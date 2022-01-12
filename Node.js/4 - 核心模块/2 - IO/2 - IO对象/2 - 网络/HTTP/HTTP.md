## httpģ�����

�����nodejs�����߶��ǳ��ſ���web server��Ŀ��ѡ����nodejs�����������չʾ�ģ�����httpģ�飬���Լ��д���͸㶨һ���������web server��

��nodejs�У�`http`����˵������ĵ�ģ�飬ͬʱҲ�ǱȽϸ��ӵ�һ��ģ�顣���ֺܼ򵥣���һ������ѧϰ�����ٳ�ѧ�߾ͻ����ͷ�ۣ���֪�Ӻ����֡�

�����ȴ�һ���򵥵����ӳ���������`http`ģ������ĵ��ĸ�ʵ�������걾�ģ�Ӧ�þ��ܹ���httpģ���и��������ʶ��

## һ���򵥵�����

������������У����Ǵ�����1��web��������1��http�ͻ���

* ������server���������Կͻ��˵����󣬲����ͻ�������ĵ�ַ���ظ��ͻ��ˡ�
* �ͻ���client����������������󣬲������������ص����ݴ�ӡ������̨��

����������ʾ��ֻ�м��У��������˲�����Ϣ������һС�ڻ���м򵥽��ܡ�

```js
var http = require('http');

// http server ����
var server = http.createServer(function(serverReq, serverRes){
    var url = serverReq.url;
    serverRes.end( '�����ʵĵ�ַ�ǣ�' + url );
});

server.listen(3000);

// http client ����
var client = http.get('http://127.0.0.1:3000', function(clientRes){
    clientRes.pipe(process.stdout);
});

```

## ���ӽ���

����������򵥵�������漰��4��ʵ�����󲿷�ʱ��serverReq��serverRes �������ǡ�

* server��http.Serverʵ���������ṩ���񣬴���ͻ��˵�����
* client��http.ClientRequesʵ�������������˷�������
* serverReq/clientRes����ʵ���� http.IncomingMessageʵ��serverReq ������ȡ�ͻ�������������Ϣ����request header����clientRes������ȡ����˷��ص������Ϣ������response header��
* serverRes��http.ServerResponseʵ��

## ����http.IncomingMessage��http.ServerResponse

�Ƚ��� http.ServerResponse ʵ�������ú���ȷ�������ͨ��http.ServerResponse ʵ�����������󷽷������ݡ�����������Ӧ��ͷ��������Ӧ����ȡ�

�������� http.IncomingMessage ʵ���������� server��client �������ˣ���ѧ�������е���ã������������

��server�ˣ���ȡ�����ͷ�����Ϣ���������󷽷���·�������ݵ����ݵȡ�
��client�ˣ���ȡ server �˷��͹�������Ϣ���������󷽷���·�������ݵ����ݵȡ�

http.IncomingMessageʵ�� ������������Ҫע�⣺method��statusCode��statusMessage��

* method��ֻ�� server �˵�ʵ���У�Ҳ���� serverReq.method��
* statusCode/statusMessage��ֻ�� client �� ��ʵ���У�Ҳ���� clientRes.method��

## ���ڼ̳�����չ

### http.Server

* http.Server �̳��� net.Server ������˳����Ҫѧһ�� net.Server ��API�����ԡ�����¼���
* net.createServer(fn)���ص��е� `socket` �Ǹ�˫����stream�ӿڣ�Ҳ����˵����ȡ���ͷ���Ϣ�����ͷ�������Ϣ��������

��ע��socket�Ŀͻ��ˡ����������Եĸ��������ʵ net.Server �ڲ�Ҳ������ net.Socket���������β��룩

```js
// �ο���https://cnodejs.org/topic/4fb1c1fd1975fe1e1310490b
var net = require('net');

var PORT = 8989;
var HOST = '127.0.0.1';

var server = net.createServer(function(socket){
    console.log('Connected: ' + socket.remoteAddress + ':' + socket.remotePort);
    
    socket.on('data', function(data){
        console.log('DATA ' + socket.remoteAddress + ': ' + data);
        console.log('Data is: ' + data);

        socket.write('Data from you is  "' + data + '"');
    });

    socket.on('close', function(){
         console.log('CLOSED: ' +
            socket.remoteAddress + ' ' + socket.remotePort);
    });
});
server.listen(PORT, HOST);

console.log(server instanceof net.Server);  // true
```

### http.ClientRequest

http.ClientRequest �ڲ�������һ��socket����������[��������](https://github.com/nodejs/node/blob/master/lib/_http_client.js#L174)��

������� http.request(options) ʱ���ڲ���������

```javascript
self.onSocket(net.createConnection(options));

```

### http.ServerResponse 

* ʵ���� Writable Stream interface���ڲ�Ҳ��ͨ��socket��������Ϣ��

### http.IncomingMessage 

* ʵ���� Readable Stream interface���ο�[����](https://github.com/nodejs/node/blob/master/lib/_http_incoming.js#L62)
* req.socket --> ��ø����������ص�socket

