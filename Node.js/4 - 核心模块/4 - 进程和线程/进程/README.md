## ģ�����

process��node��ȫ��ģ�飬���ñȽ�ֱ�ۡ�����ͨ���������node������ص���Ϣ����������node����ʱ�������в������������ý��������Ϣ���������û���������

## ����������process.env

ʹ��Ƶ�ʺܸߣ�node��������ʱ��ʱ�����жϵ�ǰ�������еĻ�����������ʾ

```js
if(process.env.NODE_ENV === 'production'){
    console.log('��������');
}else{
    console.log('����������');
}
```

�������� `NODE_ENV=production node env.js`���������

```bash
����������
```

## �첽��process.nextTick(fn)

ʹ��Ƶ��ͬ���ܸߣ�ͨ�������첽�ĳ����������򵥵����ӣ�

```js
console.log('������');
process.nextTick(function(){
    console.log('��Ӱ����');
});
console.log('����');

// �������
// ������
// ����
// ��Ӱ����
```

process.nextTick(fn) զ���� setTimeout(fn, 0) ���񣬵�ʵ����ʵ�ּ������ϵĲ��죬�����ȼ�ס�����㣺

* process.nextTick(fn) �� fn �ŵ� node �¼�ѭ���� ��һ��tick �
* process.nextTick(fn) �� setTimetout(fn, 0) ���ܸߣ�

