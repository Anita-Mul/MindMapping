## async_hooks
## Node 服务器请求上下文
 - node server 处理 web 请求，是基于异步 IO 模式，一个线程可以并发处理 N 个请求 ​

 - 问：为什么能同时处理 N 多个请求 ？ 答：因为有异步任务的时候，主线程就可以空闲下来接受新的任务（请求）

 - 问：那这些请求处理起来是串行还是并行 ？ 答：并行（除非处理过程中没有任何异步操作，这种情况就不适合用 node 做服务器了）

 - 问：一个线程内同时处理 N 个请求，多个请求之间上下文是频繁切换的，那如何维护上下文呢 ？ 答：这个问题就是本次要讨论的话题 ​

## 方案
 - 用全局对象缓存起来
    因为并不是多线程，全局数据会被覆盖
 - 方法之间层层传递
    ```js
    const http = require('http');
    const doSomething = require('doSomething');

    http.createServer(async function (req, res) {

    res.writeHead(200, {'Content-Type': 'text/plain'});

    await doSomething(req, res);  //将 req 、res 传过去，一杆子到底

    res.end();

    }).listen(8080);
    ```
 - async_hooks
    > async_hooks 提供监控所有异步任务的能力，当异步任务被创建、执行、销毁时会触发相应的钩子函数
    > 钩子函数的参数中有一个“执行层 ID”
    > 同步任务中遇到异步任务会开启新的执行层 （scope）

## executionAsyncId 和 triggerAsyncId
 - executionAsyncId() 函数标志当前执行上下文的异步资源 Id【当前正在执行的asyncId】
    说到async_hooks，就不得不先说说asyncId，首先asyncId是一个自增的不重复的正整数，程序的第一个asyncId必然是1（由于是Experimental API，不排除后面会有更改），任意一个async scope都会共享一个asyncId，什么叫一个异步上下文呢，通俗点来说就是一个不能中断的同步任务，只要是不能中断的，无论多长的代码都共用一个asyncId，但如果中间是可以中断的，比如是回调，比如中间有await，都会创建一个新的异步上下文，也会有一个新的asyncId
 - triggerAsyncId() 函数来标志当前执行上下文被触发的异步资源 Id，也就是当前异步资源是由哪个异步资源创建的
 - 每个异步资源都会生成 asyncId，该 id 会呈递增的方式生成，且在 Node.js 当前实例里全局唯一
    > Global asyncId: 1, Global triggerAsyncId: 0
    > fs.open asyncId: 5, fs.open triggerAsyncId: 1

## 默认未开启 Promise 执行跟踪
 - 默认情况下，由于 V8 提供的 promise introspection API 相对消耗性能，Promise 的执行没有分配 asyncId。这意味着默认情况下，使用了 Promise 或 Async/Await 的程序将不能正确的执行和触发 Promise 回调上下文的 ID。 即得不到当前异步资源 asyncId 也得不到当前异步资源是由哪个异步资源创建的 triggerAsyncId，如下所示：
    ```js
    Promise.resolve().then(() => {
    // Promise asyncId: 0. Promise triggerAsyncId: 0
    console.log(`Promise asyncId: ${asyncId()}. Promise triggerAsyncId: ${triggerAsyncId()}`);
    })
    ```
 - 通过 asyncHooks.createHook 创建一个 hooks 对象启用 Promise 异步跟踪。
    ```js
    const hooks = asyncHooks.createHook({});
    hooks.enable();

    Promise.resolve().then(() => {
    // Promise asyncId: 7. Promise triggerAsyncId: 6
    console.log(`Promise asyncId: ${asyncId()}. Promise triggerAsyncId: ${triggerAsyncId()}`);
    })
    ```
## 异步资源的声明周期
 - asyncHooks 的 createHook() 方法返回一个用于启用（enable）和禁用（disable）hooks 的实例，该方法接收 init/before/after/destory 四个回调来标志一个异步资源从初始化、回调调用之前、回调调用之后、销毁整个生命周期过程
 - init
    当构造一个可能发出异步事件的类时调用
    `async`：异步资源唯一 id
    `type`：异步资源类型
    `triggerAsyncId`：当前异步资源由哪个异步资源创建的异步资源 id
    `resource`：初始化的异步资源
    ```js
    init(asyncId: number, type: string, triggerAsyncId: number, resource: object)
    ```
 - promiseResolve
    当传递给 `Promise` 构造函数的 `resolve()` 函数执行时触发 `promiseResolve` 回调
    > 以下代码会触发两次 promiseResolve() 回调，第一次是我们直接调用的 resolve() 函数，第二次是在 .then() 里虽然我们没有显示的调用，但是它也会返回一个 Promise 所以还会被再次调用
    ```js
    const hooks = asyncHooks.createHook({
    promiseResolve(asyncId) {
        syncLog('promiseResolve: ', asyncId);
    }
    });
    new Promise((resolve) => resolve(true)).then((a) => {});

    // 输出结果
    promiseResolve:  2
    promiseResolve:  3
    ```
