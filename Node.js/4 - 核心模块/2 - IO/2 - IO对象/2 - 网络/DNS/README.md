## ����������dns.lookup()

��������Ҫ��ѯ���� www.qq.com ��Ӧ��ip������ͨ�� dns.lookup() ��

```javascript
var dns = require('dns');

dns.lookup('www.qq.com', function(err, address, family){
    if(err) throw err;
    console.log('����A: ' + address);
});
```

������£�

```bash
����A: 182.254.34.74
```

����֪����ͬһ�����������ܶ�Ӧ�����ͬ��ip����ô����λ�ȡһ��������Ӧ�Ķ��ip�أ�����������


```javascript
var dns = require('dns');
var options = {all: true};

dns.lookup('www.qq.com', options, function(err, address, family){
    if(err) throw err;
    console.log('����B: ' + address);
});
```

������£�

```bash
����B: [{"address":"182.254.34.74","family":4},{"address":"240e:e1:8100:28::2:16","family":6}]
```


## ����������dns.resolve4()

���ĵ����ӣ�Ҳ����ͨ�� dns.resolve4() ��ʵ�֡�

```javascript
var dns = require('dns');

dns.resolve4('id.qq.com', function(err, address){
    if(err) throw err;
    console.log( JSON.stringify(address) );
});
```

������£�

```bash
["61.151.186.39","101.227.139.179"]
```

���Ҫ��ȡIPv6�ĵ�ַ���ӿ�Ҳ��࣬��׸����

## dns.lookup()��dns.resolve4()������

������������������������������Բ�ѯ������ip�б���ô�����ǵ�������ʲô�ط��أ�

�������Ĳ�������ڣ��������˱���Hostʱ���Ƿ��Բ�ѯ�������Ӱ�졣

* dns.lookup()����Ӱ�졣
* dns.resolve4()��û��Ӱ�졣

��������hosts�ļ������������¹���

>127.0.0.1 www.qq.com

�������¶Ա�ʾ���ӣ��Ϳ��Կ�������

```javascript
var dns = require('dns');

dns.lookup('www.qq.com', function(err, address, family){
    if(err) throw err;
    console.log('����host��dns.lokup =>' + address);
});

dns.resolve4('www.qq.com', function(err, address, family){
    if(err) throw err;
    console.log('����host��dns.resolve4 =>' + address);
});
```

�������

```bash
?  2016.11.03-node-dns git:(master) ? node lookup-vs-resolve4.js 
����host��dns.resolve4 =>182.254.34.74
����host��dns.lookup =>127.0.0.1
```

## �����ӿ�

��DNS���˽��ͬѧ��Ӧ�ö�A��¼��NS��¼��CNAME�Ȳ�İ����ͬ������ͨ����Ӧ��API���в�ѯ������Ȥ�Ŀ������г����¡�

## �������

�ٷ��ĵ���https://nodejs.org/api/dns.html#dns_dns_resolve4_hostname_callback