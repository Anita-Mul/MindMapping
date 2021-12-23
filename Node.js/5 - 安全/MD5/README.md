## ���

MD5��Message-Digest Algorithm���Ǽ������ȫ����㷺ʹ�õ�ɢ�к������ֳƹ�ϣ�㷨��ժҪ�㷨������Ҫ����ȷ����Ϣ��������һ���ԡ�������Ӧ�ó��������뱣���������ļ�У��ȡ�

�����ȶ�MD5���ص���Ӧ�ý��м�Ҫ�����������ص����MD5�����뱣�������µ�Ӧ�ã����ͨ�����Ӷ�MD5��ײ���м򵥽��ܡ�

## �ص�

1. �����ٶȿ죺��`jquery.js`��md5ֵ��57254���ַ�����ʱ1.907ms
2. ������ȹ̶������볤�Ȳ��̶���������ȹ̶���128λ����
3. ���㲻���棺��֪������������£��޷�ͨ��ͨ��������õ�ԭʼ�ַ�����
4. �߶���ɢ�������΢С�仯���ɵ�������������޴�
5. ����ײ�ԣ���ͬ�����ɢ��ֵ������ͬ��

## Ӧ�ó���

1. �ļ�������У�飺�������������һ�������һ����վ���Ὣ�����md5ֵ������ҳ�ϣ��û�����������󣬿ɶ����ص����ص��������md5���㣬Ȼ�����վ�ϵ�md5ֵ���жԱȣ�ȷ�����ص�����������ģ�����ȷ�ģ�
2. ���뱣������md5������뱣�浽���ݿ⣬�����Ǳ����������룬�����Ͽ���¼�����������������й��
3. ���۸ģ���������֤��ķ��۸ģ����õ���ժҪ�㷨������Ȼ��Ҫ�������ǩ�����ֶΣ�

## nodejs��md5���������

��nodejs�У�`crypto`ģ���װ��һϵ������ѧ��صĹ��ܣ�����ժҪ���㡣�����������£��ǳ��򵥣�

```js
var crypto = require('crypto');
var md5 = crypto.createHash('md5');

var result = md5.update('a').digest('hex');

// �����0cc175b9c0f1b6a831c399e269772661
console.log(result);
```

## ���ӣ����뱣��

ǰ���ᵽ�����������뱣�浽���ݿ��Ǻܲ���ȫ�ģ����ҲҪ����md5����б��档�����û�������`123456`��md5���к󣬵õ�`�����e10adc3949ba59abbe56e057f20f883e`��

���������������ô���

1. ���ڲ���������վ����Ҳ��֪���û����������룬������վ���������û���������ɻ��¡�
2. ���ⲿ����������վ���ڿ����֣��ڿ�Ҳֻ���õ�md5������룬�������û����������롣

ʾ���������£�

```javascript
var crypto = require('crypto');

function cryptPwd(password) {
    var md5 = crypto.createHash('md5');
    return md5.update(password).digest('hex');
}

var password = '123456';
var cryptedPassword = cryptPwd(password);

console.log(cryptedPassword);
// �����e10adc3949ba59abbe56e057f20f883e
```

### �������������md5����ȫ

ǰ���ᵽ��ͨ�����û��������md5��������߰�ȫ�ԡ���ʵ���ϣ������İ�ȫ���Ǻܲ�ģ�Ϊʲô�أ�

��΢�޸�����������ӣ�������������ˡ���ͬ���������룬md5ֵҲ����ͬ�ġ�

```javascript
var crypto = require('crypto');

function cryptPwd(password) {
    var md5 = crypto.createHash('md5');
    return md5.update(password).digest('hex');
}

var password = '123456';

console.log( cryptPwd(password) );
// �����e10adc3949ba59abbe56e057f20f883e

console.log( cryptPwd(password) );
// �����e10adc3949ba59abbe56e057f20f883e
```

Ҳ����˵����������֪���㷨��md5�������ݿ���洢������ֵΪ`e10adc3949ba59abbe56e057f20f883e`ʱ�������Ͽ��Կ��Բµ����û��������������`123456`��

��ʵ�ϣ��ʺ�������ô���б����ƽ�ģ����Ƚ��������������md5ֵ����ô�������Ȼ�����վ���ݿ���洢���������ƥ�䣬���ܹ������ҵ��û����������롣�����ﲻ̽������ϸ�ڣ�

��ô����ʲô�취���Խ�һ��������ȫ���أ����ǣ�������Ρ�

## �������

�����Ρ�����ʿ���ȥ����������ʵԭ��ܼ򵥣������������ض�λ�ò����ض��ַ������ٶ��޸ĺ���ַ�������md5���㡣

�������¡�ͬ�������룬�����Ρ�ֵ��һ��ʱ��md5ֵ�Ĳ���ǳ���ͨ��������Σ����Է�ֹ������ı����ƽ⣬������������Ȳ�֪�����Ρ�ֵ���ƽ���ѶȾͻ�ǳ���

