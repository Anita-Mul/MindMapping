## ����

���ĵ��ص�����`req`��������ϡ�ǰ���Ѿ��ᵽ������ʵ��http.IncomingMessageʵ�����ڷ���ˡ��ͻ���������΢�в���

* ����˴�����ȡ���󷽵������Ϣ����request header�ȡ�
* �ͻ��˴�����ȡ��Ӧ�����ص������Ϣ����statusCode�ȡ�

��������ӣ�

```js
// ����� req
var http = require('http');
var server = http.createServer(function(req, res){
    console.log(req.headers);
    res.end('ok');
});
server.listen(3000);
```

�ͻ�������

```js
// �����res
var http = require('http');
http.get('http://127.0.0.1:3000', function(res){
    console.log(res.statusCode);
});
```

## ����/����/�¼� ����

http.IncomingMessage������/����/�¼� �����ر�࣬�����Ƿ�ͻ���/����� ���еģ�������м򵥹��ࡣ���Կ���

* ����˴����У�url
* �ͻ��˴����У�statusCode��statusMessage

| ����      |     ���� |   �����   |  �ͻ���  |
| :-------- | :--------:| :------: | :---: |
| �¼�    |   aborted |  ?  |   ?   |
| �¼�    |   close |  ?  |   ?   |
| ����    |   headers |  ?  |   ?   |
| ����    |   rawHeaders |  ?  |   ?   |
| ����    |   statusCode |  ?  |   ?   |
| ����    |   statusMessage |  ?  |   ?   |
| ����    |   httpVersion |  ?  |   ?   |
| ����    |   url |  ?  |   ?   |
| ����    |   socket |  ?  |   ?   |
| ����    |   .destroy() |  ?  |   ?   |
| ����    |   .setTimeout() |  ?  |   ?   |

## ����˵�����

### ����һ����ȡhttpVersion/method/url

������һ�����͵�HTTP�����ģ���������Ҫ�����ݰ�����HTTP�汾�����󷽷��������ַ������ͷ����

```http
GET /hello HTTP/1.1
Host: 127.0.0.1:3000
Connection: keep-alive
Cache-Control: no-cache
```

��ô����λ�ȡ�����ᵽ����Ϣ�أ��ܼ򵥣�ֱ���ϴ���

```js
// getClientInfo.js
var http = require('http');

var server = http.createServer(function(req, res){
    console.log( '1���ͻ�������url��' + req.url );
    console.log( '2��http�汾��' + req.httpVersion );
    console.log( '3��http���󷽷���' + req.method );
    console.log( '4��http����ͷ��' + JSON.stringify(req.headers) );

    res.end('ok');
});

server.listen(3000);
```

Ч�����£�

```bash
1���ͻ�������url��/hello
2��http�汾��1.1
3��http���󷽷���GET
4��http headers��{"host":"127.0.0.1:3000","connection":"keep-alive","cache-control":"no-cache","user-agent":"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.71 Safari/537.36","postman-token":"1148986a-ddfb-3569-e2c0-585634655fe4","accept":"*/*","accept-encoding":"gzip, deflate, sdch, br","accept-language":"zh-CN,zh;q=0.8,en;q=0.6,zh-TW;q=0.4"}
```

### ���Ӷ�����ȡget�������

����˴������£�

```js
// getClientGetQuery.js
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

���ʵ�ַ http://127.0.0.1:3000/hello?nick=chyingp&hello=world

������������

```bash
{"nick":"chyingp","hello":"world"}
```

### ����������ȡpost�������

����˴�������

```js
// getClientPostBody.js
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

ͨ��curl����post����

```bash
curl -d 'nick=casper&hello=world' http://127.0.0.1:3000
```

����˴�ӡ���£�

```bash
post body is: nick=casper&hello=world
```

��ע��post�����У���ͬ��`Content-type`��post body�в�С���죬����Ȥ��ͬѧ�����о��¡�

�����е�post����HTTP���Ĵ������

```http
POST / HTTP/1.1
Host: 127.0.0.1:3000
Content-Type: application/x-www-form-urlencoded
Cache-Control: no-cache

nick=casper&hello=world
```

## �ͻ��˴�����

### ����һ����ȡhttpVersion/statusCode/statusMessage

�������£�

```js
var http = require('http');
var server = http.createServer(function(req, res){
    res.writeHead(200, {'content-type': 'text/plain'});
    res.end('from server');
});
server.listen(3000);

var client = http.get('http://127.0.0.1:3000', function(res){
    console.log('1��http�汾��' + res.httpVersion);
    console.log('2������״̬�룺' + res.statusCode);
    console.log('3������״̬������Ϣ��' + res.statusMessage);
    console.log('4���������ģ�');

    res.pipe(process.stdout);
});
```

����̨�����

```bash
1��http�汾��1.1
2������״̬�룺200
3������״̬������Ϣ��OK
4���������ģ�
from server
```

## �¼��Աȣ�aborted��close

