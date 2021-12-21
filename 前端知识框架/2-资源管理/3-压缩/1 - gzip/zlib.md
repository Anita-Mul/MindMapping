### ѹ��������

�ǳ��򵥵ļ��д��룬������˱����ļ���gzipѹ����

```javascript
var fs = require('fs');
var zlib = require('zlib');

var gzip = zlib.createGzip();

var inFile = fs.createReadStream('./extra/fileForCompress.txt');
var out = fs.createWriteStream('./extra/fileForCompress.txt.gz');

inFile.pipe(gzip).pipe(out);
```

### ��ѹ������

ͬ���ǳ��򵥣����Ǹ����������

```javascript
var fs = require('fs');
var zlib = require('zlib');

var gunzip = zlib.createGunzip();

var inFile = fs.createReadStream('./extra/fileForCompress.txt.gz');
var outFile = fs.createWriteStream('./extra/fileForCompress1.txt');

inFile.pipe(gunzip).pipe(outFile);
```

## �����gzipѹ��

���볬���򵥡������ж� �Ƿ���� **accept-encoding** �ײ�����ֵΪ**gzip**��

* �񣺷���δѹ�����ļ���
* �ǣ�����gzipѹ������ļ���

```javascript
var http = require('http');
var zlib = require('zlib');
var fs = require('fs');
var filepath = './extra/fileForGzip.html';

var server = http.createServer(function(req, res){
    var acceptEncoding = req.headers['accept-encoding'];
    var gzip;
    
    if(acceptEncoding.indexOf('gzip')!=-1){ // �ж��Ƿ���Ҫgzipѹ��
        
        gzip = zlib.createGzip();
        
        // �ǵ���Ӧ Content-Encoding��������������ļ��� gzip ѹ����
        res.writeHead(200, {
            'Content-Encoding': 'gzip'
        });
        fs.createReadStream(filepath).pipe(gzip).pipe(res);
    
    }else{

        fs.createReadStream(filepath).pipe(res);
    }

});

server.listen('3000');
```

## ������ַ���gzipѹ��

�����ǰ�����Ӵ�ͬС�졣��������� **zlib.gzipSync(str)** ���ַ�������gzipѹ����

```javascript
var http = require('http');
var zlib = require('zlib');

var responseText = 'hello world';

var server = http.createServer(function(req, res){
    var acceptEncoding = req.headers['accept-encoding'];
    if(acceptEncoding.indexOf('gzip')!=-1){
        res.writeHead(200, {
            'content-encoding': 'gzip'
        });
        res.end( zlib.gzipSync(responseText) );
    }else{
        res.end(responseText);
    }

});

server.listen('3000');
```

## д�ں���

deflateѹ����ʹ��Ҳ��࣬����Ͳ�׸����������ϸ�÷��ɲο�[�ٷ��ĵ�](https://nodejs.org/api/zlib.html#zlib_class_options)��