```javascript
var crypto = require('crypto');

function cryptPwd(password, salt) {
    // ���롰���Ρ�
    var saltPassword = password + ':' + salt;
    console.log('ԭʼ���룺%s', password);
    console.log('���κ�����룺%s', saltPassword);

    // ���������md5ֵ
    var md5 = crypto.createHash('md5');
    var result = md5.update(saltPassword).digest('hex');
    console.log('���������md5ֵ��%s', result);
}

cryptPwd('123456', 'abc');
// �����
// ԭʼ���룺123456
// ���κ�����룺123456:abc
// ���������md5ֵ��51011af1892f59e74baf61f3d4389092

cryptPwd('123456', 'bcd');
// �����
// ԭʼ���룺123456
// ���κ�����룺123456:bcd
// ���������md5ֵ��55a95bcb6bfbaef6906dbbd264ab4531
```

## ������Σ������ֵ

ͨ��������Σ�����İ�ȫ���Ѿ�����˲��١�����ʵ��������Ӵ��ڲ������⡣

�����ַ���ƴ���㷨����ֵ����й������Ĵ������ٴ����������⣺

1. ����ֵ����Ҫ��ٵĿ����Խ��٣����ױ����ƽ⣬һ����ó���ֵ�������
2. ��ֵ�̶������Ƶģ�������ֻ��Ҫ�ѳ�������+��ֵ��hashֵ��������������´��ˡ�

����ֵ�Բ���˵��Ӧ�ñ��⡣����Ϊʲô��Ӧ��ʹ�ù̶���ֵ��������Ҫ�����һ�¡��ܶ�ʱ�����ǵ���ֵ��Ӳ���뵽���ǵĴ�����ģ����������ļ�����һ������ͨ��ĳ���ֶλ�֪����ֵ����ô��ֻ��Ҫ����⴮�̶�����ֵ���б�����پ����ˡ�

��������Ĵ��룬����֪����ֵ��`abc`ʱ�����̾��ܲµ�`51011af1892f59e74baf61f3d4389092`��Ӧ������������`123456`��

��ô������ô�Ż��أ����ǣ������ֵ��

ʾ���������¡����Կ���������ͬ����123456�����ڲ����������ֵ��ǰ������ó��Ľ���ǲ�ͬ�ġ����������ĺô��ǣ�����û���ͬ�������룬��������Ҫ���ж��������ܹ���ȫ�ƽ⡣ͬ���Ǵ�����3λ����ֵ�������ֵ�ƽ���������������ǹ̶���ֵ��1000����

```javascript
var crypto = require('crypto');

function getRandomSalt(){
    return Math.random().toString().slice(2, 5);
}

function cryptPwd(password, salt) {
    // ���롰���Ρ�
    var saltPassword = password + ':' + salt;
    console.log('ԭʼ���룺%s', password);
    console.log('���κ�����룺%s', saltPassword);

    // ���������md5ֵ
    var md5 = crypto.createHash('md5');
    var result = md5.update(saltPassword).digest('hex');
    console.log('���������md5ֵ��%s', result);
}

var password = '123456';

cryptPwd('123456', getRandomSalt());
// �����
// ԭʼ���룺123456
// ���κ�����룺123456:498
// ���������md5ֵ��af3b7d32cc2a254a6bf1ebdcfd700115

cryptPwd('123456', getRandomSalt());
// �����
// ԭʼ���룺123456
// ���κ�����룺123456:287
// ���������md5ֵ��65d7dd044c2db64c5e658d947578d759
```

## MD5��ײ

�򵥵�˵���������β�ͬ���ַ���������MD5����󣬵ó���ͬ�Ľ����

�����в������ӣ�����Ͳ�׸����ֱ�������ӣ��ο�(����)[http://www.mscs.dal.ca/~selinger/md5collision/]

```javascript
function getHashResult(hexString){

    // ת��16���ƣ����� 0x4d 0xc9 ...
    hexString = hexString.replace(/(\w{2,2})/g, '0x$1 ').trim();

    // ת��16�������飬�� [0x4d, 0xc9, ...]
    var arr = hexString.split(' ');

    // ת�ɶ�Ӧ��buffer���磺<Buffer 4d c9 ...>
    var buff = Buffer.from(arr);

    var crypto = require('crypto');
    var hash = crypto.createHash('md5');

    // ����md5ֵ
    var result = hash.update(buff).digest('hex');

    return result;  
}

var str1 = 'd131dd02c5e6eec4693d9a0698aff95c2fcab58712467eab4004583eb8fb7f8955ad340609f4b30283e488832571415a085125e8f7cdc99fd91dbdf280373c5bd8823e3156348f5bae6dacd436c919c6dd53e2b487da03fd02396306d248cda0e99f33420f577ee8ce54b67080a80d1ec69821bcb6a8839396f9652b6ff72a70';
var str2 = 'd131dd02c5e6eec4693d9a0698aff95c2fcab50712467eab4004583eb8fb7f8955ad340609f4b30283e4888325f1415a085125e8f7cdc99fd91dbd7280373c5bd8823e3156348f5bae6dacd436c919c6dd53e23487da03fd02396306d248cda0e99f33420f577ee8ce54b67080280d1ec69821bcb6a8839396f965ab6ff72a70';

var result1 = getHashResult(str1);
var result2 = getHashResult(str2);

if(result1 === result2) {
    console.log(`Got the same md5 result: ${result1}`);
}else{
    console.log(`Not the same md5 result`);
}
```

## �������

MD5��ײ��һЩ����
http://www.jianshu.com/p/c9089fd5b1ba

MD5 Collision Demo
http://www.mscs.dal.ca/~selinger/md5collision/

Free Password Hash Cracker
https://crackstation.net/
