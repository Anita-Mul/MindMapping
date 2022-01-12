## ģ�����

��node�У�child_process���ģ��ǳ���Ҫ������������������node�����翪����һ���µĴ��š�

�ٸ��򵥵����ӣ�

```javascript
const spawn = require('child_process').spawn;
const ls = spawn('ls', ['-lh', '/usr']);

ls.stdout.on('data', (data) => {
  console.log(`stdout: ${data}`);
});

ls.stderr.on('data', (data) => {
  console.log(`stderr: ${data}`);
});

ls.on('close', (code) => {
  console.log(`child process exited with code ${code}`);
});
```

## ���ִ����ӽ��̵ķ�ʽ

ע�����

* �����г����Ķ����첽�����ӽ��̵ķ�ʽ��ÿһ�ַ�ʽ���ж�Ӧ��ͬ���汾��
* `.exec()`��`.execFile()`��`.fork()`�ײ㶼��ͨ��`.spawn()`ʵ�ֵġ�
* `.exec()`��`execFile()`�����ṩ�˻ص������ӽ���ֹͣ��ʱ��ִ�С�

>child_process.spawn(command[, args][, options])
>child_process.exec(command[, options][, callback])
>child_process.execFile(file[, args][, options][, callback])
>child_process.fork(modulePath[, args][, options])

### child_process.exec(command[, options][, callback])

����һ��shell��Ȼ����shell��ִ�����ִ����ɺ󣬽�stdout��stderr��Ϊ��������ص�������

>spawns a shell and runs a command within that shell, passing the stdout and stderr to a callback function when complete.

�������£�

1. ִ�гɹ���`error`Ϊ`null`��ִ��ʧ�ܣ�`error`Ϊ`Error`ʵ����`error.code`Ϊ�����룬
2. `stdout`��`stderr`Ϊ��׼�������׼����Ĭ�����ַ���������`options.encoding`Ϊ`buffer`

```javascript
var exec = require('child_process').exec;

// �ɹ�������
exec('ls -al', function(error, stdout, stderr){
    if(error) {
        console.error('error: ' + error);
        return;
    }
    console.log('stdout: ' + stdout);
    console.log('stderr: ' + typeof stderr);
});

// ʧ�ܵ�����
exec('ls hello.txt', function(error, stdout, stderr){
    if(error) {
        console.error('error: ' + error);
        return;
    }
    console.log('stdout: ' + stdout);
    console.log('stderr: ' + stderr);
});
```

#### ����˵����

* `cwd`����ǰ����·����
* `env`������������
* `encoding`�����룬Ĭ����`utf8`��
* `shell`������ִ�������shell��unix��Ĭ����`/bin/sh`��windows��Ĭ����`cmd.exe`��
* `timeout`��Ĭ����0��
* `killSignal`��Ĭ����`SIGTERM`��
* `uid`��ִ�н��̵�uid��
* `gid`��ִ�н��̵�gid��
* `maxBuffer`��<Number> ��׼������������������������������λΪ�ֽڣ�����������Ļ����ӽ��̾ͻᱻɱ����Ĭ����200*1024������200k����

��ע��

1. ���`timeout`����0����ô�����ӽ������г���`timeout`���룬��ô���ͻ�����̷���`killSignal`ָ�����źţ�����`SIGTERM`����
2. �������û�г�����ô`error`Ϊ`null`��������г�����ô��`error.code`�����˳����루exist code����`error.signal`�ᱻ���ó���ֹ���̵��źš�������`CTRL+C`ʱ���͵�`SIGINT`��

#### ������

��������������û�����ģ��п��ܲ�������sqlע��ķ��գ�����

```
exec('ls hello.txt; rm -rf *', function(error, stdout, stderr){
    if(error) {
        console.error('error: ' + error);
        // return;
    }
    console.log('stdout: ' + stdout);
    console.log('stderr: ' + stderr);
});
```

#### ��ע����

Note: Unlike the exec(3) POSIX system call, child_process.exec() does not replace the existing process and uses a shell to execute the command.

### child_process.execFile(file[, args][, options][, callback])

��`.exec()`���ƣ���ͬ�����ڣ�û�д���һ���µ�shell������������Ӱ��

1. ��`child_process.exec()`Ч�ʸ�һЩ����ʵ�ʴ����ԣ�
2. һЩ����������I/O�ض����ļ�glob�Ȳ�֧�֡�

>similar to child_process.exec() except that it spawns the command directly without first spawning a shell.

`file`��<String> ��ִ���ļ������֣�����·����

���ӣ�

