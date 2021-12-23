## ģ�����

���ģ�����Ҫ�ԣ���������ǿ���ˡ������簲ȫ���������Ͼ��Ľ��죬��վ����HTTPS�Ǹ���Ȼ�����ơ�

��nodejs�У��ṩ�� https ���ģ������� HTTPS ��ع��ܡ��ӹٷ��ĵ��������� http ģ���÷��ǳ����ơ�

������Ҫ���������֣�

1. ͨ���ͻ��ˡ�����˵����ӣ���httpsģ��������Ž��⡣
2. ��η��ʰ�ȫ֤�鲻�����ε���վ������ 12306 Ϊ���ӣ�

ƪ�����ޣ������޷��� HTTPSЭ�� �� ��ؼ�����ϵ �����ི�⣬�����⻶ӭ���Խ�����

## �ͻ�������

��httpģ����÷��ǳ���ֻ��������ĵ�ַ��httpsЭ��Ķ��ѣ��������£�

```js
var https = require('https');

https.get('https://www.baidu.com', function(res){
    console.log('status code: ' + res.statusCode);
    console.log('headers: ' + JSON.stringify(res.headers));

    res.on('data', function(data){
        process.stdout.write(data);
    });
}).on('error', function(err){
    console.error(err);
});
```

## ���������

�����ṩHTTPS������Ҫ��HTTPS֤�顣������Ѿ�����HTTPS֤�飬��ô��������֤�����ɵĻ��ڡ����û�У����Բο����²���

### ����֤��

#### 1��������Ŀ¼���֤�顣

```bash
mkdir cert
cd cert
```

#### 2������˽Կ��

```
openssl genrsa -out chyingp-key.pem 2048
```

#### 3������֤��ǩ������csr�� Certificate Signing Request����˼����

```
openssl req -new \
  -sha256
  -key chyingp-key.key.pem \
  -out chyingp-csr.pem \
  -subj "/C=CN/ST=Guandong/L=Shenzhen/O=YH Inc/CN=www.chyingp.com"
```

#### 4������֤�顣

```
openssl x509 \
  -req -in chyingp-csr.pem \
  -signkey chyingp-key.pem \
  -out chyingp-cert.pem
```

### HTTPS�����

�������£�

```js
var https = require('https');
var fs = require('fs');

var options = {
    key: fs.readFileSync('./cert/chyingp-key.pem'), // ˽Կ
    cert: fs.readFileSync('./cert/chyingp-cert.pem') // ֤��
};

var server = https.createServer(options, function(req, res){
    res.end('��������HTTPS�������ķ���');
});

server.listen(3000);
```

�����Ҳ�û�� www.chyingp.com ������������������ñ���host

```
127.0.0.1 www.chyingp.com
```