���ﲻ�����������ۣ�����Ȥ�Ŀ��Ե��[����](https://cnodejs.org/topic/4f16442ccae1f4aa2700109b)�����˽⡣

## ��ȡ�����в�����process.argv

process.argv ����һ�����飬����Ԫ�طֱ����£�

* Ԫ��1��node
* Ԫ��2����ִ���ļ��ľ���·��
* Ԫ��x�����������������

```js
// print process.argv
process.argv.forEach(function(val, index, array) {
  console.log('����' + index + ': ' + val);
});
```

�������� `NODE_ENV=dev node argv.js --env production`��������¡�������������������

```bash
����0: /Users/a/.nvm/versions/node/v6.1.0/bin/node
����1: /Users/a/Documents/git-code/nodejs-learning-guide/examples/2016.11.22-node-process/argv.js
����2: --env
����3: production
```

## ��ȡnode specific������process.execArgv

�� process.argv �����񣬵�����ܴ����᷵�� node specific �Ĳ�����Ҳ��������node�������еĲ����������� --harmony�����ⲿ�ֲ������������ process.argv �

�������������ӣ��൱ֱ�ۡ��������� `node --harmony execArgv.js --nick chyingp`�� execArgv.js �������£�

```js
process.execArgv.forEach(function(val, index, array) {
  console.log(index + ': ' + val);
});
// �����
// 0: --harmony

process.argv.forEach(function(val, index, array) {
  console.log(index + ': ' + val);
});
// �����
// 0: /Users/a/.nvm/versions/node/v6.1.0/bin/node
// 1: /Users/a/Documents/git-code/nodejs-learning-guide/examples/2016.11.22-node-process/execArgv.js
// 2: --nick
// 3: chyingp
```

## ��ǰ����·����process.cwd() vs process.chdir(directory)

* process.cwd()�����ص�ǰ����·��
* process.chdir(directory)���л���ǰ����·��

����·������;���ù�������ˣ�ֱ���ϴ���

```js
console.log('Starting directory: ' + process.cwd());
try {
  process.chdir('/tmp');
  console.log('New directory: ' + process.cwd());
}
catch (err) {
  console.log('chdir: ' + err);
}
```

������£�

```bash
Starting directory: /Users/a/Documents/git-code/nodejs-learning-guide/examples/2016.11.22-node-process
New directory: /private/tmp
```

## IPC���

* process.connected�������ǰ�������ӽ��̣����븸����֮��ͨ��IPCͨ�������ţ���Ϊtrue��
* process.disconnect()���Ͽ��븸����֮���IPCͨ������ʱ�Ὣ process.connected ��Ϊfalse��

������ connected.js��ͨ�� fork �����ӽ��̣����ӽ���֮�䴴����IPCͨ����

```js
var child_process = require('child_process');

child_process.fork('./connectedChild.js', {
  stdio: 'inherit'
});
```

Ȼ���� connectedChild.js ���档

```js
console.log( 'process.connected: ' + process.connected );
process.disconnect();
console.log( 'process.connected: ' + process.connected );

// �����
// process.connected: true
// process.connected: false
```

## ����

process.config����node�ı������ò����й�


## ��׼����/��׼���/��׼���������process.stdin��process.stdout

process.stdin��process.stdout��process.stderr �ֱ������̵ı�׼���롢��׼�������׼���������������������

```js
process.stdin.setEncoding('utf8');

process.stdin.on('readable', () => {
  var chunk = process.stdin.read();
  if (chunk !== null) {
    process.stdout.write(`data: ${chunk}`);
  }
});

process.stdin.on('end', () => {
  process.stdout.write('end');
});
```

ִ�г��򣬿��Կ���������ͨ�� process.stdin ��ȡ�û������ͬʱ��ͨ�� process.stdout ���������������̨

```bash
hello
data: hello
world
data: world
```

process.stderrҲ��࣬���߿����Լ����¡�

## �û���/�û� ���

process.seteuid(id)��
process.geteuid()����õ�ǰ�û���id����POSIXƽ̨�ϲ���Ч��

process.getgid(id)
process.getgid()����õ�ǰȺ���id����POSIXƽ̨�ϲ���Ч��Ⱥ�顢��ЧȺ�� �����������йȸ裩

process.setegid(id)
process.getegid()����õ�ǰ��ЧȺ���id����POSIXƽ̨�ϲ���Ч��

process.setroups(groups)��
process.getgroups()����ø���Ⱥ���id����POSIXƽ̨�ϲ���Ч��

process.setgroups(groups)��
process.setgroups(groups)��

process.initgroups(user, extra_group)��

## ��ǰ������Ϣ

* process.pid�����ؽ���id��
* process.title�������������޸Ľ��̵����֣�������`ps`���ͬʱ�ж��node�������ܵ�ʱ�����þͳ����ˡ�

## �������/��Դռ�����

* process.uptime()����ǰnode�����Ѿ������˶೤ʱ�䣨��λ���룩��
* process.memoryUsage()�����ؽ���ռ�õ��ڴ棬��λΪ�ֽڡ�������ݴ������£�

```js
{ 
    rss: 19181568, 
    heapTotal: 8384512, // V8ռ�õ�����
    heapUsed: 4218408 // V8ʵ��ʹ���˵��ڴ�
}
```

* process.cpuUsage([previousValue])��CPUʹ��ʱ���ʱ����λΪ���롣user��ʾ�û������������ռ�õ�ʱ�䣬system��ʾϵͳռ��ʱ�䡣�����ǰ����ռ�ö���ں���ִ��������ô��ֵ���ʵ�ʸ�֪��Ҫ�󡣹ٷ��������£�

```js
const startUsage = process.cpuUsage();
// { user: 38579, system: 6986 }

// spin the CPU for 500 milliseconds
const now = Date.now();
while (Date.now() - now < 500);

console.log(process.cpuUsage(startUsage));
// { user: 514883, system: 11226 }
```

* process.hrtime()��һ�����������ܻ�׼���ԡ�����һ�����飬�������ֵΪ [[seconds, nanoseconds] ��1���10�ľŴη���΢�룩��
ע�⣬���ﷵ�ص�ֵ��������ڹ�ȥһ�������ʱ�䣬���Ա���ûʲô���塣�����㽫��һ�ε��÷��ص�ֵ��Ϊ�������룬����ʵ�����塣

�ѹ��������������޸ģ�

```js
var time = process.hrtime();

setInterval(() => {
  var diff = process.hrtime(time);

  console.log(`Benchmark took ${diff[0] * 1e9 + diff[1]} nanoseconds`);
}, 1000);
```

���������£�

```bash
Benchmark took 1006117293 nanoseconds
Benchmark took 2049182207 nanoseconds
Benchmark took 3052562935 nanoseconds
Benchmark took 4053410161 nanoseconds
Benchmark took 5056050224 nanoseconds
```

## node��ִ�г��������Ϣ

1. process.version�����ص�ǰnode�İ汾������'v6.1.0'��
2. process.versions������node�İ汾���Լ�������İ汾��������ʾ��

```js
{ http_parser: '2.7.0',
  node: '6.1.0',
  v8: '5.0.71.35',
  uv: '1.9.0',
  zlib: '1.2.8',
  ares: '1.10.1-DEV',
  icu: '56.1',
  modules: '48',
  openssl: '1.0.2h' }
```

3. process.release�����ص�ǰnode���а汾�������Ϣ���󲿷�ʱ�򲻻��õ��������ֶκ�����Կ�[����](https://nodejs.org/api/process.html#process_process_release)��

```js
{
  name: 'node',
  lts: 'Argon',
  sourceUrl: 'https://nodejs.org/download/release/v4.4.5/node-v4.4.5.tar.gz',
  headersUrl: 'https://nodejs.org/download/release/v4.4.5/node-v4.4.5-headers.tar.gz',
  libUrl: 'https://nodejs.org/download/release/v4.4.5/win-x64/node.lib'
}
```

4. process.config�����ص�ǰ node�汾 ����ʱ�Ĳ�����ͬ�����ٻ��õ���һ�����������⡣
5. process.execPath��node��ִ�г���ľ���·�������� '/usr/local/bin/node'

## �����������ڻ���

* process.arch�����ص�ǰϵͳ�Ĵ������ܹ����ַ�����������'arm', 'ia32', or 'x64'��
* process.platform�����ع���ƽ̨�������ַ��������� darwin��win32 �ȡ�

## ������Ϣ:process.emitWarning(warning);

v6.0.0�����Ľӿڣ����������׳�������Ϣ����򵥵��������£�ֻ�о�����Ϣ

```js
process.emitWarning('Something happened!');
// (node:50215) Warning: Something happened!
```

���Ը�������Ϣ�Ӹ����֣����ڷ���

```js
process.emitWarning('Something Happened!', 'CustomWarning');
// (node:50252) CustomWarning: Something Happened!
```

���Զ�����м���

```js
process.emitWarning('Something Happened!', 'CustomWarning');

process.on('warning', (warning) => {
  console.warn(warning.name);
  console.warn(warning.message);
  console.warn(warning.stack);
});

/*
(node:50314) CustomWarning: Something Happened!
CustomWarning
Something Happened!
CustomWarning: Something Happened!
    at Object.<anonymous> (/Users/a/Documents/git-code/nodejs-learning-guide/examples/2016.11.22-node-process/emitWarning.js:3:9)
    at Module._compile (module.js:541:32)
    at Object.Module._extensions..js (module.js:550:10)
    at Module.load (module.js:456:32)
    at tryModuleLoad (module.js:415:12)
    at Function.Module._load (module.js:407:3)
    at Function.Module.runMain (module.js:575:10)
    at startup (node.js:160:18)
    at node.js:445:3
*/    
```

Ҳ����ֱ�Ӹ���Error����

```js
const myWarning = new Error('Warning! Something happened!');
myWarning.name = 'CustomWarning';

process.emitWarning(myWarning);
```

## ����̷����źţ�process.kill(pid, signal)

process.kill() ������������ܻ��ó�ѧ�߸е�������ʵ������������ɱ�����̵ģ�������������̷����źš��ٸ����ӣ�

```js
console.log('hello');

process.kill(process.pid, 'SIGHUP');

console.log('world');
```

������£����Կ��������һ�д��벢û��ִ�У���Ϊ��ǰ���̷��� SIGHUP �źţ������˳����¡�

```bash
hello
[1]    50856 hangup     node kill.js
```

����ͨ������ SIGHUP �¼�������ֹ����Ĭ����Ϊ��

```js
process.on('SIGHUP', () => {
  console.log('Got SIGHUP signal.');
});

console.log('hello');

process.kill(process.pid, 'SIGHUP');

console.log('world');
```

���Խ���Ƚ����⣬������£���osx 10.11.4����SIGHUP �¼��ص�������ݲ�û�������

```bash
hello
world
```

�²�����Ϊд��׼������Ƶ���һ���¼�ѭ�����£�����process.exit()С���ᵽ�ģ���������

```js
process.on('SIGHUP', () => {
  console.log('Got SIGHUP signal.');
});

setTimeout(function(){
  console.log('Exiting.');
}, 0);

console.log('hello');

process.kill(process.pid, 'SIGHUP');

console.log('world');
```

������£���ʵ������˵��ʲô������֪���������������֡�������

```bash
hello
world
Exiting.
Got SIGHUP signal.
```

## ��ֹ���̣�process.exit([exitCode])��process.exitCode

1. process.exit([exitCode]) �������������˳����̡���ʹ��ǰ�в���ûִ���꣬���� process.exit() �Ĵ����߼�������δ��ɵ��첽�߼���
2. д���ݵ� process.stdout ֮���������� process.exit() �ǲ����յģ���Ϊ��node���棬�� stdout д�����Ƿ������ģ����Կ�Խ����¼�ѭ�������ǣ�����д��һ��͹��ˡ��Ƚϱ��յ������ǣ�ͨ��process.exitCode�����˳��룬Ȼ��Ƚ����Զ��˳���
3. �����������쳣�������˳����ɣ���ô�������׳�һ��δ�������error������ֹ���̣������ process.exit() ��ȫ��

���ι�����������¥��

```js
// How to properly set the exit code while letting
// the process exit gracefully.
if (someConditionNotMet()) {
  printUsageToStdout();
  process.exitCode = 1;
}
```

��ע������ process.exit() �Ľӿ�˵�������ڸ������� process.exit() ����ӿ��ж಻�ɿ������������𡣡���

## �¼�

* beforeExit�������˳�֮ǰ����������Ϊ exitCode������ʱeventLoop�Ѿ����ˣ��������ʽ���� process.exit()�˳�������δ������쳣�����˳�����ô beforeExit ���ᴥ��������Ҫ�����¼��к��á�������
* exit��

## TODO ����һ����֤

1. �ٷ��ĵ������ process.nextTick(fn) ��������������ι����������в��ԣ�

>It runs before any additional I/O events (including timers) fire in subsequent ticks of the event loop.

2. process.channel��ʵ�ʲ��Խ������ʹ�����ӽ��̼����IPCͨ����process.channel ��ֵ������undefined.�����Է��������⣿��

## �������

[Understanding process.nextTick()](https://howtonode.org/understanding-process-next-tick)

[nodejs �첽֮ Timer &Tick; ƪ](https://cnodejs.org/topic/4f16442ccae1f4aa2700109b)