```javascript
var child_process = require('child_process');

child_process.execFile('node', ['--version'], function(error, stdout, stderr){
    if(error){
        throw error;
    }
    console.log(stdout);
});

child_process.execFile('/Users/a/.nvm/versions/node/v6.1.0/bin/node', ['--version'], function(error, stdout, stderr){
    if(error){
        throw error;
    }
    console.log(stdout);
});
```

====== ��չ�Ķ� =======

��nodeԴ��������`exec()`��`execFile()`���Ĳ�𣬾������Ƿ񴴽���shell����execFile()�ڲ���options.shell === false������ô�������ֶ�����shell�����´������ǵȼ۵ġ�win�µ�shell����������ͬ������Ȥ��ͬѧ�����Լ������¡�

��ע��execFile()�ڲ����ջ���ͨ��spawn()ʵ�ֵģ� ���û������ {shell: '/bin/bash'}����ô spawm() �ڲ�������Ľ�����������ͬ��execFile('ls -al .') ��ֱ�ӱ���

```javascript
var child_process = require('child_process');
var execFile = child_process.execFile;
var exec = child_process.exec;

exec('ls -al .', function(error, stdout, stderr){
    if(error){
        throw error;
    }
    console.log(stdout);
});

execFile('ls -al .', {shell: '/bin/bash'}, function(error, stdout, stderr){
    if(error){
        throw error;
    }
    console.log(stdout);
});
```


### child_process.fork(modulePath[, args][, options])

`modulePath`���ӽ������е�ģ�顣

����˵�������ظ��Ĳ���˵���Ͳ��������о٣�

* `execPath`��<String> ���������ӽ��̵Ŀ�ִ���ļ���Ĭ����`/usr/local/bin/node`��Ҳ����˵�����ͨ��`execPath`��ָ�������node��ִ���ļ�·������������node�汾��
* `execArgv`��<Array> ������ִ���ļ����ַ��������б�Ĭ����`process.execArgv`���������̱���һ�¡�
* `silent`��<Boolean> Ĭ����`false`�����ӽ��̵�`stdio`�Ӹ����̼̳С������`true`����ֱ��`pipe`���ӽ��̵�`child.stdin`��`child.stdout`�ȡ�
* `stdio`��<Array> ���������`stdio`����Ḳ��`silent`ѡ������á�


����1��silent

**parent.js**

```javascript
var child_process = require('child_process');

// ����һ�����ӡ�� output from the child
// Ĭ�������silent Ϊ false���ӽ��̵� stdout ��
// �Ӹ����̼̳�
child_process.fork('./child.js', {
    silent: false
});

// ���Ӷ��������ӡ�� output from the silent child
// silent Ϊ true���ӽ��̵� stdout ��
// pipe �򸸽���
child_process.fork('./silentChild.js', {
    silent: true
});

// ����������ӡ�� output from another silent child
var child = child_process.fork('./anotherSilentChild.js', {
    silent: true
});

child.stdout.setEncoding('utf8');
child.stdout.on('data', function(data){
    console.log(data);
});
```

**child.js**

```javascript
console.log('output from the child');
```

**silentChild.js**

```javascript
console.log('output from the silent child');
```

**anotherSilentChild.js**

```javascript
console.log('output from another silent child');
```

���Ӷ���ipc

parent.js

```javascript
var child_process = require('child_process');

var child = child_process.fork('./child.js');

child.on('message', function(m){
    console.log('message from child: ' + JSON.stringify(m));
});

child.send({from: 'parent'});
```
child.js
```javascript
process.on('message', function(m){
    console.log('message from parent: ' + JSON.stringify(m));
});

process.send({from: 'child'});
```

���н��

```powershell
?  ipc git:(master) ? node parent.js
message from child: {"from":"child"}
message from parent: {"from":"parent"}
```

��������execArgv

