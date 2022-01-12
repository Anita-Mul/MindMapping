## ģ�����

��nodejs�У��ṩ��**querystring**���ģ�飬������url��ѯ�����Ľ�����ʹ�÷ǳ��򵥡�

ģ���ܹ����ĸ����������󲿷�ʱ������ֻ���õ� **.parse()**�� **.stringify()**����������ʣ��ķ���������Ȥ��ͬѧ�����в鿴�ĵ���

* **.parse()**����url��ѯ�������ַ��������н������������ڷ�����json��ʽ��
* **.stringif()**����**.parse()**�෴������ƴ�Ӳ�ѯ��ѯ��

```javascript
querystring.parse(str[, sep[, eq[, options]]])
querystring.stringify(obj[, sep[, eq[, options]]])
```

## ��ѯ����������querystring.parse()

>������querystring.parse(str[, sep[, eq[, options]]])

���ĸ��������������õ�,ֱ�Ӳ�����. �ڶ���, ��������ʵҲ�����õ�,��ĳЩʱ���ǿ�����һ�¡�ֱ�ӿ�����

```javascript
var querystring = require('querystring');
var str = 'nick=casper&age=24';
var obj = querystring.parse(str);
console.log(JSON.stringify(obj, null, 4));
```

�������

```javascript
{
    "nick": "casper",
    "age": "24"
}
```

��������`sep`��`eq`��ʲô���á��൱�ڿ����滻`&`��`=`Ϊ�Զ����ַ�����������ĳ�����˵����ͦʡ�µġ�

```javascript
var str1 = 'nick=casper&age=24&extra=name-chyingp|country-cn';
var obj1 = querystring.parse(str1);
var obj2 = querystring.parse(obj1.extra, '|', '-');
console.log(JSON.stringify(obj2, null, 4));
```

�������

```javascript
{
    "name": "chyingp",
    "country": "cn"
}
```

## ��ѯ����ƴ�ӣ�querystring.stringify()

>querystring.stringify(obj[, sep[, eq[, options]]])

ûʲô��˵�ģ��൱��`parse`�����������ֱ�ӿ�����

```javascript
var querystring = require('querystring');

var obj1 = {
    "nick": "casper",
    "age": "24"
};
var str1 = querystring.stringify(obj1);
console.log(str1);

var obj2 = {
    "name": "chyingp",
    "country": "cn"
};
var str2 = querystring.stringify(obj2, '|', '-');
console.log(str2);
```

�������

```javascript
nick=casper&age=24
name-chyingp|country-cn
```

## �������

�ٷ��ĵ���https://nodejs.org/api/querystring.html