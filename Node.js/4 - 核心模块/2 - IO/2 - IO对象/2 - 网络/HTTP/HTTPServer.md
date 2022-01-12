## http����˸���

## ����server

���д���㶨

```js
var http = require('http');
var requestListener = function(req, res){
    res.end('ok');
};
var server = http.createServer(requestListener);
// var server = new http.Server(requestListener); �������ǵȼ۵�
server.listen(3000);
```

## ��ȡ������Ϣ

### HTTP�汾��HTTP method��headers��url

```js
var http = require('http');

var server = http.createServer(function(req, res){
    console.log('�ͻ�������url��' + req.url);
    console.log('http�汾��' + req.httpVersion);
    console.log('http���󷽷���' + req.method);

    res.end('ok');
});

server.listen(3000);
```

Ч�����£�

```bash
�ͻ�������url��/hello
http�汾��1.1
http���󷽷���GET
http headers��{"host":"127.0.0.1:3000","connection":"keep-alive","cache-control":"max-age=0","upgrade-insecure-requests":"1","user-agent":"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.71 Safari/537.36","accept":"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8","accept-encoding":"gzip, deflate, sdch, br","accept-language":"zh-CN,zh;q=0.8,en;q=0.6,zh-TW;q=0.4"}
```

### ��ȡget�������

```js
var http = require('http');
var url = require('url');
var querystring = require('querystring');

var server = http.createServer(function(req, res){
    var urlObj = url.parse(req.url);
    var query = urlObj.query;
    var queryObj = querystring.parse(query);
    
    console.log( JSON.stringify(queryObj) );
    
    res.end('ok');
});

server.listen(3000);
```

������������

```bash
curl http://127.0.0.1:3000/hello\?nick\=chyingp\&hello\=world
```

������������

```bash
{"nick":"chyingp","hello":"world"}
```


### ��ȡpost�������

��������

```js
var http = require('http');
var url = require('url');
var querystring = require('querystring');

var server = http.createServer(function(req, res){
    
    var body = '';  
    req.on('data', function(thunk){
        body += thunk;
    });

    req.on('end', function(){
        console.log( 'post body is: ' + body );
        res.end('ok');
    }); 
});

server.listen(3000);
```

ͨ��curl���켫��post����

```bash
curl -d 'nick=casper&hello=world' http://127.0.0.1:3000
```

����˴�ӡ���¡�ע�⣬��post�����У���ͬ��`Content-type`��post body�в�С���죬����Ȥ��ͬѧ�����Լ����¡�

```bash
post body is: nick=casper&hello=world
```

���籾���е�post����HTTP���Ĵ������

```http
POST / HTTP/1.1
Host: 127.0.0.1:3000
Content-Type: application/x-www-form-urlencoded
Cache-Control: no-cache

nick=casper&hello=world
```


## ������¼�

���ȣ���������������Щ�¼�

checkContinue��checkExpectation��clientError��close��connect��connection��request��upgrade

### error

```js
var http = require('http');
var PORT = 3000;
var noop = function(){};

var svr = http.createServer(noop);
var anotherSvr = http.createServer(noop);

anotherSvr.on('error', function(e){
    console.error('��������' + e.message);
});

svr.listen(PORT, function(){
    anotherSvr.listen(PORT);
});
```

���д��룬�������

```bash
��������listen EADDRINUSE :::3000
```

### connect vs connection

���߲��ǳ�����Ȼ���ۿ����е���

* connect�����ͻ��˵�HTTP methodΪconnectʱ������
* connection����TCP���ӽ���ʱ�������󲿷�ʱ����Ժ�������¼���Ŀ��ģ���ڲ��Լ��õ����ѣ������⣬����ͨ�� req.connection ����ȡ���socket����nodejsԴ��������req.socket��req.connection ��ָ�������socket�������⣬socket�ϵ�readable�¼����ᴥ��������ԭ���뿴ģ���ڲ�ʵ�֣��������ǻ�û�о���

