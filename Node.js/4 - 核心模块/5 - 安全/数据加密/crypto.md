## д��ǰ��

���½�д�ò���ˣ���������Ҫ������һ�£�TODO����

## hash����

hash.digest([encoding])������ժҪ��encoding������`hex`��`latin1`����`base64`�����������encoding����ô�����ַ��������򣬷���Bufferʵ����ע�⣬����hash.digest()��hash����������ˣ��ٴε��þͻ����

hash.update(data[, input_encoding])��input_encoding������`utf8`��`ascii`����`latin1`�����data���ַ�������û��ָ�� input_encoding����Ĭ����`utf8`��ע�⣬hash.update()�������Ե��ö�Ρ�

```js
var crypto = require('crypto');
var fs = require('fs');

var content = fs.readFileSync('./test.txt', {encoding: 'utf8'});
var hash = crypto.createHash('sha256');
var output;

hash.update(content);

output = hash.digest('hex'); 

console.log(output);
// �������Ϊ��
// b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9
```

Ҳ����������

```js
var crypto = require('crypto');
var fs = require('fs');

var input = fs.createReadStream('./test.txt', {encoding: 'utf8'});
var hash = crypto.createHash('sha256');

hash.setEncoding('hex');

input.pipe(hash).pipe(process.stdout)

// �������Ϊ��
// b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9
```

hash.digest()���ٴε���digest()����update()

```js
var crypto = require('crypto');
var fs = require('fs');

var content = fs.readFileSync('./test.txt', {encoding: 'utf8'});
var hash = crypto.createHash('sha256');
var output;

hash.update(content);
hash.digest('hex'); 

// ����Error: Digest already called
hash.update(content);

// ����Error: Digest already called
hash.digest('hex');
```

## HMAC����

HMAC��ȫ����Hash-based Message Authentication Code��Ҳ����hash�ļ������㡣

�㷨ϸ�ڿ��Բο���¼���ӣ����嵽ʹ�õĻ�����hashģ���࣬ѡ��hash�㷨��ָ�����Ρ����ɡ�

����1��

```js
var crypto = require('crypto');
var fs = require('fs');

var secret = 'secret';
var hmac = crypto.createHmac('sha256', secret);
var input = fs.readFileSync('./test.txt', {encoding: 'utf8'});

hmac.update(input);

console.log( hmac.digest('hex') );
// �����
// 734cc62f32841568f45715aeb9f4d7891324e6d948e4c6c60c0621cdac48623a
```

����2��

```js
var crypto = require('crypto');
var fs = require('fs');

var secret = 'secret';
var hmac = crypto.createHmac('sha256', secret);
var input = fs.createReadStream('./test.txt', {encoding: 'utf8'});

hmac.setEncoding('hex');

input.pipe(hmac).pipe(process.stdout)
// �����
// 734cc62f32841568f45715aeb9f4d7891324e6d948e4c6c60c0621cdac48623a
```

## ����/����

�ӽ�����Ҫ�õ��������鷽����

���ܣ�

* crypto.createCipher(algorithm, password)
* crypto.createCipheriv(algorithm, key, iv)

���ܣ�

* crypto.createDecipher(algorithm, password)
* crypto.createDecipheriv(algorithm, key, iv)

### crypto.createCipher(algorithm, password)

�������� crypto.createCipher(algorithm, password)�����������ֱ��Ǽ����㷨������

* algorithm�������㷨������`aes192`����������Щ��ѡ���㷨�������ڱ���`openssl`�İ汾������ͨ��`openssl list-cipher-algorithms`����鿴֧����Щ�㷨��
* password������������Կ(key)����ʼ������(IV)��

��ע������nodejs������AES��ʹ��/ʵ��ϸ�ڣ�����key��IV������Ȥ��ͬѧ�������йȸ��¡�

