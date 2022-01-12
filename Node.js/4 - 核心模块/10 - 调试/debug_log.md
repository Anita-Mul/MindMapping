## ǰ��

��node���򿪷���ʱ��������Ҫ��ӡ������־���õıȽ϶����debugģ�飬����express����о��õ��ˡ����ļ򵥾ټ������ӽ���˵����������ش���ʾ��������[����](https://github.com/chyingp/nodejs-learning-guide/tree/master/examples/2017.01.16-debug-log/debug)�ҵ���

>��ע��node��0.11.3�汾Ҳ������util.debuglog()���ڴ�ӡ������־��ʹ�÷�����debugģ���ͬС�졣

## ��������

���ȣ���װ`debug`ģ�顣

```bash
npm install debug
```

ʹ�úܼ򵥣�����node����ʱ������`DEBUG=app`�����������ɡ�

```javascript
/**
 * debug��������
 */
var debug = require('debug')('app');

// ���� DEBUG=app node 01.js
// �����app hello +0ms
debug('hello');
```

## ���ӣ������ռ�

����Ŀ�����ø��ӣ�������Ҫ����־���з����ӡ��debug֧������ռ䣬������ʾ��

* `DEBUG=app,api`����ʾͬʱ��ӡ�������ռ�Ϊapp��api�ĵ�����־��
* `DEBUG=a*`��֧��ͨ��������������ռ�Ϊa��ͷ�ĵ�����־����ӡ������

```javascript
/**
 * debug���ӣ������ռ�
 */
var debug = require('debug');
var appDebug = debug('app');
var apiDebug = debug('api');

// �ֱ��������漸�������Ч��
// 
//     DEBUG=app node 02.js
//     DEBUG=api node 02.js
//     DEBUG=app,api node 02.js
//     DEBUG=a* node 02.js
//     
appDebug('hello');
apiDebug('hello');
```

## ���ӣ������ռ��ų�

�е�ʱ��������Ҫ��ӡ�����еĵ�����־�����˸��������ռ��µġ����ʱ�򣬿���ͨ��`-`�������ų���������ʾ��`-account*`��ʾ�ų�������account��ͷ�������ռ�ĵ�����־��

```javascript
/**
 * debug���ӣ��Ų������ռ�
 */
var debug = require('debug');
var listDebug = debug('app:list');
var profileDebug = debug('app:profile');
var loginDebug = debug('account:login');

// �ֱ��������漸�������Ч��
// 
//     DEBUG=* node 03.js
//     DEBUG=*,-account* node 03.js
//     
listDebug('hello');
profileDebug('hello');
loginDebug('hello');
```

## ���ӣ��Զ����ʽ��

debugҲ֧�ָ�ʽ�����������������ʾ��

```javascript
var debug = require('debug')('app');

debug('my name is %s', 'chyingp');
```

���⣬Ҳ�����Զ����ʽ�����ݡ�

```javascript
/**
 * debug���Զ����ʽ��
 */
var createDebug = require('debug')

createDebug.formatters.h = function(v) {
  return v.toUpperCase();
};
 
var debug = createDebug('foo');

// ���� DEBUG=foo node 04.js 
// ��� foo My name is CHYINGP +0ms
debug('My name is %h', 'chying');
```

## �������

debug��https://github.com/visionmedia/debug
debuglog��https://nodejs.org/api/util.html#util_util_debuglog_section