�󲿷�ʱ�򶼲����õ���������Ҫ����HTTP�������ͻ��˷��� connect ����ʱ������ע���ƹ��� requestListener��

```js
var http = require('http');
var PORT = 3000;

var server = http.createServer(function(req, res){
    res.end('ok');
});

// ע�⣺����connect����������� ./httpServerEventConnectClient.js ��
server.on('connect', function(req, socket, head){
    console.log('connect�¼�����');
    socket.end();   // �����Ҿ�ֻ��ٸ����ӣ�û����������������
});

server.listen(PORT);
```

### request

�����µ����ӵ���ʱ�������Ǹ� connection ��ʲô�����أ�

���ˣ�`keep-alive`�����ǳ����ڳ־û����ӵ�����£���� request ���ܶ�Ӧ���� һ�� connection��

��������û��`keep-alive`�ĳ���

```js
var http = require('http');
var PORT = 3000;
var requestIndex = 0;
var connectionIndex = 0;

var server = http.createServer(function(req, res){
    res.end('ok');
});

server.on('request', function(req, res){
    requestIndex++;
    console.log('request event: ��'+ requestIndex +'������');
});

server.on('connection', function(req, res){
    connectionIndex++;
    console.log('connection event: ��'+ connectionIndex +'������');
});

server.listen(PORT);
```

ͨ��curl��������3�����󣬿���Ч��

```bash
for i in `seq 1 3`; do curl http://127.0.0.1:3000; done
```

������������

```bash
connection event: ��1������
request event: ��1������
connection event: ��2������
request event: ��2������
connection event: ��3������
request event: ��3������
```

Ȼ������������`keep-alive`�ĳ������� postman ������� keep-alive ���������յ�HTTP����������

```http
GET / HTTP/1.1
Host: 127.0.0.1:3000
Connection: keep-alive
Cache-Control: no-cache
Postman-Token: 6027fda7-f936-d3ac-e54f-dafcbf5e58ff
```

��������3�����󣬷���˴�ӡ��־����

```bash
connection event: ��1������
request event: ��1������
request event: ��2������
request event: ��3������
```



## �����ýӿ�

### server.close([callback]); 

�رշ���������ʵ���� (new net.Server()).close()��ֹͣ�����µ����ӡ�
�Ѿ������ϵ����������������������ӽ�����ʱ��server ��ʽ�رգ����׳� close �¼���
һ���ṩ��callback���Ͳ��ü���close; ������close���Ͳ������callback��

### ����server.listen()

��ʵ���� server.listen(PORT) ���ּ�����ʽ�⣬�������¼�����Բ���ô���õļ�����ʽ���õ���ʱ�򿴿��ĵ������ˡ�

server.listen(handle[, callback])�����������ļ���������fd����windows��֧�֣�������server������socket
server.listen(path[, callback])����������socket������һ�� UNIX socket server ��
server.listen([port][, hostname][, backlog][, callback])

### ���糬ʱ server.setTimeout(msecs, callback)

�����������ӵĳ�ʱʱ�䡣������ msecs û����Ӧʱ������ͻ��Զ��Ͽ���

������� callback����ô�� timeout ����ʱ���ͻὫtimeout��socket��Ϊ��������callback��

ע�⣬һ������³�ʱ��socket���Զ����١������㴫��callback�������Ҫ�ֶ�end����destroy���socket��

## ����������

server.listening���Ƿ��ڼ�������
server.timeout�����ó�ʱʱ�䣨���룩��ע�⣬�޸����ֵ��ֻ����½��������Ӳ���Ӱ�졣���⣬��timeout����Ϊ0���ͻ�����Զ���ʱ��Ϊ����Ŀ�ⲻ�Ƽ���
server.maxHeadersCount���ͻ�����ഫ�͵�header������Ĭ����1000���������Ϊ0����û�����ơ������⣺�������1000��ô�죿����



