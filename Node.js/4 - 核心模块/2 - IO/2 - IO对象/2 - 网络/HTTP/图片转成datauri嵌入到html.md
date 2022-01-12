## ���⣺��ͼƬת��datauri

���죬��QQȺ�и�Ⱥ�����˸����⣺��nodejs��ȡͼƬ��ת��base64����ô��ȡ�أ��� ����һ�£������ʵ�Ӧ���� ��ô����ͼƬǶ�뵽��ҳ��ȥ������ΰ�ͼƬת�ɶ�Ӧ�� datauri��

�Ǹ���������⣬����Ҳ�Ǹ��ܳ��õĹ��ܡ�����ʵ���˸��򵥵�demo������˳���¼һ�¡�

## ʵ��˼·

˼·��ֱ�ۣ�1����ȡͼƬ���������� -> 2��ת��base64�ַ��� -> 3��ת��datauri��

����base64�Ľ��ܣ����Բο���һ����ʦ��[����](http://www.ruanyifeng.com/blog/2008/06/base64.html)���� datauri �ĸ�ʽ����

>data:[<mediatype>][;base64],<data>

���嵽pngͼƬ��������£����� ��xxx�� ����ǰ���base64�ַ����ˡ������������ǿ�����nodejs������ʵ��

>data: image/png;base64, xxx

## ����ʵ��

���ȣ���ȡ����ͼƬ���������ݡ�

```js
var fs = require('fs');
var filepath = './1.png';

var bData = fs.readFileSync(filepath);
```

Ȼ�󣬽�����������ת����base64������ַ�����

```js
var base64Str = bData.toString('base64');
```

���ת����datauri�ĸ�ʽ��

```js
var datauri = 'data:image/png;base64,' + base64Str;
```

�������Ӵ������£�����ǳ��٣�

```js
var fs = require('fs');
var filepath = './1.png';

var bData = fs.readFileSync(filepath);
var base64Str = bData.toString('base64');
var datauri = 'data:image/png;base64,' + base64Str;

console.log(datauri);
```

## github demo��ַ

demo��ַ��[�������](https://github.com/chyingp/nodejs-learning-guide/tree/master/examples/2016.11.15-base64-datauri)������

```bash
git clone https://github.com/chyingp/nodejs-learning-guide.git
cd nodejs-learning-guide/examples/2016.11.15-base64-datauri
node server.js
```

Ȼ������������� [http://127.0.0.1:3000](http://127.0.0.1:3000)���Ϳ��Կ���Ч�� :)

## �������

Base64�ʼǣ�http://www.ruanyifeng.com/blog/2008/06/base64.html
Data URIs��https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/Data_URIs