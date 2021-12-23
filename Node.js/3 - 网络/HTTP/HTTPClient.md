## ClientRequest����

������� http.request(options) ʱ���᷵�� ClientRequestʵ������Ҫ��������HTTP�ͻ�������

��ǰ����½���Ѿ���httpģ��ĵ�������������˲��ٽ��ܣ���http.Server��http.ServerResponse��http.IncomingMessage��

����ǰ��Ļ�������ϸ���Ĳ�����⣬���ĸ����������Ϊ����

## �򵥵�GET����

���湹���˸�GET���󣬷��� http://id.qq.com/ ���������ص���ҳ���ݴ�ӡ�ڿ���̨�¡�

```js
var http = require('http');
var options = {
    protocol: 'http:',
    hostname: 'id.qq.com',
    port: '80',
    path: '/',
    method: 'GET'
};

var client = http.request(options, function(res){
    var data = '';
    res.setEncoding('utf8');
    res.on('data', function(chunk){
        data += chunk;
    });
    res.on('end', function(){
        console.log(data);
    });
});

client.end();
```

��Ȼ��Ҳ�����ñ�ݷ��� http.get(options) ������д

```js
var http = require('http');

http.get('http://id.qq.com/', function(res){
    var data = '';
    res.setEncoding('utf8');
    res.on('data', function(chunk){
        data += chunk;
    });
    res.on('end', function(){
        console.log(data);
    });
});
```

## �򵥵�post����

�����������У����ȴ����˸�http server�����𽫿ͻ��˷��͹��������ݻش���

���ţ������ͻ���POST���������˷������ݡ���Ҫע��ĵ��У�

1. method ָ��Ϊ POST��
2. headers �������� content-type Ϊ application/x-www-form-urlencoded��
3. ���ݷ���ǰ���� querystring.stringify(obj) �Դ���Ķ�������˸�ʽ����

```js
var http = require('http');
var querystring = require('querystring');

var createClientPostRequest = function(){
    var options = {
        method: 'POST',
        protocol: 'http:',
        hostname: '127.0.0.1',
        port: '3000',
        path: '/post',
        headers: {
            "connection": "keep-alive",
            "content-type": "application/x-www-form-urlencoded"
        }    
    };

    // ���͸�����˵�����
    var postBody = {
        nick: 'chyingp'
    };

    // �����ͻ�������
    var client = http.request(options, function(res){
        // ���������Server got client data: nick=chyingp
        res.pipe(process.stdout);  
    });

    // ���͵ı������壬�ǵ����� querystring.stringify() ������
    client.write( querystring.stringify(postBody) );
    client.end();
};

// ����˳���ֻ�Ǹ���ش��ͻ�������
var server = http.createServer(function(req, res){
    res.write('Server got client data: ');
    req.pipe(res);
});

server.listen(3000, createClientPostRequest);
```

## �����¼�

�ڹٷ��ĵ��http.RequestClient��ص��¼�����7������HTTPЭ��������ص���3�����ֱ��� connect��continue��upgrade������4���ֱ��� abort��aborted��socket��response��

* ������abort��aborted��socket��response
* ��HTTPЭ����أ�connect��continue��upgrade

��HTTPЭ����صĻ���Ը���Щ����Ϊ�漰HTTPЭ������ϸ�ڡ�����3����Լ򵥡�����ֱ���м򵥵Ľ��ܡ�

### response�¼�

����������һ�������յ����Է���˵���Ӧʱ��������ʵ�� http.get(url, cbk) �еĻص���һ���ģ����³������еĴ�ӡ��Ϣ��֪����

```js
var http = require('http');

var url = 'http://id.qq.com/';

var client = http.get(url, function(res){
    console.log('1. response event');
});

client.on('response', function(res){
    console.log('2. response event');
});

client.end();
```

��ӡ��Ϣ��

```bash
1. response event
2. response event
```

### socket�¼�

����client����socket��ʱ�򴥷��������Ϥnetģ�������¼�Ӧ�ò�İ�����󲿷�ʱ�򲢲���Ҫ��ע����¼�����Ȼ�ڲ���ʵͦ���ӵġ�

### abort/aborted �¼�

�������¼����ŷǳ��񣬶��������ж�ʱ���������������жϵķ��𷽣�

* abort���ͻ��������ж����󣨵�һ�ε��� client.abort() ʱ������
* aborted������������ж������������Ѿ��ж�ʱ������

### continue�¼�

���յ�����˵���Ӧ `100 Continue` ʱ��������ϤHTTPЭ���ͬѧӦ�ö� `100 Continue` �����˽⡣���ͻ��������˷����ײ� `Expect: 100-continue` ������˾���һ����У��󣬾����Կͻ��˵ĺ���������У����Ƿ��ط��� `100 Continue`��֪��ͻ��ˣ����Լ����������ݡ���request body��

### upgrade�¼�

ͬ���Ǹ�HTTPЭ��������ء����ͻ�����ͻ��˷�������ʱ�������������ײ������� `'Connection': 'Upgrade'` ���Դ�Ҫ�����ˣ�����ǰ�����������µ�Э�顣���������ͬ�⣬��ô������Э�����ͨ�š����ﲻ����չ��̫��ϸ�ڣ�ֱ���Ϲٷ��ĵ��Ĵ���

```js
const http = require('http');

// Create an HTTP server
var srv = http.createServer( (req, res) => {
  res.writeHead(200, {'Content-Type': 'text/plain'});
  res.end('okay');
});
srv.on('upgrade', (req, socket, head) => {
  socket.write('HTTP/1.1 101 Web Socket Protocol Handshake\r\n' +
               'Upgrade: WebSocket\r\n' +
               'Connection: Upgrade\r\n' +
               '\r\n');

  socket.pipe(socket); // echo back
});

// now that server is running
srv.listen(1337, '127.0.0.1', () => {

  // make a request
  var options = {
    port: 1337,
    hostname: '127.0.0.1',
    headers: {
      'Connection': 'Upgrade',
      'Upgrade': 'websocket'
    }
  };

  var req = http.request(options);
  req.end();

  req.on('upgrade', (res, socket, upgradeHead) => {
    console.log('got upgraded!');
    socket.end();
    process.exit(0);
  });
});
```

## ����

�������潲�⵽�����ԡ��������¼��⣬�������淽��û�н��������������ǲ���Ҫ��ƪ�����ޣ�������չ����

* client.abort()���ж�����
* client.setTimeout(timeout)������ʱ���ã�
* client.flushHeaders() ���罫�����ײ����ͳ�ȥ��
* client.setSocketKeepAlive()�����ڲ����� socket ��������ʱ���ͻ��ڲ����� socket.keepAlive()��
* client.setNoDelay([noDelay])�����ڲ����� socket ��������ʱ���ͻ��ڲ����� socket.setNoDelay()��

## �ο�����

upgrade���ƣ�
https://developer.mozilla.org/en-US/docs/Web/HTTP/Protocol_upgrade_mechanism

�ٷ��ĵ���
https://nodejs.org/api/http.html#http_class_http_clientrequest

nodejsԴ�룺
https://github.com/nodejs/node/blob/master/lib/_http_client.js
