## ģ�����

eventsģ����node�ĺ���ģ��֮һ���������г��õ�nodeģ�鶼�̳���eventsģ�飬����http��fs�ȡ�

ģ�鱾��ǳ��򵥣�API��ȻҲ���٣������õľ���ô����������ټ��������ӡ�

## ��������

����һ����6�����ӣ����ǳ��򵥣�����ֱ�ӿ����������С�����5�Ƚ�����˼����ȻҲ�������ӣ���ȷʵ�����׼Ǵ�ĵ㣬����Ȥ��ͬѧ���Կ��¡�

### ����1�������¼�������

```js
var EventEmitter = require('events');

class Man extends EventEmitter {}

var man = new Man();

man.on('wakeup', function(){
    console.log('man has woken up');
});

man.emit('wakeup');
// ������£�
// man has woken up
```

### ����2��ͬ���¼�������¼�������

���Կ������¼�����ʱ���¼�����������ע���˳��ִ�С�

```js
var EventEmitter = require('events');

class Man extends EventEmitter {}

var man = new Man();

man.on('wakeup', function(){
    console.log('man has woken up');
});

man.on('wakeup', function(){
    console.log('man has woken up again');
});

man.emit('wakeup');

// ������£�
// man has woken up
// man has woken up again
```

### ����3��ֻ����һ�ε��¼�������

```js
var EventEmitter = require('events');

class Man extends EventEmitter {}

var man = new Man();

man.on('wakeup', function(){
    console.log('man has woken up');
});

man.once('wakeup', function(){
    console.log('man has woken up again');
});

man.emit('wakeup');
man.emit('wakeup');

// ������£�
// man has woken up
// man has woken up again
// man has woken up
```

### ����4��ע���¼�������ǰ���¼��ȴ���

���Կ�����ע���¼�������ǰ���¼��ȴ���������¼���ֱ�ӱ����ԡ�

```js
var EventEmitter = require('events');

class Man extends EventEmitter {}

var man = new Man();

man.emit('wakeup', 1);

man.on('wakeup', function(index){
    console.log('man has woken up ->' + index);
});

man.emit('wakeup', 2);
// ������£�
// man has woken up ->2
```

### ����5���첽ִ�У�����˳��ִ��

���Ӻܼ򵥣����ǳ���Ҫ�������Ǵ���1��ִ�У����Ǵ���2��ִ�У������죬���۶������������˵Ĵ��룬�����Լ���дnode���򣬶��ǳ��ؼ���

ʵ��֤��������1��ִ���ˡ�(node v6.1.0)

```js
var EventEmitter = require('events');

class Man extends EventEmitter {}

var man = new Man();

man.on('wakeup', function(){
    console.log('man has woken up'); // ����1
});

man.emit('wakeup');

console.log('woman has woken up');  // ����2

// ������£�
// man has woken up
// woman has woken up
```

### ����6���Ƴ��¼�������

```js
var EventEmitter = require('events');

function wakeup(){
    console.log('man has woken up');
}

class Man extends EventEmitter {}

var man = new Man();

man.on('wakeup', wakeup);
man.emit('wakeup');

man.removeListener('wakeup', wakeup);
man.emit('wakeup');

// ������£�
// man has woken up
```

## �������

https://nodejs.org/api/events.html

