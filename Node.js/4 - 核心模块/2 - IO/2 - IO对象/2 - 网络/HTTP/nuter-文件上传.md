## ��������

����ԳС����ǰ��ѶIMWEB�Ŷӳ�Ա��������������ר����֤��������ӭ���� Expressǰ�˽���Ⱥ(197339705)��

������ӣ�[��Nodejsѧϰ�ʼǡ�](https://chyingp.gitbooks.io/nodejs/) / [��Expressѧϰ�ʼǡ�](https://www.gitbook.com/book/chyingp/express/details) 

�������ӣ�[��������](https://yq.aliyun.com/users/1970729537231450?spm=5176.100240.searchblog.12.xDc8pM&do=login) / [github](https://github.com/chyingp) / [����΢��](http://weibo.com/chyingp?is_all=1) / [֪��](https://www.zhihu.com/people/chen-ying-ping-57) / [Segmentfault](https://segmentfault.com/u/chyingp) / [����԰](http://chyingp.cnblogs.com/)  / [վ��](http://www.zcool.com.cn/u/346408)

## ����

ͼƬ�ϴ���web�����о����õ��Ĺ��ܣ�node�������ⷽ��Ҳ����������Ƶ�֧�֡�

���õĿ�Դ�����**multer**��**formidable**�ȣ�������������Դ������������ɸ㶨ͼƬ�ϴ���

������Ҫ�����������ݣ������½ڻ�Լ���ʵ��ϸ�ڽ��������ھ򡣱����������Ӿ��д���ʾ��������[����](../examples/2016.11.07-advanced-express-multer/)�鿴��

* �������ӣ�����express��multerʵ�ֵ�ͼ����ͼ�ϴ���
* ����API����ȡ�ϴ���ͼƬ����Ϣ��
* ����ʹ�ã��Զ��屣���ͼƬ·�������ơ�

## ������ʼ��

�ǳ��򵥣�һ�����

```bash
npm install express multer multer --save
```

ÿ��ʾ�����棬�������������ļ�

```bash
?  upload-custom-filename git:(master) ? tree -L 1
.
������ app.js # ����˴��룬���������ļ��ϴ�����
������ form.html # ǰ��ҳ�棬�����ϴ��ļ�
```

## �������ӣ���ͼ�ϴ�

����ʾ��������ο�[����](../examples/2016.11.07-advanced-express-multer/upload-single)��

[app.js](../examples/2016.11.07-advanced-express-multer/upload-single/app.js)��

```javascript
var fs = require('fs');
var express = require('express');
var multer  = require('multer')

var app = express();
var upload = multer({ dest: 'upload/' });

// ��ͼ�ϴ�
app.post('/upload', upload.single('logo'), function(req, res, next){
    res.send({ret_code: '0'});
});

app.get('/form', function(req, res, next){
    var form = fs.readFileSync('./form.html', {encoding: 'utf8'});
    res.send(form);
});

app.listen(3000);

```


[form.html](../examples/2016.11.07-advanced-express-multer/upload-single/form.html)��

```html
<form action="/upload" method="post" enctype="multipart/form-data">
    <h2>��ͼ�ϴ�</h2>
    <input type="file" name="logo">
    <input type="submit" value="�ύ">
</form>
```

���з���

```bash
node app.js
```


���� http://127.0.0.1:3000/form ��ѡ��ͼƬ��������ύ����done��Ȼ����ͻῴ�� upload Ŀ¼�¶��˸�ͼƬ��

## �������ӣ���ͼ�ϴ�

����ʾ��������ο�[����](../examples/2016.11.07-advanced-express-multer/upload-multi)��

�����ֱ���ܸ��򵥣���ǰ��� upload.single('logo') �ĳ� upload.array('logo', 2) ���С���ʾ��ͬʱ֧��2��ͼƬ�ϴ������� name ����Ϊ logo��

[app.js](../examples/2016.11.07-advanced-express-multer/upload-multi/app.js)��

```javascript
var fs = require('fs');
var express = require('express');
var multer  = require('multer')

var app = express();
var upload = multer({ dest: 'upload/' });

// ��ͼ�ϴ�
app.post('/upload', upload.array('logo', 2), function(req, res, next){
    res.send({ret_code: '0'});
});

app.get('/form', function(req, res, next){
    var form = fs.readFileSync('./form.html', {encoding: 'utf8'});
    res.send(form);
});

app.listen(3000);


```


[form.html](../examples/2016.11.07-advanced-express-multer/upload-multi/form.html)��


```html
<form action="/upload" method="post" enctype="multipart/form-data">
    <h2>��ͼ�ϴ�</h2>
    <input type="file" name="logos">
    <input type="file" name="logos">
    <input type="submit" value="�ύ">
</form>
```

ͬ���Ĳ��Բ��裬��׸����

## ��ȡ�ϴ���ͼƬ����Ϣ

����ʾ��������ο�[����](../examples/2016.11.07-advanced-express-multer/upload-get-file-info)��

�ܶ�ʱ�򣬳��˽�ͼƬ�����ڷ������⣬���ǻ���Ҫ���ܶ��������飬���罫ͼƬ����Ϣ�浽���ݿ��

���õ���Ϣ����ԭʼ�ļ������ļ����͡��ļ���С�����ر���·���ȡ�����multer�����ǿ��Ժܷ���Ļ�ȡ��Щ��Ϣ��

���ǵ��ļ��ϴ������ӣ���ʱ��multer�Ὣ�ļ�����Ϣд�� req.file �ϣ����´�����ʾ��


[app.js](../examples/2016.11.07-advanced-express-multer/upload-get-file-info/app.js)��

```javascript
var fs = require('fs');
var express = require('express');
var multer  = require('multer')

var app = express();
var upload = multer({ dest: 'upload/' });

// ��ͼ�ϴ�
app.post('/upload', upload.single('logo'), function(req, res, next){
    var file = req.file;

    console.log('�ļ����ͣ�%s', file.mimetype);
    console.log('ԭʼ�ļ�����%s', file.originalname);
    console.log('�ļ���С��%s', file.size);
    console.log('�ļ�����·����%s', file.path);

    res.send({ret_code: '0'});
});

app.get('/form', function(req, res, next){
    var form = fs.readFileSync('./form.html', {encoding: 'utf8'});
    res.send(form);
});

app.listen(3000);
```


[form.html](../examples/2016.11.07-advanced-express-multer/upload-get-file-info/form.html)��

```html
<form action="/upload" method="post" enctype="multipart/form-data">
    <h2>��ͼ�ϴ�</h2>
    <input type="file" name="logo">
    <input type="submit" value="�ύ">
</form>
```

���������ϴ��ļ��󣬾ͻῴ������̨�´�ӡ������Ϣ��

```bash
�ļ����ͣ�image/png
ԭʼ�ļ�����1.png
�ļ���С��18379
�ļ�����·����upload/b7e4bb22375695d92689e45b551873d9
```


## �Զ����ļ��ϴ�·��������

�е�ʱ��������Ҫ�����ļ��ϴ���·�������ƣ�multerҲ���Է����ʵ�֡�

### �Զ��屾�ر����·��

�ǳ��򵥣����������뽫�ļ��ϴ��� my-upload Ŀ¼�£��޸��� dest ��������С�

```javascript
var upload = multer({ dest: 'upload/' });
```

������������£�������Դ���Ǳ�����ͬ��Ŀ¼�¡���ʱ������Ҫ��Բ�ͬ�ļ����и��Ի����ã���ô�����Բο���һС�ڵ����ݡ�

### �Զ��屾�ر�����ļ���

����ʾ��������ο�[����](../examples/2016.11.07-advanced-express-multer/upload-custom-filename)��

������΢��һ�㣬��ͬ���򵥡�multer �ṩ�� **storage** �������������Դ�����·�����ļ������и��Ի����á�

ʹ��ע���������£�

* destination��������Դ�ı���·����ע�⣬���û����������Ĭ�ϻᱣ���� /tmp/uploads �¡����⣬·����Ҫ�Լ�������
* filename��������Դ�����ڱ��ص��ļ�����

[app.js](../examples/2016.11.07-advanced-express-multer/upload-custom-filename/app.js)��

```javascript
var fs = require('fs');
var express = require('express');
var multer  = require('multer')

var app = express();

var createFolder = function(folder){
    try{
        fs.accessSync(folder); 
    }catch(e){
        fs.mkdirSync(folder);
    }  
};

var uploadFolder = './upload/';

createFolder(uploadFolder);

// ͨ�� filename ���Զ���
var storage = multer.diskStorage({
    destination: function (req, file, cb) {
        cb(null, uploadFolder);    // �����·������ע����Ҫ�Լ�����
    },
    filename: function (req, file, cb) {
        // �������ļ�������Ϊ �ֶ��� + ʱ��������� logo-1478521468943
        cb(null, file.fieldname + '-' + Date.now());  
    }
});

// ͨ�� storage ѡ������ �ϴ���Ϊ ���ж��ƻ�
var upload = multer({ storage: storage })

// ��ͼ�ϴ�
app.post('/upload', upload.single('logo'), function(req, res, next){
    var file = req.file;
    res.send({ret_code: '0'});
});

app.get('/form', function(req, res, next){
    var form = fs.readFileSync('./form.html', {encoding: 'utf8'});
    res.send(form);
});

app.listen(3000);
```

[form.html](../examples/2016.11.07-advanced-express-multer/upload-custom-filename/form.html)��

```html
<form action="/upload" method="post" enctype="multipart/form-data">
    <h2>��ͼ�ϴ�</h2>
    <input type="file" name="logo">
    <input type="submit" value="�ύ">
</form>
```

���Բ��費׸��������һ�¾�֪��Ч���ˡ�

## д�ں���

���Ķ�multer�Ļ����÷������˽��ܣ���δ�漰����ԭ���ԵĶ������׻�˵ **�������治����������**���ں������½������ļ��ϴ���ϸ�ڽ����ھ򣬺��ö������Ѷ��ļ��ϴ������һ������ʶ��


## �������

multer�ٷ��ĵ���https://github.com/expressjs/multer