## 异步间共享上下文
 - asyncLocalStorage.run() 函数第一个参数是存储我们在异步调用中所需要访问的共享数据，第二个参数是一个异步函数，我们在 setTimeout() 的回调函数里又调用了 test2 函数，这一系列的异步操作都不影响我们在需要的地方去获取 asyncLocalStorage.run() 函数中存储的共享数据
    ```js
    const { AsyncLocalStorage } = require('async_hooks');
    const asyncLocalStorage = new AsyncLocalStorage();
    asyncLocalStorage.run({ traceId: 1 }, test1);
    async function test1() {
    setTimeout(() => test2(), 2000);
    }
    async function test2() {
    console.log(asyncLocalStorage.getStore().traceId);
    }
    ```
 - AsyncLocalStorage 用途很多，例如在服务端必不可少的日志分析，一个 HTTP 从请求到响应整个系统交互的日志输出如果能通过一个 traceId 来关联，在分析日志时也就能够清晰的看到整个调用链路
 - 下面是一个 HTTP 请求的简单示例，模拟了异步处理，并且在日志输出时去追踪存储的 id
    ```js
    import { createServer } from 'http';
    import { AsyncLocalStorage } from 'async_hooks'
    const asyncLocalStorage = new AsyncLocalStorage();

    function logWithId(msg) {
        const id = asyncLocalStorage.getStore();
        console.log(`${id !== undefined ? id : '-'}:`, msg);
    }

    let idSeq = 0;
    createServer((req, res) => {
    asyncLocalStorage.run(idSeq++, () => {
        logWithId('start');
        setImmediate(() => {
        logWithId('processing...');
        setTimeout(() => {
            logWithId('finish');
            res.end();
        }, 2000)
        });
    });
    }).listen(8080);
    ```