�������񣬲������������� [http://www.chyingp.com:3000](http://www.chyingp.com:3000)��ע�⣬���������ʾ��֤�鲻�ɿ������ ���β��������� �����ˡ�

## �������ӣ����ʰ�ȫ֤�鲻�����ε���վ

������������ϲ����12306��Ϊ���ӡ�������ͨ�������������12306�Ĺ�Ʊҳ�� https://kyfw.12306.cn/otn/regist/init ʱ��chrome����ֹ���Ƿ��ʣ�������Ϊ��12306��֤�����Լ��䷢�ģ�chrome�޷�ȷ�����İ�ȫ�ԡ�

��������������������´���ʽ��

1. ֹͣ���ʣ��ż���Ʊ�ؼҹ���������ʾ�޷����ܡ�
2. ���Ӱ�ȫ���棬�������ʣ��󲿷�����£�������ǻ���еģ�������ȫ��ʾ���ڡ�
3. ����12306��CA��֤�飺������ԹԾͷ�����Ϊ�����ǰ�ȫ�ġ���ʵ���ϻ����а�ȫ��ʾ����Ϊ12306�õ�ǩ���㷨��ȫ���𲻹���

### ���ӣ�������ȫ����

ͬ���ģ�ͨ�� node https client ��������Ҳ������ͬ�����⡣��������ʵ�飬�������£�

```js
var https = require('https');

https.get('https://kyfw.12306.cn/otn/regist/init', function(res){   
    res.on('data', function(data){
        process.stdout.write(data);
    });
}).on('error', function(err){
    console.error(err);
});
```

����������룬�õ�����Ĵ�����ʾ����˼�� ��ȫ֤�鲻�ɿ����ܾ��������ʡ�

```bash
{ Error: self signed certificate in certificate chain
    at Error (native)
    at TLSSocket.<anonymous> (_tls_wrap.js:1055:38)
    at emitNone (events.js:86:13)
    at TLSSocket.emit (events.js:185:7)
    at TLSSocket._finishInit (_tls_wrap.js:580:8)
    at TLSWrap.ssl.onhandshakedone (_tls_wrap.js:412:38) code: 'SELF_SIGNED_CERT_IN_CHAIN' }
```

ps��������Ϊ����Ĵ�����ʾ�е����ˣ�12306��վ��֤�鲢������ǩ���ģ�ֻ�Ƕ�֤��ǩ����CA��12306�Լҵģ����ڿ����б�����ѡ���ǩ��֤�飬���Լ�CAǩ����֤�黹�ǲ�һ���ġ�

���������������ʣ����ǿ��Բ�ȡ���´���

1. �����飺���԰�ȫ���棬�������ʣ�
2. ���飺��12306��CA���������б�

### ����1�����԰�ȫ���棬��������

�ǳ��򵥣��� rejectUnauthorized ����Ϊ false ���У��ٴ����д��룬�Ϳ������ķ���ҳ���ˡ�

```js
// ���ӣ����԰�ȫ����
var https = require('https');

var options = { 
    hostname: 'kyfw.12306.cn',
    path: '/otn/leftTicket/init',
    rejectUnauthorized: false  // ���԰�ȫ����
};

var req = https.get(options, function(res){ 
    res.pipe(process.stdout);   
});

req.on('error', function(err){
    console.error(err.code);
});
```

### ����2����12306��CA���������б�

�������3�����裺

1. ���� 12306 ��CA֤��
2. ��der��ʽ��CA֤�飬ת��pem��ʽ
3. �޸�node https������

#### 1������ 12306 ��CA֤��

��12306�Ĺ����ϣ��ṩ��CA֤���[���ص�ַ](http://www.12306.cn/mormhweb/ggxxfw/wbyyzj/201106/srca12306.zip)���������浽���أ�����Ϊ srca.cer��

#### 2����der��ʽ��CA֤�飬ת��pem��ʽ

https��ʼ��clientʱ���ṩ�� ca �����������Խ� 12306 ��CA֤����ӽ�ȥ��������� 12306 ����վʱ��client�ͻ���ca��������� ca ֤�飬�Ե�ǰ��֤�����У�飬���Ǿ�У��ͨ���ˡ�

��Ҫע����ǣ�ca ������ֻ֧�� pem ��ʽ������12306�������ص���der��ʽ�ġ���Ҫת���¸�ʽ�����á����� pem��der�����𣬿ɲο� [����](https://support.ssl.com/Knowledgebase/Article/View/19/0/der-vs-crt-vs-cer-vs-pem-certificates-and-how-to-convert-them)��

```bash
openssl x509 -in srca.cer -inform der -outform pem -out srca.cer.pem
```

#### 3���޸�node https������

�޸ĺ�Ĵ������£����ڿ������ķ���12306�ˡ�

```js
// ���ӣ���12306��CA֤�飬�������ǵ������б���
var https = require('https');
var fs = require('fs');
var ca = fs.readFileSync('./srca.cer.pem');

var options = { 
  hostname: 'kyfw.12306.cn',
  path: '/otn/leftTicket/init',
  ca: [ ca ]
};

var req = https.get(options, function(res){ 
  res.pipe(process.stdout); 
});

req.on('error', function(err){
  console.error(err.code);
});
```

## �������

[Why is my node.js SSL connection failing to connect?](http://www.thedreaming.org/2016/09/27/nodejs-ssl/)

[DER vs. CRT vs. CER vs. PEM Certificates and How To Convert Them](https://support.ssl.com/Knowledgebase/Article/View/19/0/der-vs-crt-vs-cer-vs-pem-certificates-and-how-to-convert-them)

[Painless Self Signed Certificates in node.js](https://github.com/Daplie/node-ssl-root-cas/wiki/Painless-Self-Signed-Certificates-in-node.js)

[����OpenSSL������ǩ����SSL֤�鱸�����Խ�ca��](http://wangye.org/blog/archives/732/)

[OpenSSL �� SSL ����֤�������](http://seanlook.com/2015/01/15/openssl-certificate-encryption/)

[��ǩ��֤���˽��CAǩ����֤������� ������ǩ��֤�� ����˽��CA ֤������ ֤����չ��](http://blog.csdn.net/sdcxyz/article/details/47220129)

[��Щ֤����ص������(SSL,X.509,PEM,DER,CRT,CER,KEY,CSR,P12��)](http://www.cnblogs.com/guogangj/p/4118605.html)