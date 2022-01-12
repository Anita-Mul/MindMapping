## �½ڸ���

morgan��expressĬ�ϵ���־�м����Ҳ��������express����Ϊnode.js����־�������ʹ�á�������ǳ���������Ҫ������

* morganʹ����������
* ��ν���־���浽�����ļ�
* ����APIʹ��˵��������
* ����ʹ�ã�1����־�ָ� 2������־д�����ݿ�
* Դ��������morgan����־��ʽ�Լ�Ԥ����

## ��������

���ȣ���ʼ����Ŀ��

```bash
npm install express morgan
```

Ȼ����`basic.js`��������´��롣

```js
var express = require('express');
var app = express();
var morgan = require('morgan');

app.use(morgan('short'));
app.use(function(req, res, next){
    res.send('ok');
});

app.listen(3000);
```

`node basic.js`���г��򣬲������������� http://127.0.0.1:3000 ����ӡ��־����

```bash
?  2016.12.11-advanced-morgan git:(master) ? node basic.js
::ffff:127.0.0.1 - GET / HTTP/1.1 304 - - 3.019 ms
::ffff:127.0.0.1 - GET /favicon.ico HTTP/1.1 200 2 - 0.984 ms
```

## ����־��ӡ�������ļ�

morgan֧��stream���������ͨ������ʵ�ֽ���־��ص�Ч�����������£�

```js
var express = require('express');
var app = express();
var morgan = require('morgan');
var fs = require('fs');
var path = require('path');

var accessLogStream = fs.createWriteStream(path.join(__dirname, 'access.log'), {flags: 'a'});

app.use(morgan('short', {stream: accessLogStream}));
app.use(function(req, res, next){
    res.send('ok');
});

app.listen(3000);
```

## ʹ�ý���

### ����API

morgan��API�ǳ��٣�ʹ��Ƶ����ߵľ���`morgan()`�������Ƿ���һ��express��־�м����

```js
morgan(format, options)
```

����˵�����£�

* format����ѡ��morgan�붨���˼�����־��ʽ��ÿ�ָ�ʽ���ж�Ӧ�����ƣ�����`combined`��`short`�ȣ�Ĭ����`default`����ͬ��ʽ�Ĳ��ɲο�[����](https://github.com/expressjs/morgan/#predefined-formats)�����Ļὲ���£�����Զ�����־��ʽ��
* options����ѡ�����������`stream�����ã�`��`skip`��`immediate`��
  * stream����־����������ã�Ĭ����`process.stdout`��
  * skip���Ƿ�������־��¼��ʹ�÷�ʽ���Բο�[����](https://github.com/expressjs/morgan/#skip)��
  * immediate������ֵ��Ĭ����false����Ϊtrueʱ��һ�յ����󣬾ͼ�¼��־�����Ϊfalse���������󷵻غ��ټ�¼��־��

### �Զ�����־��ʽ

���ȸ����morgan�е��������format �� token���ǳ��򵥣�

* format����־��ʽ�������Ǵ�����־��ʽ���ַ��������� `:method :url :status :res[content-length] - :response-time ms`��
* token��format����ɲ��֣����������`:method`��`:url`��ʹ��ν��token��

�����format��token������󣬾Ϳ��Կ���morgan�У������Զ�����־��ʽ�Ĺؼ�API��

```js
morgan.format(name, format);  // �Զ�����־��ʽ
morgan.token(name, fn);  // �Զ���token
```

## �Զ���format

�ǳ��򵥣�����ͨ��`morgan.format()`������Ϊ`joke`����־��ʽ��Ȼ��ͨ��`morgan('joke')`���ü��ɡ�

```js
var express = require('express');
var app = express();
var morgan = require('morgan');

morgan.format('joke', '[joke] :method :url :status');

app.use(morgan('joke'));

app.use(function(req, res, next){
    res.send('ok');
});

app.listen(3000);
```

�������������н��

```bash
?  2016.12.11-advanced-morgan git:(master) ? node morgan.format.js
[joke] GET / 304
[joke] GET /favicon.ico 200
```

## �Զ���token

�������£�ͨ��`morgan.token()`�Զ���token��Ȼ���Զ����token�������Զ����format�м��ɡ�

```js
var express = require('express');
var app = express();
var morgan = require('morgan');

// �Զ���token
morgan.token('from', function(req, res){
    return req.query.from || '-';
});

// �Զ���format�����а����Զ����token
morgan.format('joke', '[joke] :method :url :status :from');

// ʹ���Զ����format
app.use(morgan('joke'));

app.use(function(req, res, next){
    res.send('ok');
});

app.listen(3000);
```

���г��򣬲�����������Ⱥ���� http://127.0.0.1:3000/hello?from=app �� http://127.0.0.1:3000/hello?from=pc

```bash
?  2016.12.11-advanced-morgan git:(master) ? node morgan.token.js 
[joke] GET /hello?from=app 200 app
[joke] GET /favicon.ico 304 -
[joke] GET /hello?from=pc 200 pc
[joke] GET /favicon.ico 304 -
```

## �߼�ʹ��

### ��־�и�

һ������Ӧ�ã�������е���־����ص�ͬһ�������ļ���ʱ����ˣ��ļ����÷ǳ��󣬼�Ӱ�����ܣ��ֲ����ڲ鿴����ʱ�򣬾���Ҫ�õ���־�ָ��ˡ�

����`file-stream-rotator`������������������־�ָ�Ĺ���������`file-stream-rotator`��ص����ô��룬�����֮ǰ�����Ӳ�࣬���ﲻ׸����

```js
var FileStreamRotator = require('file-stream-rotator')
var express = require('express')
var fs = require('fs')
var morgan = require('morgan')
var path = require('path')

var app = express()
var logDirectory = path.join(__dirname, 'log')

// ensure log directory exists
fs.existsSync(logDirectory) || fs.mkdirSync(logDirectory)

// create a rotating write stream
var accessLogStream = FileStreamRotator.getStream({
  date_format: 'YYYYMMDD',
  filename: path.join(logDirectory, 'access-%DATE%.log'),
  frequency: 'daily',
  verbose: false
})

// setup the logger
app.use(morgan('combined', {stream: accessLogStream}))

app.get('/', function (req, res) {
  res.send('hello, world!')
})

```

### ��־д�����ݿ�

�е�ʱ�����ǻ������������󣬽�������־д�����ݿ⡣�������󳣼�����Ҫʵʱ��ѯͳ�Ƶ���־ϵͳ��

��morgan������ʵ���أ����ĵ��ϣ���û�п����ʺϵ���չ�ӿڡ����ǲ�������`morgan`��Դ�룬����ʵ�������ǳ��򵥡�

�ع���֮ǰ��־д�뱾���ļ������ӣ���ؼ������д������¡�ͨ��`stream`ָ����־���������

```js
var accessLogStream = fs.createWriteStream(path.join(__dirname, 'access.log'), {flags: 'a'});
app.use(morgan('short', {stream: accessLogStream}));
```

��`morgan`�ڲ�������ʵ���������ģ��򻯺󣩡�

```js
// optΪ�����ļ�
var stream = opts.stream || process.stdout;
var logString = createLogString();  // α���룬����format��token�Ķ��壬������־
stream.write(logString);
```

���ǣ������ñȽ�ȡ�ɵķ�ʽ��ʵ��Ŀ�ģ�����һ����`write`�����Ķ��󣬲���Ϊ`stream`���ô��롣

```js
var express = require('express');
var app = express();
var morgan = require('morgan');

// ��write�����Ķ���
var dbStream = {
  write: function(line){
    saveToDatabase(line);  // α���룬���浽���ݿ�
  }
};

// �� dbStream ��Ϊ stream �������ֵ
app.use(morgan('short', {stream: dbStream}));
app.use(function(req, res, next){
  res.send('ok');
});

app.listen(3000);
```

## ��������

morgan�Ĵ���ǳ���࣬���������˵��morgan���������ڰ�����

>token���� --> ��־��ʽ���� -> ��־��ʽԤ���� --> ����ﵽ/���� --> д��־

���У�token���塢��־��ʽ����ǰ���Ѿ������������ֻ���� **��־��ʽԤ����** ��ϸ�ڡ�

��ģ������Ԥ����һ������־��ʽԤ���룬Ҳ��Ϊ���������ܡ�Դ�����£���ؼ��Ĵ������`compile(fmt)`��

```js
function getFormatFunction (name) {
  // lookup format
  var fmt = morgan[name] || name || morgan.default

  // return compiled format
  return typeof fmt !== 'function'
    ? compile(fmt)
    : fmt
}
```

`compile()`������ʵ��ϸ�����ﲻ׸�������ؿ���`compile(fmt)`���ص����ݣ�

```js
var morgan = require('morgan');
var format = morgan['tiny'];
var fn = morgan.compile(format);

console.log(fn.toString());
```

���������������������£�����`tokens`��ʵ����`morgan`��

```bash
function anonymous(tokens, req, res
/**/) {
  return ""
    + (tokens["method"](req, res, undefined) || "-") + " "
    + (tokens["url"](req, res, undefined) || "-") + " "
    + (tokens["status"](req, res, undefined) || "-") + " "
    + (tokens["res"](req, res, "content-length") || "-") + " - "
    + (tokens["response-time"](req, res, undefined) || "-") + " ms";
}
```

����`morgan.token()`�Ķ��壬�ͺ�������

```js
function token (name, fn) {
  morgan[name] = fn
  return this
}
```

## �������

https://github.com/expressjs/morgan