���ȣ�process.execArgv�Ķ��壬�ο�[����](https://nodejs.org/api/process.html#process_process_execargv)������`execArgv`��Ŀ��һ�����ڣ����ӽ��̸������̱�����ͬ��ִ�л�����

���磬������ָ����`--harmony`������ӽ���û��ָ������ô��Ҫ���ˡ�

parent.js

```javascript
var child_process = require('child_process');

console.log('parent execArgv: ' + process.execArgv);

child_process.fork('./child.js', {
    execArgv: process.execArgv
});
```

child.js

```javascript
console.log('child execArgv: ' + process.execArgv);
```

���н��

```powershell
?  execArgv git:(master) ? node --harmony parent.js
parent execArgv: --harmony
child execArgv: --harmony
```

����3��execPath��TODO �������ӣ�

### child_process.spawn(command[, args][, options])

`command`��Ҫִ�е�����

options����˵����

* `argv0`��[String] ����ȽϹ��죬��uninx��windows�ϱ��ֲ�һ��������Ҫ�����
* `stdio`��[Array] | [String] �ӽ��̵�stdio���ο�[����](https://nodejs.org/api/child_process.html#child_process_options_stdio)
* `detached`��[Boolean] ���ӽ��̶����ڸ�����֮�����С�ͬ���ڲ�ͬƽ̨�ϱ����в��죬����ο�[����](https://nodejs.org/api/child_process.html#child_process_options_detached)
* `shell`��[Boolean] | [String] �����`true`����shell�����г���Ĭ����`false`���������ã����� ����ͨ�� /bin/sh -c xxx ��ʵ�� .exec() ������Ч����

����1����������

```javascript
var spawn = require('child_process').spawn;
var ls = spawn('ls', ['-al']);

ls.stdout.on('data', function(data){
    console.log('data from child: ' + data);
});


ls.stderr.on('data', function(data){
    console.log('error from child: ' + data);
});

ls.on('close', function(code){
    console.log('child exists with code: ' + code);
});
```

����2������stdio

```javascript
var spawn = require('child_process').spawn;
var ls = spawn('ls', ['-al'], {
    stdio: 'inherit'
});

ls.on('close', function(code){
    console.log('child exists with code: ' + code);
});
```

����3������ʹ��shell

```javascript
var spawn = require('child_process').spawn;

// ���� echo "hello nodejs" | wc
var ls = spawn('bash', ['-c', 'echo "hello nodejs" | wc'], {
    stdio: 'inherit',
    shell: true
});

ls.on('close', function(code){
    console.log('child exists with code: ' + code);
});
```

����4���������������ֳ����������ֳ����в�ͬ�Ĵ���ʽ��

* ����1����������ڣ������ӽ��̱���
* ����2��������ڣ������й��̱���

```javascript
var spawn = require('child_process').spawn;
var child = spawn('bad_command');

child.on('error', (err) => {
  console.log('Failed to start child process 1.');
});

var child2 = spawn('ls', ['nonexistFile']);

child2.stderr.on('data', function(data){
    console.log('Error msg from process 2: ' + data);
});

child2.on('error', (err) => {
  console.log('Failed to start child process 2.');
});
```

���н�����¡�

```powershell
?  spawn git:(master) ? node error/error.js
Failed to start child process 1.
Error msg from process 2: ls: nonexistFile: No such file or directory
```

����5��echo "hello nodejs" | grep "nodejs"

```javascript
// echo "hello nodejs" | grep "nodejs"
var child_process = require('child_process');

var echo = child_process.spawn('echo', ['hello nodejs']);
var grep = child_process.spawn('grep', ['nodejs']);

grep.stdout.setEncoding('utf8');

echo.stdout.on('data', function(data){
    grep.stdin.write(data);
});

echo.on('close', function(code){
    if(code!==0){
        console.log('echo exists with code: ' + code);
    }
    grep.stdin.end();
});

grep.stdout.on('data', function(data){
    console.log('grep: ' + data);
});

grep.on('close', function(code){
    if(code!==0){
        console.log('grep exists with code: ' + code);
    }
});
```

���н����

```powershell
?  spawn git:(master) ? node pipe/pipe.js
grep: hello nodejs
```

## ����`options.stdio`

Ĭ��ֵ��['pipe', 'pipe', 'pipe']������ζ�ţ�

1. child.stdin��child.stdout ����`undefined`
2. ����ͨ������ `data` �¼�������ȡ���ݡ�

### ��������

```javascript
var spawn = require('child_process').spawn;
var ls = spawn('ls', ['-al']);

ls.stdout.on('data', function(data){
    console.log('data from child: ' + data);
});

ls.on('close', function(code){
    console.log('child exists with code: ' + code);
});
```

### ͨ��child.stdin.write()д��

```javascript
var spawn = require('child_process').spawn;
var grep = spawn('grep', ['nodejs']);

setTimeout(function(){
    grep.stdin.write('hello nodejs \n hello javascript');
    grep.stdin.end();
}, 2000);

grep.stdout.on('data', function(data){
    console.log('data from grep: ' + data);
});

grep.on('close', function(code){
    console.log('grep exists with code: ' + code);
});
```

## �첽 vs ͬ��

�󲿷�ʱ���ӽ��̵Ĵ������첽�ġ�Ҳ����˵��������������ǰ���¼�ѭ������������ܵ��������а�����

��Ȼ���е�ʱ��ͬ���ķ�ʽ������㣨�����¼�ѭ����������ͨ���ӽ��̵ķ�ʽ��ִ��shell�ű�ʱ��

nodeͬ���ṩͬ���İ汾�����磺

* spawnSync()
* execSync()
* execFileSync()

## ����`options.detached`

����ľ����windows�������ԣ���������ԭ��

>On Windows, setting options.detached to true makes it possible for the child process to continue running after the parent exits. The child will have its own console window. Once enabled for a child process, it cannot be disabled.

�ڷ�window��ƽ̨�ϵı���

>On non-Windows platforms, if options.detached is set to true, the child process will be made the leader of a new process group and session. Note that child processes may continue running after the parent exits regardless of whether they are detached or not. See setsid(2) for more information.

### Ĭ������������̵ȴ��ӽ��̽�����

�ӽ��̡����Կ������и���ʱ��һֱ����

```javascript
var times = 0;
setInterval(function(){
    console.log(++times);
}, 1000);
```

����������룬�ᷢ�ָ�����һֱhold�Ų��˳���

```
var child_process = require('child_process');
child_process.spawn('node', ['child.js'], {
    // stdio: 'inherit'
});
```

### ͨ��child.unref()�ø������˳�

����`child.unref()`�����ӽ��̴Ӹ����̵��¼�ѭ�����޳������Ǹ����̿��������˳��������м���Ҫ��

1. ����`child.unref()`
2. ����`detached`Ϊ`true`
3. ����`stdio`Ϊ`ignore`�������������

```javascript
var child_process = require('child_process');
var child = child_process.spawn('node', ['child.js'], {
    detached: true,
    stdio: 'ignore'  // ��ע���������Ϊ ignore����ô �����̻��ǲ����˳�
    // stdio: 'inherit'
});

child.unref();
```

### ��`stdio`�ض����ļ�

����ֱ�ӽ�stdio����Ϊ`ignore`�������Խ����ض��򵽱��ص��ļ���

```javascript
var child_process = require('child_process');
var fs = require('fs');

var out = fs.openSync('./out.log', 'a');
var err = fs.openSync('./err.log', 'a');

var child = child_process.spawn('node', ['child.js'], {
    detached: true,
    stdio: ['ignore', out, err]
});

child.unref();
```

## exec()��execFile()֮�������

���ȣ�exec() �ڲ����� execFile() ��ʵ�֣��� execFile() �ڲ����� spawn() ��ʵ�֡�

>exec() -> execFile() -> spawn()

��Σ�execFile() �ڲ�Ĭ�Ͻ� options.shell ����Ϊfalse��exec() Ĭ�ϲ���false��

## Class: ChildProcess

* ͨ��`child_process.spawn()`�ȴ�����һ�㲻ֱ���ù��캯��������
* �̳���`EventEmitters`��������`.on()`�ȷ�����

### �����¼�

### close

��stdio���ر�ʱ����������¼���`exit`��ͬ����Ϊ������̿��Թ���ͬ��stdio����   
������code���˳��룬����ӽ������Լ��˳��Ļ�����signal�������ӽ��̵��źţ�
���⣺codeһ�����е��𣿣��Ӷ�code��ע�����������ǣ�������`kill`ɱ���ӽ��̣���ô��code�ǣ�

### exit
������code��signal������ӽ������Լ��˳��ģ���ô`code`�����˳��룬����Ϊnull������ӽ�����ͨ���źŽ����ģ���ô��`signal`���ǽ������̵��źţ�����Ϊnull���������У�һ�߿϶���Ϊnull��
ע�����`exit`�¼�����ʱ���ӽ��̵�stdio stream���ܻ����š��������������⣬nodejs������SIGINT��SIGTERM�źţ�Ҳ����˵��nodejs�յ��������ź�ʱ�����������˳�����������һЩ����Ĺ�����Ȼ�������׳��������źš���Ŀ���ʱjs�������������ˣ�����ر����ݿ�ȡ�TODO ���ʣ�js�����Ƿ�Ҳ���Բ��˳�����������

SIGINT��interrupt��������ֹ�źţ�ͨ�����û�����CTRL+Cʱ����������֪ͨǰ̨������ֹ���̡�
SIGTERM��terminate����������źţ����źſ��Ա������ʹ���ͨ������Ҫ������Լ������˳���shell����killȱʡ��������źš�����ź���ֹ���ˣ����ǲŻ᳢��SIGKILL��ǿ����ֹ����

>Also, note that Node.js establishes signal handlers for SIGINT and SIGTERM and Node.js processes will not terminate immediately due to receipt of those signals. Rather, Node.js will perform a sequence of cleanup actions and then will re-raise the handled signal.

### error

��������������ʱ��error�ͻᱻ��������error����ʱ��exit���ܴ�����Ҳ���ܲ��������������Ǳ����ģ�
* �޷������ӽ��̡�
* �����޷�kill����TODO ���ӣ�
* ���ӽ��̷�����Ϣʧ�ܡ���TODO  ���ӣ�

### message

������`process.send()`��������Ϣʱ������
������`message`��Ϊjson���󣬻���primitive value��`sendHandle`��net.Socket���󣬻���net.Server����TODO ʲôʱ����ʲô���󣿣�����

**.connected**��������`.disconnected()`ʱ����Ϊfalse�������Ƿ��ܹ����ӽ��̽�����Ϣ�����߶��ӽ��̷�����Ϣ��

**.disconnect()**���رո����̡��ӽ���֮���IPCͨ�������������������ʱ��`disconnect`�¼��ͻᴥ��������ӽ�����nodeʵ����ͨ��child_process.fork()����������ô���ӽ����ڲ�Ҳ������������`process.disconnect()`����ֹIPCͨ�����ο�[process.disconnect](https://nodejs.org/api/process.html#process_process_disconnect)��
���ʣ�����fork�˸��ӽ��̣��ӽ�����������http server����ô�������̵��� `.disconnect()`��Ӱ�죿��TODO ����֤��������

## ����Ҫ�ı�����

### windowsƽ̨�ϵ�`cmd`��`bat`

>The importance of the distinction between child_process.exec() and child_process.execFile() can vary based on platform. On Unix-type operating systems (Unix, Linux, OSX) child_process.execFile() can be more efficient because it does not spawn a shell. On Windows, however, .bat and .cmd files are not executable on their own without a terminal, and therefore cannot be launched using child_process.execFile(). When running on Windows, .bat and .cmd files can be invoked using child_process.spawn() with the shell option set, with child_process.exec(), or by spawning cmd.exe and passing the .bat or .cmd file as an argument (which is what the shell option and child_process.exec() do).

```javascript
// On Windows Only ...
const spawn = require('child_process').spawn;
const bat = spawn('cmd.exe', ['/c', 'my.bat']);

bat.stdout.on('data', (data) => {
  console.log(data);
});

bat.stderr.on('data', (data) => {
  console.log(data);
});

bat.on('exit', (code) => {
  console.log(`Child exited with code ${code}`);
});

// OR...
const exec = require('child_process').exec;
exec('my.bat', (err, stdout, stderr) => {
  if (err) {
    console.error(err);
    return;
  }
  console.log(stdout);
});
```


### ���̱��� 

Note: Certain platforms (OS X, Linux) will use the value of argv[0] for the process title while others (Windows, SunOS) will use command.

Note: Node.js currently overwrites argv[0] with process.execPath on startup, so process.argv[0] in a Node.js child process will not match the argv0 parameter passed to spawn from the parent, retrieve it with the process.argv0 property instead.


### �������д��������

**p.js**

```javascript
const cp = require('child_process');
const n = cp.fork(`${__dirname}/sub.js`);

console.log('1');

n.on('message', (m) => {
  console.log('PARENT got message:', m);
});

console.log('2');

n.send({ hello: 'world' });

console.log('3');
```

**sub.js**

```javascript
console.log('4');
process.on('message', (m) => {
  console.log('CHILD got message:', m);
});

process.send({ foo: 'bar' });
console.log('5');
```

����`node p.js`����ӡ��������������

```powershell
?  ch node p.js       
1
2
3
4
5
PARENT got message: { foo: 'bar' }
CHILD got message: { hello: 'world' }
```

����������

```javascript
// p2.js
var fork = require('child_process').fork;

console.log('p: 1');

fork('./c2.js');

console.log('p: 2');

// �Ӳ��Խ��������ͬ����70ms���е�ʱ�򣬶�ʱ���ص����ӽ�����ִ�У��е�ʱ����ӽ�����ִ�С�
const t = 70;
setTimeout(function(){
    console.log('p: 3 in %s', t);
}, t);


// c2.js
console.log('c: 1');
```

### ����NODE_CHANNEL_FD

child_process.fork()ʱ�����ָ����execPath����ô�����ӽ��̼�ͨ��NODE_CHANNEL_FD ����ͨ�š�

>Node.js processes launched with a custom execPath will communicate with the parent process using the file descriptor (fd) identified using the environment variable NODE_CHANNEL_FD on the child process. The input and output on this fd is expected to be line delimited JSON objects.


## �������

�ٷ��ĵ���https://nodejs.org/api/child_process.html
