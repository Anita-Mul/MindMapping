## ģ�����

netģ����ͬ����nodejs�ĺ���ģ�顣��httpģ��������ᵽ��http.Server�̳���net.Server�����⣬http�ͻ�����http����˵�ͨ�ž�������socket��net.Socket����Ҳ����˵����node����˱�̣�net�������Ʋ�����һ��ģ�顣

�����������netģ����Ҫ���������֣��˽�socket��̵�ͬѧӦ�ñȽ���Ϥ�ˣ�

* net.Server��TCP server���ڲ�ͨ��socket��ʵ����ͻ��˵�ͨ�š�
* net.Socket��tcp/���� socket��node��ʵ�֣���ʵ����ȫ˫����stream�ӿڡ�

���Ĵ�һ���򵥵� tcp�����/�ͻ��� �����ӿ�ʼ���⣬���ö����и���Ҫ����ʶ�������ٷֱ���� net.Server��net.Socket �Ƚ���Ҫ��API�����ԡ��¼���

���ڳ�ѧ�ߣ���������е����ӱ�����һ�������⡣

## �򵥵� server+client ����

tcp����˳������£�

```js
var net = require('net');

var PORT = 3000;
var HOST = '127.0.0.1';

// tcp�����
var server = net.createServer(function(socket){
    console.log('����ˣ��յ����Կͻ��˵�����');

    socket.on('data', function(data){
        console.log('����ˣ��յ��ͻ������ݣ�����Ϊ{'+ data +'}');

        // ���ͻ��˷�������
        socket.write('��ã����Ƿ����');
    });

    socket.on('close', function(){
         console.log('����ˣ��ͻ������ӶϿ�');
    });
});
server.listen(PORT, HOST, function(){
    console.log('����ˣ���ʼ�������Կͻ��˵�����');
});
```

tcp�ͻ������£�

```js
var net = require('net');

var PORT = 3000;
var HOST = '127.0.0.1';

// tcp�ͻ���
var client = net.createConnection(PORT, HOST);

client.on('connect', function(){
    console.log('�ͻ��ˣ��Ѿ������˽�������');
});

client.on('data', function(data){
    console.log('�ͻ��ˣ��յ���������ݣ�����Ϊ{'+ data +'}');
});

client.on('close', function(data){
    console.log('�ͻ��ˣ����ӶϿ�');
});

client.end('��ã����ǿͻ���');
```

���з���ˡ��ͻ��˴��룬����̨�ֱ�������£�

����ˣ�

```bash
����ˣ���ʼ�������Կͻ��˵�����
����ˣ��յ����Կͻ��˵�����
����ˣ��յ��ͻ������ݣ�����Ϊ{��ã����ǿͻ���}
����ˣ��ͻ������ӶϿ�
```

�ͻ��ˣ�

```bash
�ͻ��ˣ��Ѿ������˽�������
�ͻ��ˣ��յ���������ݣ�����Ϊ{��ã����Ƿ����}
�ͻ��ˣ����ӶϿ�
```

## ����� net.Server

### server.address()

���ط���˵ĵ�ַ��Ϣ������󶨵�ip��ַ���˿ڵȡ�

```js
console.log( server.address() );
// ������� { port: 3000, family: 'IPv4', address: '127.0.0.1' }
```

### server.close(callback])

�رշ�������ֹͣ�����µĿͻ��������м���ע�����

* �����ڴ����еĿͻ������󣬷�������ȴ����Ǵ����꣨��ʱ����Ȼ������ʽ�رա�
* �����رյ�ͬʱ��callback �ᱻִ�У�ͬʱ�ᴥ�� close �¼���
* �쳣�رյ�ͬʱ��callback Ҳ��ִ�У�ͬʱ����Ӧ�� error ��Ϊ�������롣�����绹û���� server.listen(port) ֮ǰ���͵�����server.close()��

�����ͨ��������������ӽ��жԱȣ��Ȱѽ����г���

* �ѵ���server.listen()�������رգ�close�¼�������Ȼ��callbackִ�У�error����Ϊundefined
* δ����server.listen()���쳣�رգ�close�¼�������Ȼ��callbackִ�У�errorΪ����Ĵ�����Ϣ����ע�⣬error �¼�û�д�����

����1������������ر�

```js
var net = require('net');
var PORT = 3000;
var HOST = '127.0.0.1';
var noop = function(){};

// tcp�����
var server = net.createServer(noop);

server.listen(PORT, HOST, function(){

    server.close(function(error){
        if(error){
            console.log( 'close�ص���������쳣��' + error.message );
        }else{
            console.log( 'close�ص�������������ر�' );
        }            
    }); 
});

server.on('close', function(){
    console.log( 'close�¼�������˹ر�' );
});

server.on('error', function(error){
    console.log( 'error�¼���������쳣��' + error.message );
});
```

���Ϊ��

```bash
close�¼�������˹ر�
close�ص�������������ر�
```

����2��������쳣�ر�

��������

```js
var net = require('net');
var PORT = 3000;
var HOST = '127.0.0.1';
var noop = function(){};

// tcp�����
var server = net.createServer(noop);

// û����ʽ�����������
// server.listen(PORT, HOST);

server.on('close', function(){
    console.log( 'close�¼�������˹ر�' );
});

server.on('error', function(error){
    console.log( 'error�¼���������쳣��' + error.message );
});

server.close(function(error){
    if(error){
        console.log( 'close�ص���������쳣��' + error.message );
    }else{
        console.log( 'close�ص�������������ر�' );
    }            
});
```

���Ϊ��

```bash
close�¼�������˹ر�
close�ص���������쳣��Not running
```

### server.ref()/server.unref()

�˽�node�¼�ѭ����ͬѧ��������APIӦ�ò�İ������Ҫ���ڽ�server �����¼�ѭ��/���¼�ѭ�������޳���Ӱ������ڻ᲻��Ӱ����̵��˳���

�Գ�ѧϰnet��ͬѧ��˵��������Ҫ�ر��ע������Ȥ���Լ�����ʵ��ͺá�

### �¼� listening/connection/close/error

* listening������ server.listen()����ʽ��ʼ���������ʱ�򴥷���
* connection�������µ��������ʱ����������Ϊ������ص� socket��
* close������˹رյ�ʱ�򴥷���
* error����������ʱ�򴥷�������������Ѿ���ռ�õĶ˿ڡ�

�����¼����Ƚϼ򵥣�������ٸ� connection �����ӡ�

�Ӳ��Խ�����Կ��������µĿͻ������Ӳ���ʱ��net.createServer(callback) �е�callback�ص� �ᱻ���ã�ͬʱ connection �¼�ע��Ļص�����Ҳ�ᱻ���á�

��ʵ�ϣ�net.createServer(callback) �е� callback ��node�ڲ�ʵ���� Ҳ�Ǽ�������Ϊ connection�¼� �ļ�������������Ȥ�Ŀ��Կ���node��Դ�롣

```js
var net = require('net');
var PORT = 3000;
var HOST = '127.0.0.1';
var noop = function(){};

// tcp�����
var server = net.createServer(function(socket){
    socket.write('1. connection ����\n');
});

server.on('connection', function(socket){
    socket.end('2. connection ����\n');
});

server.listen(PORT, HOST);
```

ͨ���������������Ч��

```bash
curl http://127.0.0.1:3000
```

�����

```bash
1. connection ����
2. connection ����
```

## �ͻ��� net.Socket

�����¿�ͷ�Ѿ��ٹ��ͻ��˵����ӣ������ٰ�������һ�¡�(��ע���ϸ���˵��Ӧ�ð� net.Socket �����ͻ��ˣ����﷽�㽲�����)

����node�ٷ��ĵ������Ļ����о� net.Socket �� net.Server Ҫ���Ӻܶ࣬�и����API���¼������ԡ���ʵ���ϣ��� net.Socket ��ص�API���¼������� ���й����£��ᷢ�֣���ʵҲ�����ر��ӡ�

�����뿴��һС�����ݡ�

```js
var net = require('net');

var PORT = 3000;
var HOST = '127.0.0.1';

// tcp�ͻ���
var client = net.createConnection(PORT, HOST);

client.on('connect', function(){
    console.log('�ͻ��ˣ��Ѿ������˽�������');
});

client.on('data', function(data){
    console.log('�ͻ��ˣ��յ���������ݣ�����Ϊ{'+ data +'}');
});

client.on('close', function(data){
    console.log('�ͻ��ˣ����ӶϿ�');
});

client.end('��ã����ǿͻ���');
```

## API�����Թ���

���¶�net.Socket��API�����ԣ�������;�����˴��µķ��࣬������߸��õ���⡣�󲿷�API�����Զ��Ƚϼ򵥣������ĵ���֪����ʲô�ģ�������Ȳ�չ����

### �������

* socket.connect()����3�ֲ�ͬ�Ĳ��������ڲ�ͬ�ĳ�����
* socket.setTimeout()�������������ӳ�ʱ���á�
* socket.setKeepAlive()���������ó����ӡ�
* socket.destroy(����socket.destroyed����������ʱ����������socket��ȷ�����socket�ϲ�������������IO������

### ���ݶ���д���

socket.write()��socket.end()��socket.pause()��socket.resume()��socket.setEncoding()��socket.setNoDelay()

### �����������

socket.bufferSize��socket.bytesRead��socket.bytesWritten

### �¼�ѭ�����

socket.ref()��socket.unref()

### ��ַ���

* socket.address()
* socket.remoteAddress��socket.remoteFamily��socket.remotePort
* socket.localAddress/socket.localPort

## �¼����

* data�����յ���һ�ഫ��������ʱ������
* connect�������ӽ���ʱ������
* close�����ӶϿ�ʱ�������������Ϊ��������µ����ӶϿ��������Ϊerror��
* end����������һ�෢���� FIN ����ʱ�򴥷������߿��Իع���HTTP��ζϿ����ӵģ���Ĭ������£�allowHalfOpen == false����socket������������ٲ���������Ҳ���԰� allowHalfOpen ����Ϊ true�������Ϳ��Լ�����socket��д���ݡ���Ȼ���������Ҫ�ֶ����� socket.end()
* error�����д�����ʱ���ͻᴥ��������Ϊerror�����ٷ��ĵ�����һ�仰�������������ǵ�����Ŀ���̫�࣬Ҳ������⣩
* timeout����ʾ�û���socket �Ѿ���ʱ����Ҫ�ֶ��ر����ӡ�
* drain����д������˵�ʱ�򴥷��������Ǻܺ�������������Կ���stream�Ľ��ܣ�
* lookup�������������ʱ������

## �������

�ٷ��ĵ���
https://nodejs.org/api/net.html#net_socket_destroy_exception