## 异步本地存储
 - 异步本地存储类似于多线程编程语言中的线程本地存储，例如 Java 中的 ThreadLocal 类，可以为使用相同变量的不同线程创建一个各自的副本，避免共享资源产生的冲突，在一个线程请求之内通过 get()/set() 方法获取或设置这个变量在当前线程中对应的副本值，在多线程并发访问时线程之间各自创建的副本互不影响
 - 在 Node.js 中我们的业务通常都工作在主线程（使用 work_threads 除外），是没有 ThreadLocal 类的。并且以事件驱动的方式来处理所有的 HTTP 请求，每个请求过来之后又都是异步的，异步之间还很难去追踪上下文信息，我们想做的是在这个异步事件开始，例如从接收 HTTP 请求到响应，能够有一种机可以让我们随时随地去获取在这期间的一些共享数据，也就是我们本节所提的异步本地存储技术
 - 假设你是用的 Express、Koa 这些基础框架，所有业务都是模块加载函数式调用，如果每次把请求的 traceId 手动在 Controller -> Service -> Model 之间传递，这样对业务代码的侵入太大了，日志与业务的耦合度就太高了
 - 现在有一个需求，在不更改业务代码的情况下每次日志打印都输出当前 HTTP 请求处理 Headers 中携带的 traceId 字段，如果是你会怎么做呢
    ###### 创建 AsyncLocalStorage 类
    ```js
    // AsyncLocalStorage.js
    const asyncHooks = require('async_hooks');
    const { executionAsyncId } = asyncHooks;
    class AsyncLocalStorage {
    constructor() {
        this.storeMap = new Map(); // {1}
        this.createHook(); // {2}
    }
    
    createHook() {
        const ctx = this;
        const hooks = asyncHooks.createHook({
        // 在每次的异步任务都会执行这个 async
        init(asyncId, type, triggerAsyncId) {
            if (ctx.storeMap.has(triggerAsyncId)) {
            ctx.storeMap.set(asyncId, ctx.storeMap.get(triggerAsyncId));
            }
        },
        destroy(asyncId) {
            ctx.storeMap.delete(asyncId);
        }
        });
        hooks.enable();
    }

    run(store, callback) { // {3}
        this.storeMap.set(executionAsyncId(), store);
        callback();
    }

    getStore() { // {4}
        return this.storeMap.get(executionAsyncId());
    }
    }
    module.exports = AsyncLocalStorage;
    ```
    ###### logger.js 文件
    ```js
    const { v4: uuidV4 } = require('uuid');
    const AsyncLocalStorage = require('./AsyncLocalStorage');
    const asyncLocalStorage = new AsyncLocalStorage();

    const logger = {
    info: (...args) => {
        // 获取当前上下文的信息
        const traceId = asyncLocalStorage.getStore();
        console.log(traceId, ...args);
    },
    run: (req, callback) => {
        // 在当前上下文中存储 req.headers.requestId
        // 如果不用这种方法，也可以直接在中间件中传递req，res
        asyncLocalStorage.run(req.headers.requestId || uuidV4(), callback);
    }
    }

    module.exports = {
        logger,
    }
    ```
    ###### app.js
    ```js
    const express = require('express');
    const app = express();
    const PORT = 3000;
    const { logger } = require('./logger');


    app.use((req, res, next) => logger.run(req, next));

    app.get('/logger', async (req, res, next) => {
    try {
    const users = await getUsersController();
    res.json({ code: 'SUCCESS', message: '', data: users });
    } catch (error) {
        res.json({ code: 'ERROR', message: error.message })
    }
    });

    app.listen(PORT, () => console.log(`server is listening on ${PORT}`));





    // 每次 async 都会触发 init
    async function getUsersController() {
        logger.info('Get user list at controller layer.');
        return getUsersService();
    }

    async function getUsersService() {
        logger.info('Get user list at service layer.');
        setTimeout(function() { logger.info('setTimeout 2s at service layer.') }, 3000);
        return getUsersModel();
    }

    async function getUsersModel() {
        logger.info('Get user list at model layer.');
        return [];
    }
    ```
 - 方式二：executionAsyncResource() 返回当前执行的异步资源
    ```js
    const asyncHooks = require('async_hooks');
    const { executionAsyncId, executionAsyncResource } = asyncHooks;

    class AsyncLocalStorage {
    constructor() {
        this.createHook();
    }

    createHook() {
        const hooks = asyncHooks.createHook({
            init(asyncId, type, triggerAsyncId, resource) {
                const cr = executionAsyncResource();
                if (cr) {
                    resource[asyncId] = cr[triggerAsyncId];
                }
            }
        });

        hooks.enable();
    }
    
    run(store, callback) {
        executionAsyncResource()[executionAsyncId()] = store;
        callback();
    }
    getStore() {
        return executionAsyncResource()[executionAsyncId()];
    }
    }

    module.exports = AsyncLocalStorage;
    ```
 - 基于 ResourceAsync 创建 AsyncLocalStorage 类
    ResourceAysnc 可以用来自定义异步资源
    ```js
    const asyncHooks = require('async_hooks');
    const { executionAsyncResource, AsyncResource } = asyncHooks;

    class AsyncLocalStorage {
    constructor() {
        this.kResourceStore = Symbol('kResourceStore');
        this.enabled = false;
        const ctx = this;

        this.hooks = asyncHooks.createHook({
        init(asyncId, type, triggerAsyncId, resource) {
            const currentResource = executionAsyncResource();
            ctx._propagate(resource, currentResource)
        }
        });
    }

    // Propagate the context from a parent resource to a child one
    _propagate(resource, triggerResource) {
        const store = triggerResource[this.kResourceStore];
        if (store) {
        resource[this.kResourceStore] = store;
        }
    }

    _enable() {
        if (!this.enabled) {
        this.enabled = true;
        this.hooks.enable();
        }
    }

    enterWith(store) {
        this._enable();
        const resource = executionAsyncResource();
        resource[this.kResourceStore] = store;
    }

    run(store, callback) {
        const resource = new AsyncResource('AsyncLocalStorage', {
        requireManualDestroy: true,
        });

        /**
        * 每一次的调用都会创建一个资源，调用其 runInAsyncScope() 方法，
        * 这样在这个资源的异步作用域下，所执行的代码（传入的 callback）
        * 都是可追踪我们设置的 store
        */
        return resource.emitDestroy().runInAsyncScope(() => {
        this.enterWith(store);
        return callback();
        });
    }

    getStore() {
        return executionAsyncResource()[this.kResourceStore];
    }
    }

    module.exports = AsyncLocalStorage;
    ```


[  参考文章](https://zhuanlan.zhihu.com/p/347563211)