����������Ŀ����˵����־�Ƿǳ���Ҫ��һ����log4js��ʹ�õñȽ϶��һ����־�����������Expressһ�����ʹ�á����Ĵ�����ʵ����ʼ������log4js��ʹ�ã��Լ���θ�Express�������ϡ�

## ��������

�����־���£�������־��ӡʱ�䡢��־������־���ࡢ��־���ݡ�

```javascript
// started.js
var log4js = require('log4js');
var logger = log4js.getLogger();
logger.debug('hello world');

// ����� 
// [2017-02-28 21:28:22.853] [DEBUG] [default] - hello world
```

## ��־����

`logger.setLevel('INFO');` ��ʾ��Ҫ��ӡ����ͼ������־��`INFO`��Ҳ����˵����������`logger.debug()`�ȼ������`INFO`�Ľӿڣ���־�ǲ����ӡ�����ġ�

```javascript
var log4js = require('log4js');
var logger = log4js.getLogger();
logger.setLevel('INFO');

logger.debug('level: debug');
logger.info('level: info');
logger.error('level: error');

// ������£�
// [2017-02-28 21:50:45.372] [INFO] [default] - level: info
// [2017-02-28 21:50:45.376] [ERROR] [default] - level: error
```

## ��־���

�������⣬�����Զ���־���з��࣬`log4js.getLogger(category)`��������ʾ

```javascript
var log4js = require('log4js');
var alogger = log4js.getLogger('category-a');
var blogger = log4js.getLogger('category-b');

alogger.info('hello');
blogger.info('hello');

// ������£�
// [2017-02-28 22:36:57.570] [INFO] category-a - hello
// [2017-02-28 22:36:57.574] [INFO] category-b - hello
```

## appenders

appendersָ����־�����λ�ã�����ͬʱ���ö������category�������֡����� `log4js.getLogger('info')` Ӧ�õľ��� `type` Ϊ `dateFile` �����á�

����ע�⵽��`type` Ϊ `console` ������û������ `category` ����ˣ����е���־�����ӡ������̨��

```javascript
var log4js = require('log4js');

log4js.configure({
    appenders: [
        { type: 'console'},
        { type: 'dateFile', filename: './logs/info.log', category: 'info' }
    ]
});

var logger = log4js.getLogger('info');
logger.setLevel('INFO');

logger.trace('trace');
logger.debug('debug');
logger.info('info');

// ������£�
// [2017-02-28 22:51:30.723] [INFO] info - info
```

## expressӦ��

һ���Ƚϼ򵥵��������£���־ȫ����ӡ������̨��

```javascript
var express = require('express');
var log4js = require('log4js');
var app = express();

log4js.configure({
    appenders: [
        { type: 'console', category: 'app' }
    ]
});

var logger = log4js.getLogger('app');

logger.setLevel('INFO');  // ���� > INFO ����־�Żᱻ��ӡ

app.use( log4js.connectLogger(logger) );

app.use(function(req, res, next){
    res.send('ok');
});

app.listen(3000);
```

���� http://127.0.0.1:3000 ����ӡ��־����

```bash
[2017-03-01 00:28:29.301] [INFO] app - ::ffff:127.0.0.1 - - "GET / HTTP/1.1" 304 - "" "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36"
```

`log4js.connectLogger(logger)` ʱ������������־�ļ���

```javascript
// ���� > INFO ����־�Żᱻ��ӡ
logger.setLevel('INFO'); 

// ��־�ļ����� WARN 
app.use( log4js.connectLogger(logger, {level: 'WARN'}) );
```

ע�⣬�����������־�������`logger.setLevel(level)`�޶��ļ�����ô��־���ᱻ��ӡ���������ӡ�

```javascript
logger.setLevel('INFO'); 

app.use( log4js.connectLogger(logger, {level: 'DEBUG'}) );
```

## �������

������https://github.com/nomiddlename/log4js-node