```js
var crypto = require('crypto');
var secret = 'secret';

var cipher = crypto.createCipher('aes192', secret);
var content = 'hello';
var cryptedContent;

cipher.update(content);
cryptedContent = cipher.final('hex');
console.log(cryptedContent);
// �����
// 71d30ec9bc926b5dbbd5150bf9d3e5fb
```

### crypto.createDecipher(algorithm, password)

���Կ��� crypto.createCipher(algorithm, password) ���������ֱ�ӿ�����

```js
var crypto = require('crypto');
var secret = 'secret';

var cipher = crypto.createCipher('aes192', secret);
var content = 'hello';
var cryptedContent;

cipher.update(content);
cryptedContent = cipher.final('hex');
console.log(cryptedContent);
// �����
// 71d30ec9bc926b5dbbd5150bf9d3e5fb

var decipher = crypto.createDecipher('aes192', secret);
var decryptedContent;

decipher.update(cryptedContent, 'hex');
decryptedContent = decipher.final('utf8');
console.log(decryptedContent);
// �����
// hello
```

### crypto.createCipheriv(algorithm, key, iv)

����� crypto.createCipher() ��˵��crypto.createCipheriv() ��Ҫ�ṩ`key`��`iv`���� crypto.createCipher() �Ǹ����û��ṩ�� password ������ġ�

key��iv ������Buffer��Ҳ������utf8������ַ�����������Ҫ��ע�������ǵĳ��ȣ�

* key������ѡ����㷨�йأ����� aes128��aes192��aes256�����ȷֱ���128��192��256λ��16��24��32�ֽڣ�
* iv������128λ��16�ֽڣ�

```js
var crypto = require('crypto');
var key = crypto.randomBytes(192/8);
var iv = crypto.randomBytes(128/8);
var algorithm = 'aes192';

function encrypt(text){
    var cipher = crypto.createCipheriv(algorithm, key, iv);
    cipher.update(text);
    return cipher.final('hex');
}

function decrypt(encrypted){
    var decipher = crypto.createDecipheriv(algorithm, key, iv);
    decipher.update(encrypted, 'hex');
    return decipher.final('utf8');
}

var content = 'hello';
var crypted = encrypt('hello');
console.log( crypted );

var decrypted = decrypt( crypted );
console.log( decrypted );  // �����utf8
```

## ����ǩ��/ǩ��У��

���裺

1�������ԭʼ��ϢΪM��ժҪ�㷨ΪHash��Hash(M)�ó���ժҪ��H��
2����ԿΪPub��˽ԿΪPiv���ǶԳƼ����㷨ΪEncrypt���ǶԳƽ����㷨ΪDecrypt��
3��Encrypt(H)�õ��Ľ����S��
4���ͻ����õ�����ϢΪM1������Hash(M1)�ó��Ľ����H1��

����ǩ���Ĳ�����У�鲽��ֱ����£�

1������ǩ���Ĳ������裺����ժҪ�㷨Hash���M��ժҪ����Hash(M) == H�����÷ǶԳƼ����㷨��ժҪ���м���Encrypt( H, Piv )���õ�����ǩ��S��
2������ǩ����У�鲽�裺���ý����㷨D������ǩ�����н��ܣ���Decrypt(S) == H������M1��ժҪ Hash(M1) == H1���Ա� H��H1�����������ͬ����ͨ��У�顣

˽Կ������ɲ���������ص㣬����������ϵķ��������ɣ����[����](�������ɷǶԳƼ��ܹ�Կ˽Կ�ԡ��������ɹ�˽Կ�ԡ�RSA Key pair create������RSA��Կ��)��

�˽�������ǩ��������У���ԭ�����������Ĵ����������⣺

