## д��ǰ��

`body-parser`�Ƿǳ����õ�һ��`express`�м���������Ƕ�http��������н�����ʹ�÷ǳ��򵥣��������д����Ѿ������˴󲿷ֵ�ʹ�ó�����

```javascript
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
```

���ĴӼ򵥵����ӳ�����̽��`body-parser`���ڲ�ʵ�֡�����`body-parser`���ʹ�ã�����Ȥ��ͬѧ���Բο�[�ٷ��ĵ�](https://github.com/expressjs/body-parser/)��

## ���Ż���

����ʽ����ǰ������������һ��POST����ı��ģ�������ʾ��

```http
POST /test HTTP/1.1
Host: 127.0.0.1:3000
Content-Type: text/plain; charset=utf8
Content-Encoding: gzip

chyingp
```

������Ҫ����ע�����`Content-Type`��`Content-Encoding`�Լ��������壺

* Content-Type����������������͡����롣������������`text/plain`��`application/json`��`application/x-www-form-urlencoded`�������ı�����`utf8`��`gbk`�ȡ�
* Content-Encoding���������������ѹ����ʽ��������ȡֵ��`gzip`��`deflate`��`identity`��
* �������壺�����Ǹ���ͨ���ı��ַ���`chyingp`��

## body-parser��Ҫ����ʲô

`body-parser`ʵ�ֵ�Ҫ�����£�

1. ����ͬ���͵������壺����`text`��`json`��`urlencoded`�ȣ���Ӧ�ı�������ĸ�ʽ��ͬ��
2. ����ͬ�ı��룺����`utf8`��`gbk`�ȡ�
3. ����ͬ��ѹ�����ͣ�����`gzip`��`deflare`�ȡ�
4. �����߽硢�쳣�Ĵ���

## һ������ͬ����������

Ϊ�˷�����߲��ԣ��������Ӿ���������ˡ��ͻ��˴��룬�����������[����github](https://github.com/chyingp/nodejs-learning-guide/tree/master/examples/2017.05.20-express-body-parser)���ҵ���

### ����text/plain

�ͻ�������Ĵ������£�����Ĭ�ϱ��룬�������������ѹ��������������Ϊ`text/plain`��

```javascript
var http = require('http');

var options = {
    hostname: '127.0.0.1',
    port: '3000',
    path: '/test',
    method: 'POST',
    headers: {
        'Content-Type': 'text/plain',
        'Content-Encoding': 'identity'
    }
};

var client = http.request(options, (res) => {
    res.pipe(process.stdout);
});

client.end('chyingp');
```

����˴������¡�`text/plain`���ʹ���Ƚϼ򵥣�����buffer��ƴ�ӡ�

```javascript
var http = require('http');

var parsePostBody = function (req, done) {
    var arr = [];
    var chunks;

    req.on('data', buff => {
        arr.push(buff);
    });

    req.on('end', () => {
        chunks = Buffer.concat(arr);
        done(chunks);
    });
};

var server = http.createServer(function (req, res) {
    parsePostBody(req, (chunks) => {
        var body = chunks.toString();
        res.end(`Your nick is ${body}`)
    });
});

server.listen(3000);
```

### ����application/json

�ͻ��˴������£���`Content-Type`����`application/json`��

```javascript
var http = require('http');
var querystring = require('querystring');

var options = {
    hostname: '127.0.0.1',
    port: '3000',
    path: '/test',
    method: 'POST',
    headers: {
        'Content-Type': 'application/json',
        'Content-Encoding': 'identity'
    }
};

var jsonBody = {
    nick: 'chyingp'
};

var client = http.request(options, (res) => {
    res.pipe(process.stdout);
});

client.end( JSON.stringify(jsonBody) );
```

����˴������£����`text/plain`��ֻ�Ƕ��˸�`JSON.parse()`�Ĺ��̡�

```javascript
var http = require('http');

var parsePostBody = function (req, done) {
    var length = req.headers['content-length'] - 0;
    var arr = [];
    var chunks;

    req.on('data', buff => {
        arr.push(buff);
    });

    req.on('end', () => {
        chunks = Buffer.concat(arr);
        done(chunks);
    });
};

var server = http.createServer(function (req, res) {
    parsePostBody(req, (chunks) => {
        var json = JSON.parse( chunks.toString() );    // �ؼ�����    
        res.end(`Your nick is ${json.nick}`)
    });
});

server.listen(3000);
```

### ����application/x-www-form-urlencoded

�ͻ��˴������£�����ͨ��`querystring`����������и�ʽ�����õ�����`nick=chyingp`���ַ�����

```javascript
var http = require('http');
var querystring = require('querystring');

var options = {
    hostname: '127.0.0.1',
    port: '3000',
    path: '/test',
    method: 'POST',
    headers: {
        'Content-Type': 'form/x-www-form-urlencoded',
        'Content-Encoding': 'identity'
    }
};

var postBody = { nick: 'chyingp' };

var client = http.request(options, (res) => {
    res.pipe(process.stdout);
});

client.end( querystring.stringify(postBody) );
```

����˴������£�ͬ����`text/plain`�Ľ�����࣬�Ͷ��˸�`querystring.parse()`�ĵ��á�

```javascript
var http = require('http');
var querystring = require('querystring');

var parsePostBody = function (req, done) {
    var length = req.headers['content-length'] - 0;
    var arr = [];
    var chunks;

    req.on('data', buff => {
        arr.push(buff);
    });

    req.on('end', () => {
        chunks = Buffer.concat(arr);
        done(chunks);
    });
};

var server = http.createServer(function (req, res) {
    parsePostBody(req, (chunks) => {
        var body = querystring.parse( chunks.toString() );  // �ؼ�����
        res.end(`Your nick is ${body.nick}`)
    });
});

server.listen(3000);
```

## ��������ͬ����

�ܶ�ʱ�����Կͻ��˵����󣬲��õĲ�һ����Ĭ�ϵ�`utf8`���룬���ʱ�򣬾���Ҫ����������н��봦��

�ͻ����������£�������Ҫ�㡣

1. ������������`Content-Type`������` ;charset=gbk`
2. ��������룺���������`iconv-lite`������������б���`iconv.encode('����ԳС��', encoding)`

```javascript
var http = require('http');
var iconv = require('iconv-lite');

var encoding = 'gbk';  // �������

var options = {
    hostname: '127.0.0.1',
    port: '3000',
    path: '/test',
    method: 'POST',
    headers: {
        'Content-Type': 'text/plain; charset=' + encoding,
        'Content-Encoding': 'identity',        
    }
};

// ��ע��nodejs����֧��gbk���룬����������ǰ����Ҫ�Ƚ��б���
var buff = iconv.encode('����ԳС��', encoding);

var client = http.request(options, (res) => {
    res.pipe(process.stdout);
});

client.end(buff, encoding);
```

����˴������£���������������裺�����жϡ��������������ͨ��`Content-Type`��ȡ��������`gbk`��Ȼ��ͨ��`iconv-lite`���з�����������

```javascript
var http = require('http');
var contentType = require('content-type');
var iconv = require('iconv-lite');

var parsePostBody = function (req, done) {
    var obj = contentType.parse(req.headers['content-type']);
    var charset = obj.parameters.charset;  // �����жϣ������ȡ����ֵ�� 'gbk'

    var arr = [];
    var chunks;

    req.on('data', buff => {
        arr.push(buff);
    });

    req.on('end', () => {
        chunks = Buffer.concat(arr);
        var body = iconv.decode(chunks, charset);  // �������
        done(body);
    });
};

var server = http.createServer(function (req, res) {
    parsePostBody(req, (body) => {
        res.end(`Your nick is ${body}`)
    });
});

server.listen(3000);
```

## ��������ͬѹ������

����ٸ�`gzip`ѹ�������ӡ��ͻ��˴������£�Ҫ�����£�

1. ѹ������������`Content-Encoding`��ֵΪ`gzip`��
2. ������ѹ����ͨ��`zlib`ģ������������gzipѹ����

```javascript
var http = require('http');
var zlib = require('zlib');

var options = {
    hostname: '127.0.0.1',
    port: '3000',
    path: '/test',
    method: 'POST',
    headers: {
        'Content-Type': 'text/plain',
        'Content-Encoding': 'gzip'
    }
};

var client = http.request(options, (res) => {
    res.pipe(process.stdout);
});

// ע�⣺�� Content-Encoding ����Ϊ gzip ��ͬʱ�����͸�����˵�����ҲӦ���Ƚ���gzip
var buff = zlib.gzipSync('chyingp');

client.end(buff);
```

����˴������£�����ͨ��`zlib`ģ�飬������������˽�ѹ��������guzip����

```javascript
var http = require('http');
var zlib = require('zlib');

var parsePostBody = function (req, done) {
    var length = req.headers['content-length'] - 0;
    var contentEncoding = req.headers['content-encoding'];
    var stream = req;

    // �ؼ���������
    if(contentEncoding === 'gzip') {
        stream = zlib.createGunzip();
        req.pipe(stream);
    }

    var arr = [];
    var chunks;

    stream.on('data', buff => {
        arr.push(buff);
    });

    stream.on('end', () => {
        chunks = Buffer.concat(arr);        
        done(chunks);
    });

    stream.on('error', error => console.error(error.message));
};

var server = http.createServer(function (req, res) {
    parsePostBody(req, (chunks) => {
        var body = chunks.toString();
        res.end(`Your nick is ${body}`)
    });
});

server.listen(3000);
```

## д�ں���

`body-parser`�ĺ���ʵ�ֲ������ӣ�����Դ�����ᷢ�֣�����Ĵ������ڴ����쳣���߽硣

���⣬����POST���󣬻���һ���ǳ�������`Content-Type`��`multipart/form-data`������Ĵ�����Ը���Щ��`body-parser`������������֧�֡�ƪ�����ޣ������½��ټ���չ����

��ӭ���������д�©��ָ����

## �������

https://github.com/expressjs/body-parser/

https://github.com/ashtuchkin/iconv-lite