�ٷ��ĵ����������¼��Ľ����ǣ����ͻ�����ֹ����ʱ������aborted�¼������ͻ������ӶϿ�ʱ������close�¼����ٷ��ĵ������ǣ�[��ַ](https://nodejs.org/api/http.html#http_event_aborted_1)

���͵ñȽϺ�������ʵ��ʵ��Ա������������ٷ��ĵ��в�С���롣���⣬�ͻ��˴�������˴��ı���Ҳ�ǲ�ͬ�ġ�

### ����˱���

����ʵ�ʲ��Խ�����������ͻ��ˣ�

* abort����ʱ�������req��aborted��close�¼����ᴥ���������죩
* �����������ʱ�������req��close�¼����ᴥ������Ҳ�ܹ��죩

ֱ�Ӱ�����nodejs��Դ���룬���ֵ�ȷ��ͬʱ�����ģ�����������������������ǰ���ͻ���abort����

���Դ������£�

```js
var http = require('http');

var server = http.createServer(function(req, res){
    
    console.log('1���յ��ͻ�������: ' + req.url);
    
    req.on('aborted', function(){
        console.log('2���ͻ�������aborted');
    });
    
    req.on('close', function(){
        console.log('3���ͻ�������close');
    });
    
    // res.end('ok'); ���ⲻ���أ����ſͻ����ж�����
});

server.listen(3000, function(){
    var client = http.get('http://127.0.0.1:3000/aborted');
    setTimeout(function(){
        client.abort();  // �����ӳ�100ms��ȷ�����󷢳�
    }, 100);    
});


// �������
// 1���յ��ͻ�������: /aborted
// 2���ͻ�������aborted
// 3���ͻ�������close
```

���´�������nodejsԴ�루_http_server.js��

```js
  function abortIncoming() {
    while (incoming.length) {
      var req = incoming.shift();
      req.emit('aborted');
      req.emit('close');
    }
    // abort socket._httpMessage ?
  }
```

����һ���Աȣ�`req.on('close')`��`req.socket.on('close')`��

```js
// reqSocketClose.js
var http = require('http');

var server = http.createServer(function(req, res){
    
    console.log('server: �յ��ͻ�������');
    
    req.on('close', function(){
        console.log('server: req close');
    });
    
    req.socket.on('close', function(){
        console.log('server: req.socket close');
    });    
    
    res.end('ok'); 
});

server.listen(3000);

var client = http.get('http://127.0.0.1:3000/aborted', function(res){
    console.log('client: �յ��������Ӧ');
});
```

������£������˾���close�¼������ˡ�

```bash
server: �յ��ͻ�������
server: req.socket close
client: �յ��������Ӧ
```

### �ͻ��˱���

�²�ͻ��˵�aborted��closeҲ�������Ƴ����´��������Դ������¡�����һ���Ƚ�����˼�������`res.pipe(process.stdout)` ���д����Ƿ���ӣ���Ӱ��`close`�Ƿ񴥷���

* û��`res.pipe(process.stdout)`��close��������
* ��`res.pipe(process.stdout)`��close������

```js
var http = require('http');

var server = http.createServer(function(req, res){
    
    console.log('1������ˣ��յ��ͻ�������');
    
    res.flushHeaders();
    res.setTimeout(100);    // ���ⲻ���أ�3000ms��ʱ
});


server.on('error', function(){});

server.listen(3000, function(){

    var client = http.get('http://127.0.0.1:3000/aborted', function(res){

        console.log('2���ͻ��ˣ��յ��������Ӧ');

        // res.pipe(process.stdout); ע�����д���
        
        res.on('aborted', function(){
            console.log('3���ͻ��ˣ�aborted������');
        });

        res.on('close', function(){
            console.log('4���ͻ��ˣ�close������');
        });     
    });
});
```

## ��Ϣ���Դ�� .destroy()

����ǰ��aborted��close�ĴݲУ����ܵľ��� .destroy() �����ı��ֻ��кܶྪϲ֮����

���Դ������£�

```js
var http = require('http');

var server = http.createServer(function(req, res){
    
    console.log('����ˣ��յ��ͻ�������');
    
    req.destroy(new Error('����destroy'));
    
    req.on('error', function(error){
        console.log('����ˣ�req error: ' + error.message);
    });
    
    req.socket.on('error', function(error){
        console.log('����ˣ�req socket error: ' + error.message);
    })
});

server.on('error', function(error){
    console.log('����ˣ�server error: ' + error.message);
});

server.listen(3000, function(){

    var client = http.get('http://127.0.0.1:3000/aborted', function(res){
        // do nothing
    });

    client.on('error', function(error){
        console.log('�ͻ��ˣ�client error������' + error.message);
    });
});
```

������¡����� .destroy() ���õ�ʱ����ͬ��error �����Ķ���ͬ�������Թ��̱ȽϿ����ʱ�����ܽ�һ�£�

```bash
����ˣ��յ��ͻ�������
����ˣ�req socket error: ����destroy
�ͻ��ˣ�client error������socket hang up
```

## ����������

* rawHeaders��δ����ǰ��request header��
* trailers���ڷֿ鴫�����(chunk)���õ�����ʾtrailer���header�ɷֿ鴫�䡣������Ȥ�Ŀ����о��£�
* rawTrailers��

����trailers���ԣ�
>The request/response trailers object. Only populated at the 'end' event.

## д�ں���

һ��ò�ƺܼ򵥵Ķ���ʵ�ʱ����Ҫ����һЩ�����˲��ٶԱ�ʵ�飬Ҳ������һЩ����Ķ�������������ѧϰ��ͬѧ�����Լ��ද�ֳ���һ�� :)

TODO��

1. ��close��aborted���и�����Ա�
2. ��.destroy()���и�����Ա�

## �������

�ٷ��ĵ���
https://nodejs.org/api/http.html#http_class_http_incomingmessage
