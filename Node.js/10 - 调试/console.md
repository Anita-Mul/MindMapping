## ģ�����

consoleģ���ṩ�˻����ĵ��Թ��ܡ�ʹ�úܼ򵥣����õ�API��Ҫ�� console.log()��console.error()��

���⣬���Ի���Console�࣬�������չ���Լ���consoleʵ��������ѵ�����Ϣ��ӡ���ļ������������ڿ���̨�ϡ�

ֱ�ӿ����ӡ�

## ��������

������˵������־����Ĭ�ϴ�ӡ������̨����õ���console.log()��console.error()����������

* console.log(msg)����ͨ��־��ӡ��
* console.error(msg)��������־��ӡ��
* console.info(msg)����ͬ��console.log(msg)
* console.warn(msg)����ͬ��console.error(msg)

�������£�

```js
console.log('log: hello');
console.log('log: hello', 'chyingp');
console.log('log: hello %s', 'chyingp');

console.error('error: hello');
console.error('error: hello', 'chyingp');
console.error('error: hello %s', 'chyingp');

// ������£�
// log: hello
// log: hello chyingp
// log: hello chyingp
// error: hello
// error: hello chyingp
// error: hello chyingp
```

## �Զ���stdout

����ͨ�� new console.Console(stdout, stderr) �������Զ����consoleʵ����������ܺ�ʵ�á�

�������뽫������Ϣ��ӡ�������ļ�����ô���Ϳ���ͨ�����´���ʵ�֡�

```js
var fs = require('fs');
var file = fs.createWriteStream('./stdout.txt');

var logger = new console.Console(file, file);

logger.log('hello');
logger.log('word');

// ��ע����������� stdout.txt������Ǵ�ӡ������̨
```

## ��ʱ

ͨ��`console.time(label)`��`console.timeEnd(label)`������ӡ������ʱ���֮���ʱ����λ�Ǻ��룬�������¡�

```js
var timeLabel = 'hello'

console.time(timeLabel);

setTimeout(console.timeEnd, 1000, timeLabel);
// ������룺
// hello: 1005.505ms
```

## ����

ͨ�� console.assert(value, message) ���ж��ԡ����value��Ϊtrue����ô�׳�`AssertionError`�쳣�����жϳ���ִ�С�

���´�����ʾ���ڶ������Ա�������ִֹͣ�С�

```js
console.assert(true, '1��right');
console.assert(false, '2��right', '2��wrong');

// ������£�
// assert.js:90
//   throw new assert.AssertionError({
//     ^
//     AssertionError: 2��right 2��wrong
//         at Console.assert (console.js:95:23)
```

Ϊ��������쳣�˳�����Ҫ��������쳣���д������磺

```js
try{
    console.assert(false, 'error occurred');
}catch(e){
    console.log(e.message);
}

// ������£�
// error occurred
```

## ��ӡ�����ջ��console.trace(msg)

��msg��ӡ����׼����������������ǰ�����λ�úͶ�ջ��Ϣ��

```js
console.trace('trace is called');

// ������£�
// Trace: trace is called
//     at Object.<anonymous> (/Users/a/Documents/git-code/nodejs-learning-guide/examples/2016.12.01-console/trace.js:1:71)
//     at Module._compile (module.js:541:32)
//     at Object.Module._extensions..js (module.js:550:10)
//     at Module.load (module.js:456:32)
//     at tryModuleLoad (module.js:415:12)
//     at Function.Module._load (module.js:407:3)
//     at Function.Module.runMain (module.js:575:10)
//     at startup (node.js:160:18)
//     at node.js:445:3
```

## ����ӡ

���ٹ�ע console.dir(obj)����Ϊ�󲿷�ʱ����ָ� console.log(obj) ��࣬������

```js
var obj = {
    nick: 'chyingp'
};

console.log(obj);  // �����{ nick: 'chyingp' }
console.dir(obj);  // �����{ nick: 'chyingp' }
```

����obj�Ĳ㼶�Ƚ���ʱ���ô��ͳ����ˡ�����ͨ��`depth`�Զ����ӡ�Ĳ㼶����Ĭ����2������ڵ��Ժ��а�����

```js
var obj2 = {
    human: {
        man: {
            info: {
                nick: 'chyingp'
            }
        }
    }
};

console.log(obj2);  // �����{ human: { man: { info: [Object] } } }
console.dir(obj2);  // �����{ human: { man: { info: [Object] } } }

console.dir(obj2, {depth: 3});  // �����{ human: { man: { info: { nick: 'chyingp' } } } }
```

## �������

�ٷ��ĵ���https://nodejs.org/api/console.html
