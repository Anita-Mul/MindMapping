## debuglog(section)

�����õĵ��Է���������ͨ�� util.debuglog(name) ������һ������fn�����fn���ص��ǣ�ֻ�������г���ʱ��������������NODE_DEBUG=name���Ż��ӡ��������Ϣ��

���Կ���������ӣ�ֱ������ `node debuglog.js`��û���κ��������Ҫ`NODE_DEBUG=foo`���Ż��д�ӡ��Ϣ.

```js
var util = require('util');
var logger = util.debuglog('foo');

logger('hello');
```

������ʾ��ע�⣬6347 �ǵ�ǰ����id��

```bash
?  2016.12.02-util git:(master) ? NODE_DEBUG=foo node debuglog.js
FOO 6347: hello world
```

���⣬������һ��ָ�����`name`��ͨ�����ŷָ���

```js
var util = require('util');
var firstLogger = util.debuglog('first');
var secondLogger = util.debuglog('second');
var thirdLogger = util.debuglog('third');

firstLogger('hello');
secondLogger('hello');
thirdLogger('hello');
```

�������£�

```bash
FOO 6347: hello world
?  2016.12.02-util git:(master) ? NODE_DEBUG=first,second node debuglog.js
FIRST 6456: hello
SECOND 6456: hello
```

## ��������ʶΪ���ϣ�util.deprecate(fn, str)

��`fn`����һ�㣬������һ���µĺ���`fn2`������`fn2`ʱ��ͬ�����`fn`ԭ�еĹ��ܣ���ͬʱ���ӡ��������־����ʾ���������ϣ��������ʾ��Ϣ���ǵڶ�������`str`��

```js
var util = require('util');
var foo = function(){
    console.log('foo');
};

var foo2 = util.deprecate(foo, 'foo is deprecate');

foo2();

// ������£�
// foo
// (node:6608) DeprecationWarning: foo is deprecate
```

����Ӵ�����ʾ��Ϣ���ˣ�����ͨ��`--no-deprecation`�������������Բο�[����](https://nodejs.org/api/util.html#util_util_deprecate_function_string)��

```bash
?  2016.12.02-util git:(master) ? node --no-deprecation deprecate.js 
foo
```

## ��ʽ����ӡ��util.format(format[, ...args])

��ʽ����ӡ���Ӧ�ñȽ���Ϥ�ˣ�����ÿ�������ﶼ���Լ���ʵ�֣�ֱ�������ӡ�

```js
var util = require('util');

console.log( util.format('hello %s', 'world') );
// �����hello world

console.log( util.format('1 + 1 = %d', 2) );
// �����1 + 1 = 2

console.log( util.format('info: %j', {nick: 'chyingp'}) );
// �����info: {"nick":"chyingp"}

console.log( util.format('%s is %d age old', 'chyingp') );
// �����chyingp is %d age old

console.log( util.format('%s is a man', 'chyingp', 'indeed') );
// �����chyingp is a man indeed
```

## ���Է�����util.inspect(obj[, options])

�ǳ�ʵ�õ�һ������������˵�����£�

* obj��jsԭʼֵ�����߶���
* options�����ò�������������ѡ��
    * showHidden�������true�Ļ���obj�ķ�ö������Ҳ�ᱻչʾ������Ĭ����false��
    * depth�����obj�Ƕ�����ô��depth���ƶ���ݹ�չʾ�Ĳ㼶����Կɶ�����һ���ĺô���Ĭ����2���������Ϊnull���������ơ�
    * colors���Զ�����ɫ������
    * showProxy��
    * maxArrayLength�����obj�����飬��ô��������չʾ�����������Ĭ����100���������Ϊnull���������ơ��������Ϊ0��������һ������չʾ��

```js
var util = require('util');

var obj = {};

Object.defineProperty(obj, 'nick', {
  enumerable: false,  
  value: 'chyingp'
});

console.log( util.inspect(obj) );
// �����{}

console.log( util.inspect(obj, {showHidden: true}) );
// �����{ [nick]: 'chyingp' }
```