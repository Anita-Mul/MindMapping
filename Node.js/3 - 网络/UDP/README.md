## ģ�����

dgramģ���Ƕ�UDP socket��һ���װ�����netģ��򵥺ܶ࣬���濴���ӡ�

## UDP�ͻ��� vs UDP�����

���ȣ�����UDP server���������Զ˿�33333������

**server.js**

```js
// ���ӣ�UDP�����
var PORT = 33333;
var HOST = '127.0.0.1';

var dgram = require('dgram');
var server = dgram.createSocket('udp4');

server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});

server.on('message', function (message, remote) {
    console.log(remote.address + ':' + remote.port +' - ' + message);
});

server.bind(PORT, HOST);
```


Ȼ�󣬴���UDP socket����˿�33333��������

**client.js**

```js
// ���ӣ�UDP�ͻ���
var PORT = 33333;
var HOST = '127.0.0.1';

var dgram = require('dgram');
var message = Buffer.from('My KungFu is Good!');

var client = dgram.createSocket('udp4');

client.send(message, PORT, HOST, function(err, bytes) {
    if (err) throw err;
    console.log('UDP message sent to ' + HOST +':'+ PORT);
    client.close();
});
```

���� server.js��

```bash
node server.js
```

���� client.js��

```bash
?  2016.12.22-dgram git:(master) ? node client.js 
UDP message sent to 127.0.0.1:33333
```

����˴�ӡ��־����

```bash
UDP Server listening on 127.0.0.1:33333
127.0.0.1:58940 - My KungFu is Good!
```

## �㲥

ͨ��dgramʵ�ֹ㲥���ܼܺ򵥣�����˴������¡�

```js
var dgram = require('dgram');
var server = dgram.createSocket('udp4');
var port = 33333;

server.on('message', function(message, rinfo){
    console.log('server got message from: ' + rinfo.address + ':' + rinfo.port);
});

server.bind(port);
```

���Ŵ����ͻ��ˣ����ַ'255.255.255.255:33333'���й㲥��

```js
var dgram = require('dgram');
var client = dgram.createSocket('udp4');
var msg = Buffer.from('hello world');
var port = 33333;
var host = '255.255.255.255';

client.bind(function(){
    client.setBroadcast(true);
    client.send(msg, port, host, function(err){
        if(err) throw err;
        console.log('msg has been sent');
        client.close();
    });
});
```

���г������շ���˴�ӡ��־����

```bash
?  2016.12.22-dgram git:(master) ? node broadcast-server.js
server got message from: 192.168.0.102:61010
```

## �������

https://nodejs.org/api/dgram.html