```js
var crypto = require('crypto');
var fs = require('fs');
var privateKey = fs.readFileSync('./private-key.pem');  // ˽Կ
var publicKey = fs.readFileSync('./public-key.pem');  // ��Կ
var algorithm = 'RSA-SHA256';  // �����㷨 vs ժҪ�㷨

// ����ǩ��
function sign(text){
    var sign = crypto.createSign(algorithm);
    sign.update(text);
    return sign.sign(privateKey, 'hex');    
}

// У��ǩ��
function verify(oriContent, signature){
    var verifier = crypto.createVerify(algorithm);
    verifier.update(oriContent);
    return verifier.verify(publicKey, signature, 'hex');
}

// �����ݽ���ǩ��
var content = 'hello world';
var signature = sign(content);
console.log(signature);

// У��ǩ�������ͨ��������true
var verified = verify(content, signature);
console.log(verified);
```

## DiffieHellman

DiffieHellman��Diffie�CHellman key exchange����дΪD-H����һ�ְ�ȫЭ�飬��ͨ��˫����Ԥ��û�жԷ���Ϣ������£�ͨ������ȫͨ���ŵ�������һ����Կ�������Կ�����ں�����ͨ���У���Ϊ�ԳƼ��ܵ���Կ���ܴ��ݵ���Ϣ��

�������£�ԭ������� TODO

```js
const crypto = require('crypto');
const assert = require('assert');

// Generate Alice's keys...
const alice = crypto.createDiffieHellman(2048);
const alice_key = alice.generateKeys();

// Generate Bob's keys...
const bob = crypto.createDiffieHellman(alice.getPrime(), alice.getGenerator());
const bob_key = bob.generateKeys();

// Exchange and generate the secret...
const alice_secret = alice.computeSecret(bob_key);
const bob_secret = bob.computeSecret(alice_key);

// OK
assert.equal(alice_secret.toString('hex'), bob_secret.toString('hex'));
```

## ECDH��Elliptic Curve Diffie-Hellman 

�������£�ԭ������� TODO

```js
const crypto = require('crypto');
const assert = require('assert');

// Generate Alice's keys...
const alice = crypto.createECDH('secp521r1');
const alice_key = alice.generateKeys();

// Generate Bob's keys...
const bob = crypto.createECDH('secp521r1');
const bob_key = bob.generateKeys();

// Exchange and generate the secret...
const alice_secret = alice.computeSecret(bob_key);
const bob_secret = bob.computeSecret(alice_key);

assert(alice_secret, bob_secret);
  // OK
```

## ֤��

SPKAC��

>SPKAC is an acronym that stands for Signed Public Key and Challenge, also known as Netscape SPKI.

SPKI��Simple public-key infrastructure

## �ؼ���

md5���̶����ȣ�128bit���������棨��Ҫ������ͬ���ݵ�ɢ��ֵ������ͬ����Ҫ�����߶���ɢ�ͣ�ԭ��ϸ΢�ı仯���ᵼ��ɢ��ֵ����޴�


sha1���̶�����160bit���㷺ʹ�ã���TLS��Ŀǰ��ȫ���ܵ�����ѧ�ҵ����ɣ�

SHA-256/SHA-384/SHA-512�������ʾժҪ�ĳ��ȡ�

��;������ǩ�����ļ�������У��

��ϵ��sha1 ���� MD5��MD5 ���� MD4

md5(1991) -> SHA1

sha���壺���������Ұ�ȫ�֣�NSA������ƣ������������ұ�׼�뼼���о�Ժ��NIST����������������������׼��

## �������

SPKAC��Signed Public Key and Challenge

MD5��Message-Digest Algorithm 5����Ϣ-ժҪ�㷨��

SHA��Secure Hash Algorithm����ȫɢ���㷨��

HMAC��Hash-based Message Authentication Code����Կ��صĹ�ϣ������Ϣ��֤�롣

SPKAC��

�ԳƼ��ܣ�����AES��DES

�ǶԳƼ��ܣ�����RSA��DSA

AES��Advanced Encryption Standard���߼����ܱ�׼������Կ���ȿ�����128��192��256λ��

DES��Data Encryption Standard�����ݼ��ܱ�׼���Գ���Կ�����㷨��������Ϊ����ȫ����https://en.wikipedia.org/wiki/Data_Encryption_Standard

