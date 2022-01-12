## ģ�����

��nodejs�У�path�Ǹ�ʹ��Ƶ�ʺܸߣ���ȴ�����ְ��ֺ޵�ģ�顣������Ϊ�ĵ�˵�Ĳ���������������Ϊ�ӿڵ�ƽ̨�����ԡ�

��path�Ľӿڰ�����;���࣬��ϸ��ĥ��ĥ��Ҳ��û��ô�ѽ��ˡ�

## ��ȡ·��/�ļ���/��չ��

* ��ȡ·����path.dirname(filepath)
* ��ȡ�ļ�����path.basename(filepath)
* ��ȡ��չ����path.extname(filepath)

### ��ȡ����·��

�������£�

```javascript
var path = require('path');
var filepath = '/tmp/demo/js/test.js';

// �����/tmp/demo/js
console.log( path.dirname(filepath) );
```

### ��ȡ�ļ���

�ϸ���������˵��path.basename(filepath) ֻ�����·�������һ���֣��������ж��Ƿ��ļ�����

���󲿷�ʱ�����ǿ�����������Ϊ���׵ġ���ȡ�ļ������ķ�����

```javascript
var path = require('path');

// �����test.js
console.log( path.basename('/tmp/demo/js/test.js') );

// �����test
console.log( path.basename('/tmp/demo/js/test/') );

// �����test
console.log( path.basename('/tmp/demo/js/test') );
```

���ֻ���ȡ�ļ��������������ļ���չ�أ��������ϵڶ���������

```javascript
// �����test
console.log( path.basename('/tmp/demo/js/test.js', '.js') );
```

### ��ȡ�ļ���չ��

�򵥵��������£�

```javascript
var path = require('path');
var filepath = '/tmp/demo/js/test.js';

// �����.js
console.log( path.extname(filepath) );
```

����ϸ�Ĺ��������£������� path.basename(filepath) === B ��

* ��B�����һ��`.`��ʼ��ȡ��ֱ�����һ���ַ���
* ���B�в�����`.`������B�ĵ�һ���ַ�����`.`����ô���ؿ��ַ�����

ֱ�ӿ�[�ٷ��ĵ�](https://nodejs.org/api/path.html#path_path_extname_path)������

```javascript
path.extname('index.html')
// returns '.html'

path.extname('index.coffee.md')
// returns '.md'

path.extname('index.')
// returns '.'

path.extname('index')
// returns ''

path.extname('.index')
// returns ''

```

## ·�����

* path.join([...paths])
* path.resolve([...paths])

### path.join([...paths])

��`paths`ƴ������Ȼ����normalizeһ�¡���仰�������Լ�����Ҳ��Ī��������Բο������α���붨�塣

�������£�

```javacript
var path = require('path');

// ��� '/foo/bar/baz/asdf'
path.join('/foo', 'bar', 'baz/asdf', 'quux', '..');
```

path�����α�������£�

```javascript
module.exports.join = function(){
  var paths = Array.prototye.slice.call(arguments, 0);
  return this.normalize( paths.join('/') );
};
```

### path.resolve([...paths])

����ӿڵ�˵���еㆪ�¡������������������shell���棬����������һ��`cd path`������ջ�ȡ�ľ���·��/�ļ�������������ӿ������صĽ���ˡ�

���� `path.resolve('/foo/bar', './baz')` ���Կ�����������Ľ��

```bash
cd /foo/bar
cd ./baz
```

����Ա��������£�

```javascript
var path = require('path');

// ���赱ǰ����·���� /Users/a/Documents/git-code/nodejs-learning-guide/examples/2016.11.08-node-path

// ��� /Users/a/Documents/git-code/nodejs-learning-guide/examples/2016.11.08-node-path
console.log( path.resolve('') )

// ��� /Users/a/Documents/git-code/nodejs-learning-guide/examples/2016.11.08-node-path
console.log( path.resolve('.') )

// ��� /foo/bar/baz
console.log( path.resolve('/foo/bar', './baz') );

// ��� /foo/bar/baz
console.log( path.resolve('/foo/bar', './baz/') );

// ��� /tmp/file
console.log( path.resolve('/foo/bar', '/tmp/file/') );

// ��� /Users/a/Documents/git-code/nodejs-learning-guide/examples/2016.11.08-node-path/www/js/mod.js
console.log( path.resolve('www', 'js/upload', '../mod.js') );

```

## ·������

path.parse(path)

## path.normalize(filepath)

�ӹٷ��ĵ�������������path.normalize(filepath) Ӧ���ǱȽϼ򵥵�һ��API���������������Ǿ���û�ס�

Ϊʲô�أ�API˵�����ڼ����ˣ��������£�

* ���·��Ϊ�գ�����`.`���൱�ڵ�ǰ�Ĺ���·����
* ����·�����ظ���·���ָ���������linux�µ�`/`)�ϲ�Ϊһ����
* ��·���е�`.`��`..`���д�����������shell���`cd ..`��
* ���·�������`/`����ô������`/`��

�о�stackoverflow��һ���ֵܶ����API�Ľ��͸�ʵ�ڣ�[ԭ������](http://stackoverflow.com/questions/10822574/difference-between-path-normalize-and-path-resolve-in-node-js)��

>In other words, path.normalize is "What is the shortest path I can take that will take me to the same place as the input"


����ʾ�����¡�������߰Ѵ��뿽�����������£�����ʵ��Ч����

```javascript
var path = require('path');

var index = 0;

var compare = function(desc, callback){
  console.log('[����%d]��%s', ++index, desc);
  callback();
  console.log('\n');
};

compare('·��Ϊ��', function(){
  // ��� .
  console.log( path.normalize('') );
});

compare('·����β�Ƿ��/', function(){
  // ��� /tmp/demo/js/upload
  console.log( path.normalize('/tmp/demo/js/upload') );

  // /tmp/demo/js/upload/
  console.log( path.normalize('/tmp/demo/js/upload/') );
});

compare('�ظ���/', function(){
  // ��� /tmp/demo/js
  console.log( path.normalize('/tmp/demo//js') );
});

compare('·����..', function(){
  // ��� /tmp/demo/js
  console.log( path.normalize('/tmp/demo/js/upload/..') );
});

compare('���·��', function(){
  // ��� demo/js/upload/
  console.log( path.normalize('./demo/js/upload/') );

  // ��� demo/js/upload/
  console.log( path.normalize('demo/js/upload/') );
});

compare('�����ñ߽�', function(){
  // ��� ..
  console.log( path.normalize('./..') );

  // ��� ..
  console.log( path.normalize('..') );

  // ��� ../
  console.log( path.normalize('../') );

  // ��� /
  console.log( path.normalize('/../') );
  
  // ��� /
  console.log( path.normalize('/..') );
});
```

����Ȥ�Ŀ��Կ��� path.normalize(filepath) ��nodeԴ�����£�[������](https://github.com/nodejs/node/blob/master/lib/path.js)

## �ļ�·���ֽ�/���

* path.format(pathObject)����pathObject��root��dir��base��name��ext���ԣ�����һ���Ĺ�����ϳ�һ���ļ�·����
* path.parse(filepath)��path.format()�����ķ��������

������������������������Ե�˵����

������linux��

```bash
���������������������������������������������Щ�������������������������
��          dir        ��    base    ��
����������������              ���������������Щ�����������
�� root ��              �� name �� ext ��
"  /    home/user/dir / file  .txt "
���������������ة����������������������������ة������������ة�����������
(all spaces in the "" line should be ignored -- they are purely for formatting)
```


Ȼ����windows��

```bash
���������������������������������������������Щ�������������������������
��          dir        ��    base    ��
����������������              ���������������Щ�����������
�� root ��              �� name �� ext ��
" C:\      path\dir   \ file  .txt "
���������������ة����������������������������ة������������ة�����������
(all spaces in the "" line should be ignored -- they are purely for formatting)
```

### path.format(pathObject)

�Ķ����API�ĵ�˵�����֣�path.format(pathObject)�У�pathObject�����������ǿ��Խ�һ������ġ�

���ݽӿڵ��������������������ǵȼ۵ġ�

* `root` vs `dir`�����߿��Ի����滻���������ڣ�·��ƴ��ʱ��`root`�󲻻��Զ���`/`����`dir`�ᡣ
* `base` vs `name+ext`�����߿��Ի����滻��

```javascript
var path = require('path');

var p1 = path.format({
  root: '/tmp/', 
  base: 'hello.js'
});
console.log( p1 ); // ��� /tmp/hello.js

var p2 = path.format({
  dir: '/tmp', 
  name: 'hello',
  ext: '.js'
});
console.log( p2 );  // ��� /tmp/hello.js
```

### path.parse(filepath)

path.format(pathObject) �ķ��������ֱ���Ϲ������ӡ�

�ĸ����ԣ�����ʹ������ͦ�����ģ�����path.format(pathObject) ��Ҳ���ĸ��������ԣ����е����׸�졣

```javascript
path.parse('/home/user/dir/file.txt')
// returns
// {
//    root : "/",
//    dir : "/home/user/dir",
//    base : "file.txt",
//    ext : ".txt",
//    name : "file"
// }
```

## ��ȡ���·��

�ӿڣ�path.relative(from, to)

��������`from`·������`to`·�������·����

�߽磺

* ���`from`��`to`ָ��ͬ��·������ô�����ؿ��ַ�����
* ���`from`��`to`����һ��Ϊ�գ���ô�����ص�ǰ����·����

�����ӣ�

```javascript
var path = require('path');

var p1 = path.relative('/data/orandea/test/aaa', '/data/orandea/impl/bbb');
console.log(p1);  // ��� "../../impl/bbb"

var p2 = path.relative('/data/demo', '/data/demo');
console.log(p2);  // ��� ""

var p3 = path.relative('/data/demo', '');
console.log(p3);  // ��� "../../Users/a/Documents/git-code/nodejs-learning-guide/examples/2016.11.08-node-path"
```


## ƽ̨��ؽӿ�/����

�������ԡ��ӿڣ�����ƽ̨�ľ���ʵ����ء�Ҳ����˵��ͬ�������ԡ��ӿڣ��ڲ�ͬƽ̨�ϵı��ֲ�ͬ��

* path.posix��path������ԡ��ӿڵ�linuxʵ�֡�
* path.win32��path������ԡ��ӿڵ�win32ʵ�֡�
* path.sep��·���ָ�������linux����`/`����windows����`\`��
* path.delimiter��path���õķָ����linux����`:`��windows����`;`��

ע�⣬��ʹ�� path.win32 ��ؽӿ�ʱ������ͬ������ʹ��`/`���ָ��������ӿڷ���ֵ�ķָ��ֻ����`\`��

ֱ�������Ӹ�ֱ�ۡ�

```bash
> path.win32.join('/tmp', 'fuck')
'\\tmp\\fuck'
> path.win32.sep
'\\'
> path.win32.join('\tmp', 'demo')
'\\tmp\\demo'
> path.win32.join('/tmp', 'demo')
'\\tmp\\demo'
```

### path.delimiter

linuxϵͳ���ӣ�

```bash
console.log(process.env.PATH)
// '/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin'

process.env.PATH.split(path.delimiter)
// returns ['/usr/bin', '/bin', '/usr/sbin', '/sbin', '/usr/local/bin']
```

windowsϵͳ���ӣ�

```bash
console.log(process.env.PATH)
// 'C:\Windows\system32;C:\Windows;C:\Program Files\node\'

process.env.PATH.split(path.delimiter)
// returns ['C:\\Windows\\system32', 'C:\\Windows', 'C:\\Program Files\\node\\']
```

## �������

�ٷ��ĵ���https://nodejs.org/api/path.html#path_path
