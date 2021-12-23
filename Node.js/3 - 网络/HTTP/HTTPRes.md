## ����

httpģ���Ľ���֮һ��`res`��Ӧ�ö���İ���ˡ�һ��web������򣬽��ܵ����Կͻ��˵�http�������ͻ��˷�����ȷ����Ӧ���ݣ������`res`��ְ��

���ص����ݰ�����״̬����/״̬������Ϣ����Ӧͷ������Ӧ���塣���Ļ�ټ����򵥵����ӡ�

```js
var http = require('http');
var server = http.createServer(function(req, res){
    res.end('ok');
});
server.listen(3000);
```

## ����

������������У�����ͬʱ������ ״̬����/״̬������Ϣ����Ӧͷ������Ӧ���壬������ô�򵥡�

```js
var http = require('http');

// ����״̬�롢״̬������Ϣ����Ӧ����
var server = http.createServer(function(req, res){
    res.writeHead(200, 'ok', {
        'Content-Type': 'text/plain'
    });
    res.end('hello');
});

server.listen(3000);
```

### ����״̬���롢״̬������Ϣ

`res`�ṩ�� res.writeHead()��res.statusCode/res.statusMessage ��ʵ�����Ŀ�ġ�

�����������Ҫ���� 200/ok ������

```js
res.writeHead(200, 'ok');
```

Ҳ����

```js
res.statusCode = 200;
res.statusMessage = 'ok';
```

���߲�࣬���������

1. res.writeHead() �����ṩ����Ĺ��ܣ�����������Ӧͷ����
2. ����Ӧͷ�����ͳ�ȥ��res.statusCode/res.statusMessage �ᱻ���ó��ѷ��ͳ�ȥ�� ״̬����/״̬������Ϣ��

### ������Ӧͷ��

`res`�ṩ�� res.writeHead()��response.setHeader() ��ʵ����Ӧͷ�������á�

������������� `Content-Type` ����Ϊ `text-plain`����ô����

```js
// ����һ
res.writeHead(200, 'ok', {
    'Content-Type': 'text-plain'
});

// ������
res.setHeader('Content-Type', 'text-plain');
```

���ߵĲ�����������أ�

1. res.writeHead() ������������header��
2. �Ѿ�ͨ�� res.setHeader() ������header����ͨ�� res.writeHead() ����ͬ��header��res.writeHead() �����ûḲ��֮ǰ�����á�

���ڵ�2����죬����ٸ����ӡ�������룬���յ� `Content-Type` Ϊ `text/plain`��

```js
var http = require('http');

var server = http.createServer(function(req, res){
    res.setHeader('Content-Type', 'text/html');
    res.writeHead(200, 'ok', {
        'Content-Type': 'text/plain'
    });
    res.end('hello');
});

server.listen(3000);
```

����������ӣ���ֱ�ӱ���������ϢΪ `Error: Can't set headers after they are sent.`��

```js
var http = require('http');

var server = http.createServer(function(req, res){    
    res.writeHead(200, 'ok', {
        'Content-Type': 'text/plain'
    });
    res.setHeader('Content-Type', 'text/html');
    res.end('hello');
});

server.listen(3000);
```

### ������Ӧͷ������

����ɾ���ġ��� �����׵ġ�����ֱ����˵���£�����̫�򵥾�ֱ���ϴ����ˡ�

```js
// ��
res.setHeader('Content-Type', 'text/plain');

// ɾ
res.removeHeader('Content-Type');

// ��
res.setHeader('Content-Type', 'text/plain');
res.setHeader('Content-Type', 'text/html');  // ����

// ��
res.getHeader('content-type');
```

�������Բ�ͬ���� res.getHeader(name)��name �õ���Сд������ֵû�����⴦��

```js
res.setHeader('Content-Type', 'TEXT/HTML');
console.log( res.getHeader('content-type') );  // TEXT/HTML

res.setHeader('Content-Type', 'text/plain');
console.log( res.getHeader('content-type') );  // text/plain
```

���⣬���в���ô���õģ�

* res.headersSent��header�Ƿ��Ѿ����ͣ�
* res.sendDate��Ĭ��Ϊtrue����Ϊtrueʱ������response header���Զ�����Date�ײ���

## ������Ӧ����

��Ҫ�õ� res.write() �Լ� res.end() ����������

res.write() API����Ϣ���Դ󣬽��鿴��[�ٷ��ĵ�](https://nodejs.org/api/http.html#http_response_write_chunk_encoding_callback)��

### response.write(chunk[, encoding][, callback])

* chunk����Ӧ��������ݣ�������string��Ҳ������buffer����Ϊstringʱ��encoding��������ָ�����뷽ʽ����Ĭ����utf8��
* encoding�����뷽ʽ��Ĭ���� utf8��
* callback������Ӧ��flushedʱ��������TODO �������¸��õĽ��͡�������

ʹ����ûʲô�Ѷȣ�ֻ����Щע�����

1. ��� res.write() ������ʱ�� res.writeHead() ��û�����ù�����ô���ͻ��header flush��ȥ��
2. res.write() ���Ա����ö�Ρ�
3. �� res.write(chunk) ��һ�α�����ʱ��node �Ὣ header ��Ϣ �Լ� chunk ���͵��ͻ��ˡ��ڶ��ε��� res.write(chunk) ��node ����Ϊ����Ҫstreaming data��WTF������ô���룩������

>Returns true if the entire data was flushed successfully to the kernel buffer. Returns false if all or part of the data was queued in user memory. 'drain' will be emitted when the buffer is free again.

### response.end([data][, encoding][, callback])

������ res.write() �Ļ���res.end() �ͺܼ��ˡ�res.end() ���ô��Ǹ���nodejs��header��body�������ˣ������Ӧ�͵�����ɡ�

�е�����﷨�ǣ����Կ��������������õ���ϡ�����callback������Ӧ���ݽ����󴥷���

```js
res.write(data, encoding);
res.end()
```

## chunk����

�ο����http://stackoverflow.com/questions/6258210/how-can-i-output-data-before-i-end-the-response

Ҳ����˵������nodejs�����ԣ�����Ҫ�˽� HTTPЭ�顢������ľ���ʵ�֡���ϸ˼���֣�

����� `text/html`

```js
var http = require('http');

http.createServer(function(req, res) {    
    res.setHeader('Content-Type', 'text/html; charset=utf-8');
    res.write('hello');

    setTimeout(function() {
        res.write(' world!');
        res.end();
    }, 2000);

}).listen(3000);
```

����� `text/plain`

```js
var http = require('http');

http.createServer(function (req, res) {
    res.writeHead(200, {
        'Content-Type': 'text/plain; charset=utf-8',
        'X-Content-Type-Options': 'nosniff'
    });
    res.write('hello');

    setTimeout(function(){
        res.write('world');
        res.end()
    }, 2000);
    
}).listen(3000);
```

ʧ������

```js
var http = require('http');

var server = http.createServer(function(req, res){
    res.writeHead(200, 'ok', {
        'Content-Type': 'text/html'
    });
    res.write('hello');
    
    setTimeout(function(){
        res.write('world');
        res.end();
    }, 2000);
});

server.listen(3000);
```

## ��ʱ����

�ӿڣ�response.setTimeout(msecs, callback)

���� timeout �¼���˵����ͬ�����Լ����ࣨWTF����������Ϣ�����������demo TODO

>If no 'timeout' listener is added to the request, the response, or the server, then sockets are destroyed when they time out. If you assign a handler on the request, the response, or the server's 'timeout' events, then it is your responsibility to handle timed out sockets.

## �¼� close/finish

* close��response.end() ������ǰ�����ӾͶϿ��ˡ���ʱ�ᴥ������¼���
* finish����Ӧheader��body���Ѿ����ͳ�ȥ����������ϵͳ���ŶӵȺ��䣩�����ͻ����Ƿ�ʵ���յ�����Ϊֹ��������¼���res �ϾͲ������������¼�������

## ��������������/����

* response.finished��һ��ʼ��false����Ӧ����������Ϊtrue��
* response.sendDate��Ĭ����true���Ƿ��Զ�����Dateͷ��������HTTPЭ���Ǳ���Ҫ�ģ������ǵ����ã���Ȼ��Ҫ����Ϊfalse��
* response.headersSent��ֻ�����ԡ���Ӧͷ���Ƿ��ѷ��͡�
* response.writeContinue()������  HTTP/1.1 100 Continue ��Ϣ���ͻ��ˣ���ʾ˵�����Ը����ܿͻ��˵���������������������ģ�body)����TODO ����demoɶ���Ǵ��ĺã�


## �������

How can I output data before I end the response?
http://stackoverflow.com/questions/6258210/how-can-i-output-data-before-i-end-the-response

8.2.3 Use of the 100 (Continue) Status
http://greenbytes.de/tech/webdav/rfc2616.html#use.of.the.100.status