DiffieHellman��Diffie�CHellman key exchange����дΪD-H����һ�ְ�ȫЭ�飬��ͨ��˫����Ԥ��û�жԷ���Ϣ������£�ͨ������ȫͨ���ŵ�������һ����Կ�������Կ�����ں�����ͨ���У���Ϊ�ԳƼ��ܵ���Կ���ܴ��ݵ���Ϣ������ע��ʹ����Э��ķ�����������

## �������

�ַ�����ʼǣ�ASCII��Unicode��UTF-8 - ��һ���������־
http://www.ruanyifeng.com/blog/2007/10/ascii_unicode_and_utf-8.html

Unicode��JavaScript���
http://www.ruanyifeng.com/blog/2014/12/unicode.html

Base64�ʼ�
http://www.ruanyifeng.com/blog/2008/06/base64.html

MIME�ʼ�
http://www.ruanyifeng.com/blog/2008/06/mime.html

SHA����
https://zh.wikipedia.org/wiki/SHA%E5%AE%B6%E6%97%8F

���������ϣ�������ȷʹ��
http://blog.jobbole.com/61872/

HMAC-MD5�㷨ԭ��ʵ��
http://www.jianshu.com/p/067f9eb6b252

Encrypting using AES-256, can I use 256 bits IV?
http://security.stackexchange.com/questions/90848/encrypting-using-aes-256-can-i-use-256-bits-iv

����ԳƼ���ģʽ:ECB/CBC/CFB/OFB
http://blog.csdn.net/aaaaatiger/article/details/2525561

�������ɷǶԳƼ��ܹ�Կ˽Կ�ԡ��������ɹ�˽Կ�ԡ�RSA Key pair create������RSA��Կ��
http://web.chacuo.net/netrsakeypair

Diffie�CHellman key exchange
https://zh.wikipedia.org/wiki/%E8%BF%AA%E8%8F%B2-%E8%B5%AB%E7%88%BE%E6%9B%BC%E5%AF%86%E9%91%B0%E4%BA%A4%E6%8F%9B

��� Deffie-Hellman ��Կ�����㷨
http://wsfdl.com/algorithm/2016/02/04/%E7%90%86%E8%A7%A3Diffie-Hellman%E5%AF%86%E9%92%A5%E4%BA%A4%E6%8D%A2%E7%AE%97%E6%B3%95.html

What is the difference between DHE and ECDH?
http://stackoverflow.com/questions/2701294/how-does-the-elliptic-curve-version-of-diffie-hellman-cryptography-work?rq=1

Example application for working with SPKAC (signed public key & challege) data coming from the <keygen> element.
https://github.com/jas-/node-spkac

Using Padding in Encryption
http://www.di-mgt.com.au/cryptopad.html#randompadding

�ԳƼ��ܺͷ�������е�����ģʽ(ECB��CBC��CFB��OFB)
http://www.cnblogs.com/happyhippy/archive/2006/12/23/601353.html

�������빤��ģʽ
https://zh.wikipedia.org/wiki/%E5%88%86%E7%BB%84%E5%AF%86%E7%A0%81%E5%B7%A5%E4%BD%9C%E6%A8%A1%E5%BC%8F#.E5.AF.86.E7.A0.81.E5.9D.97.E9.93.BE.E6.8E.A5.EF.BC.88CBC.EF.BC.89

Ϊʲô˵��������ģʽ�Ѿ�ɥʧ��ȫ�ԣ�
https://www.zhihu.com/question/26437065

Elliptic Curve Cryptography: a gentle introduction
http://andrea.corbellini.name/2015/05/17/elliptic-curve-cryptography-a-gentle-introduction/

Elliptic Curve Cryptography: ECDH and ECDSA
http://andrea.corbellini.name/2015/05/30/elliptic-curve-cryptography-ecdh-and-ecdsa/

ΪʲôRSA��Կÿ�μ��ܵõ��Ľ������һ����
http://blog.csdn.net/guyongqiangx/article/details/74930951