## ģ�����

nodejs�ĺ���ģ�飬�����϶���stream�ĵ�ʵ��������process.stdout��http.clientRequest��

���ڴ󲿷ֵ�nodejs��������˵��ƽ��������ֱ���õ�streamģ�飬ֻ��Ҫ�˽�stream�����л��Ƽ��ɣ��ǳ���Ҫ����

��������Ҫʵ���Զ���streamʵ���Ŀ�������˵���͵úú��о�stream����չAPI�ˣ�����gulp���ڲ�ʵ�־ʹ����õ����Զ����stream���͡�

�����򵥵�������¥�����д����ʵ���˶�ȡ�ļ����ݣ�����ӡ������̨��

```js
const fs = require('fs');

fs.createReadStream('./sample.txt').pipe(process.stdout);
```

## Stream����

��nodejs�У�������stream���ͣ�

* Readable��������ȡ���ݣ����� `fs.createReadStream()`��
* Writable������д���ݣ����� `fs.createWriteStream()`��
* Duplex���ɶ�+��д������ `net.Socket()`��
* Transform���ڶ�д�Ĺ����У����Զ����ݽ����޸ģ����� `zlib.createDeflate()`������ѹ��/��ѹ����

## Readable Stream

���¶���nodejs�г�����Readable Stream����Ȼ���������ģ������в鿴�ĵ���

* http.IncomingRequest
* fs.createReadStream()
* process.stdin
* ����

����һ��

```js
var fs = require('fs');

fs.readFile('./sample.txt', 'utf8', function(err, content){
	// �ļ���ȡ��ɣ��ļ������� [��ã����ǳ���ԳС��]
	console.log('�ļ���ȡ��ɣ��ļ������� [%s]', content);
});
```

���Ӷ���

```js
var fs = require('fs');

var readStream = fs.createReadStream('./sample.txt');
var content = '';

readStream.setEncoding('utf8');

readStream.on('data', function(chunk){
	content += chunk;
});

readStream.on('end', function(chunk){
	// �ļ���ȡ��ɣ��ļ������� [��ã����ǳ���ԳС��]
	console.log('�ļ���ȡ��ɣ��ļ������� [%s]', content);
});
```

��������

����ʹ����`.pipe(dest)`���ô����ڣ����Դ�ļ��ϴ󣬶��ڽ����ڴ�ռ���кô���

```js
var fs = require('fs');

fs.createReadStream('./sample.txt').pipe(process.stdout);
```

ע�⣺����ֻ��ԭ�ⲻ���Ľ��������������̨������ʵ���ϸ�ǰ����������ϸ΢���졣���������޸ģ��ﵽ����ͬ����Ч��

```js
var fs = require('fs');

var onEnd = function(){
	process.stdout.write(']');	
};

var fileStream = fs.createReadStream('./sample.txt');
fileStream.on('end', onEnd)

fileStream.pipe(process.stdout);

process.stdout.write('�ļ���ȡ��ɣ��ļ�������[');

// �ļ���ȡ��ɣ��ļ�������[��ã����ǳ���ԳС��]
```

## Writable Stream

ͬ����д�ļ�Ϊ���ӣ������뽫`hello world`д��`sample.txt`�

����һ��

```js
var fs = require('fs');
var content = 'hello world';
var filepath = './sample.txt';

fs.writeFile(filepath, content);
```

���Ӷ���

```js
var fs = require('fs');
var content = 'hello world';
var filepath = './sample.txt';

var writeStram = fs.createWriteStream(filepath);
writeStram.write(content);
writeStram.end();
```

## Duplex Stream

�����Duplex streamӦ�þ���`net.Socket`ʵ���ˣ���ǰ����������нӴ����������ֱ���ϴ����ˣ������������˴��롢�ͻ��˴��롣

����˴��룺

```js
var net = require('net');
var opt = {
	host: '127.0.0.1',
	port: '3000'
};

var server = net.createServer((socket) => {
    socket.on('data', (data) => {
        console.log('client send message: ', data.toString());
    });
    socket.write('hello client');
});
server.listen(opt.port, opt.host, ()=>{
    console.log(server.address());
});
```

�ͻ��˴��룺

```js
var net = require('net');
var opt = {
	host: '127.0.0.1',
	port: '3000'
};

var client = net.connect(opt, function(){
	client.write('msg from client');  // ��д
});

// �ɶ�
client.on('data', function(data){
    // lient: got reply from server [reply from server]
	console.log('client: got reply from server [%s]', data);
	client.end();
});
```

## Transform Stream

Transform stream��Duplex stream��������Ҳ����˵��Transform streamҲͬʱ�ɶ���д����Duplex stream����������ڣ�Transform stream������������Ǵ�������Եġ�

������Transform stream����`zlib`��`crypto`������ٸ������ӣ��ļ���gzipѹ����

```js
var fs = require('fs');
var zlib = require('zlib');

var gzip = zlib.createGzip();

var inFile = fs.createReadStream('./extra/fileForCompress.txt');
var out = fs.createWriteStream('./extra/fileForCompress.txt.gz');

inFile.pipe(gzip).pipe(out);
```

## �������

https://nodejs.org/api/stream.html
