## ģ�����

nodejs�У��ṩ��**url**����ǳ�ʵ�õ�ģ�飬������URL�Ľ���������node����˵Ŀ���ʱ�ᾭ���õ���ʹ�úܼ򵥣��ܹ�ֻ��3��������

��ʽ����ǰ����λͬѧ�Ȱ��������ͼ�������ϣ�����nodejs���������ȶ�URL��һ��ֱ�۵���ʶ��

![](/assets/url.png)

## ģ�鷽������

urlģ�����������ֱ��ǣ�

* **.parse\(urlString\)**����url�ַ�����������object�����ڿ����߽��в�����
* **.format\(urlObj\)**��.parse\(\) �����ķ��������
* **.resove\(from, to\)**����from��Ϊ��ʼ��ַ��������������Ŀ���ַ�����ǿ�ֱ�ӿ����Ӻ�Щ��

## url������url.parse\(\)

> �����﷨��url.parse\(urlString\[, parseQueryString\[, slashesDenoteHost\]\]\)

ʹ�ñȽϼ򵥣�����Ҫ�㱸�����¡�

1. **parseQueryString**����Ĭ��Ϊfalse����Ϊfalse����`urlObject.query`Ϊδ�������ַ���������`nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1`���Ҷ�Ӧ��ֵ����decode�����`parseQueryString`Ϊtrue����`urlObject.query`Ϊobject������`{ nick: '����ԳС��' }`����ֵ�ᱻdecode��
2. **slashesDenoteHos**����Ĭ��Ϊfalse�����Ϊtrue����ô����`//foo/bar`���`foo`�ͻᱻ��Ϊ��`hostname`�����Ϊfalse����`foo`����Ϊ��pathname��һ���֡�
3. ���ڽ����õ��� urlObject ��������һС�ڽ�����ϸ���ܡ�

### ����1������ֵ�����н���

�������£�

```javascript
var url = require('url');
var str = 'http://Chyingp:HelloWorld@ke.qq.com:8080/index.html?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1#part=1';

var obj = url.parse(str);
console.log(obj);
```

������£�

```javascript
Url {
  protocol: 'http:',
  slashes: true,
  auth: 'Chyingp:HelloWorld',
  host: 'ke.qq.com:8080',
  port: '8080',
  hostname: 'ke.qq.com',
  hash: '#part=1',
  search: '?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1',
  query: 'nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1',
  pathname: '/index.html',
  path: '/index.html?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1',
  href: 'http://Chyingp:HelloWorld@ke.qq.com:8080/index.html?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1#part=1' }
```

### ����2���Բ���ֵ����decode

�������£�

```javascript
var url = require('url');
var str = 'http://Chyingp:HelloWorld@ke.qq.com:8080/index.html?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1#part=1';

var obj = url.parse(str, true);
console.log(obj);
```

������£��Ա���������ӻᷢ�֣�**query** �ֶα���������object������decode����

```bash
Url {
  protocol: 'http:',
  slashes: true,
  auth: 'Chyingp:HelloWorld',
  host: 'ke.qq.com:8080',
  port: '8080',
  hostname: 'ke.qq.com',
  hash: '#part=1',
  search: '?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1',
  query: { nick: '����ԳС��' },
  pathname: '/index.html',
  path: '/index.html?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1',
  href: 'http://Chyingp:HelloWorld@ke.qq.com:8080/index.html?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1#part=1' }
```

### ����3�����·�� \/\/foo\/bar �Ĵ���

�������£�

```
var url = require('url');
var str = '//foo/bar';

var obj = url.parse(str, true, false);
console.log(obj);

obj = url.parse(str, true, true);
console.log(obj);
```

������£����жԱ�����֮��Ĳ��죺

```bash
Url {
  protocol: null,
  slashes: null,
  auth: null,
  host: null,
  port: null,
  hostname: null,
  hash: null,
  search: '',
  query: {},
  pathname: '//foo/bar',
  path: '//foo/bar',
  href: '//foo/bar' }
Url {
  protocol: null,
  slashes: true,
  auth: null,
  host: 'foo',
  port: null,
  hostname: 'foo',
  hash: null,
  search: '',
  query: {},
  pathname: '/bar',
  path: '/bar',
  href: '//foo/bar' }
```

## ����urlObject

���������Ϊ���ӣ����Խ�����`urlObject`������ϸ�ڿɲο�[�ٷ��ĵ�](https://nodejs.org/api/url.html#url_url_strings_and_url_objects)��

* protocol��Э�飬��Ҫע����ǰ�����`:`��������Сд�ġ�
* slashes�����`:`�����������`//`����ôΪtrue��
* auth����֤��Ϣ����������룬Ϊ`usrname:passwd`�����û�У���Ϊ`usrname`��ע�⣬�������ִ�Сд��
* host����������ע������˶˿ڣ�����`ke.qq.com:8080`��������Сд�ġ�
* hostname�����������������˿ڣ�������Сд�ġ�
* hash����ϣ���֣�ע�������`#`��
* search����ѯ�ַ�����ע�⣬������`?`�����⣬ֵ��û�о���decode�ġ�
* query���ַ��� ���� ����������ַ���������`search`ȥ��`?`������һ��������Ƕ�����ô��decode���ġ�
* path��·�����֣�����search���֡�
* pathname��·�����֣�������search���֡�
* href��ԭʼ�ĵ�ַ��������Ҫע����ǣ�`protocol`��`host`�ᱻת��Сд��ĸ��

```javascript
{
  protocol: 'http:',
  slashes: true,
  auth: 'Chyingp:HelloWorld',
  host: 'ke.qq.com:8080',
  port: '8080',
  hostname: 'ke.qq.com',
  hash: '#part=1',
  search: '?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1',
  query: { nick: '����ԳС��' },
  pathname: '/index.html',
  path: '/index.html?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1',
  href: 'http://Chyingp:HelloWorld@ke.qq.com:8080/index.html?nick=%E7%A8%8B%E5%BA%8F%E7%8C%BF%E5%B0%8F%E5%8D%A1#part=1' }
```

## urlƴ�ӣ�url.format\(urlObject\)

> �����﷨��url.format\(urlObject\)

`url.parse(str)`�ķ��������ûʲô��˵�ġ�`urlObject`�����˺ܶ��ֶΣ�����`protocol`��`slashes`��`protocol`�ȣ��Ҳ�һ����Ҫȫ������������һ�׽����߼���

���̱Ƚ��߳����󲿷�ʱ����Ҫ�õ���ֱ����[�ٷ��ĵ�](https://nodejs.org/api/url.html#url_url_format_urlobject)�����ӣ�����Ҫ�ٿ���

## url.resolve\(from, to\)

�÷��Ƚϼ򵥣�ֱ�����ٷ��ĵ�������

```javascript
url.resolve('/one/two/three', 'four')         // '/one/two/four'
url.resolve('http://example.com/', '/one')    // 'http://example.com/one'
url.resolve('http://example.com/one', '/two') // 'http://example.com/two'
```

## �Ƿ��ַ�ת��

url�ַ������������ַ��ᱻת�壨�Ƿ��ַ���

> &lt; &gt; " \` \r \n \t { } \| \ ^ '

## �������

�ٷ��ĵ���[https:\/\/nodejs.org\/api\/url.html\#url\_url](https://nodejs.org/api/url.html#url_url)

