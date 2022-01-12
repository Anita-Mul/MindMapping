## �ļ���ȡ

### ��ͨ��ȡ

ͬ����ȡ

```javascript
var fs = require('fs');
var data;

try{
    data = fs.readFileSync('./fileForRead.txt', 'utf8');
    console.log('�ļ�����: ' + data);
}catch(err){
    console.error('��ȡ�ļ�����: ' + err.message);
}
```

������£�

```powershell
/usr/local/bin/node readFileSync.js
�ļ�����: hello world
```

�첽��ȡ

```javascript
var fs = require('fs');

fs.readFile('./fileForRead.txt', 'utf8', function(err, data){
    if(err){
        return console.error('��ȡ�ļ�����: ' + err.message);
    }
    console.log('�ļ�����: ' + data);
});
```

�������

```powershell
/usr/local/bin/node readFile.js
�ļ�����: hello world
```

### ͨ���ļ�����ȡ

�ʺ϶�ȡ���ļ�

```javascript
var fs = require('fs');
var readStream = fs.createReadStream('./fileForRead.txt', 'utf8');

readStream
    .on('data', function(chunk) {
        console.log('��ȡ����: ' + chunk);
    })
    .on('error', function(err){
        console.log('����: ' + err.message);
    })
    .on('end', function(){  // û��������
        console.log('û��������');
    })
    .on('close', function(){  // �Ѿ��رգ����������¼��׳�
        console.log('�Ѿ��ر�');
    });
```

�������

```powershell
/usr/local/bin/node createReadStream.js
��ȡ����: hello world
û��������
�Ѿ��ر�
``` 

## �ļ�д��

��ע�����´��룬����ļ������ڣ��򴴽��ļ�������ļ����ڣ��򸲸��ļ����ݣ�

�첽д��

```javascript
var fs = require('fs');

fs.writeFile('./fileForWrite.txt', 'hello world', 'utf8', function(err){
    if(err) throw err;
    console.log('�ļ�д��ɹ�');
});
```

ͬ��д��

```javascript
var fs = require('fs');

try{
    fs.writeFileSync('./fileForWrite1.txt', 'hello world', 'utf8');
    console.log('�ļ�д��ɹ�');
}catch(err){
    throw err;
}
```

### ͨ���ļ���д��

```javascript
var fs = require('fs');
var writeStream = fs.createWriteStream('./fileForWrite1.txt', 'utf8');

writeStream
    .on('close', function(){  // �Ѿ��رգ����������¼��׳�
        console.log('�Ѿ��ر�');
    });

writeStream.write('hello');
writeStream.write('world');
writeStream.end('');
```

### ��Եײ�Ľӿ�

>fs.write(fd, buffer, offset, length[, position], callback)
>fs.write(fd, data[, position[, encoding]], callback)
>fs.writeSync(fd, buffer, offset, length[, position])
>fs.writeSync(fd, data[, position[, encoding]])

* fd��д����ļ������
* buffer��д������ݡ�
* offset����buffer��offsetλ�ÿ�ʼ������Ϊlength������д�롣
* length��д���buffer���ݵĳ��ȡ�
* position���Ӵ��ļ���position��д�롣
* callback������Ϊ `(err, written, buffer)`��`written`��ʾ��xx�ֽڵ�buffer��д�롣

��ע��`fs.write(fd, buffer, offset, length[, position], callback)`��`fs.write(fd, data[, position[, encoding]], callback)`���������ڣ������ֻ�ܰ����е�dataд�룬��ǰ��Ŀ���д��ָ����data�Ӵ���

## �ļ��Ƿ����

`fs.exists()`�Ѿ���`deprecated`״̬�����ڿ���ͨ����������ж��ļ��Ƿ���ڡ�

```javascript
var fs = require('fs');

fs.access('./fileForRead.txt', function(err){
    if(err) throw err;
    console.log('fileForRead.txt����');
});

fs.access('./fileForRead2.txt', function(err){
    if(err) throw err;
    console.log('fileForRead2.txt����');
});
```

`fs.access()`�����ж��ļ��Ƿ���ڣ�Ĭ��ģʽ���������������ж��ļ���Ȩ�ޡ�

������`fs.constants.F_OK`�ȳ����޷���ȡ��node v6.1��mac 10.11.4�£�`fs.constants`��`undefined`��

## ����Ŀ¼

�첽�汾�����Ŀ¼�Ѵ��ڣ��ᱨ��

```javascript
var fs = require('fs');

fs.mkdir('./hello', function(err){
    if(err) throw err;
    console.log('Ŀ¼�����ɹ�');
});
```

ͬ���汾

```javascript
var fs = require('fs');

fs.mkdirSync('./hello');
```

## ɾ���ļ�

```javascript
var fs = require('fs');

fs.unlink('./fileForUnlink.txt', function(err){
    if(err) throw err;
    console.log('�ļ�ɾ���ɹ�');
});
```

```javascript
var fs = require('fs');

fs.unlinkSync('./fileForUnlink.txt');
```

## ����Ŀ¼

```javascript
// fs.mkdir(path[, mode], callback)
var fs = require('fs');

fs.mkdir('sub', function(err){
    if(err) throw err;
    console.log('����Ŀ¼�ɹ�');
});
```

```javascript
// fs.mkdirSync(path[, mode])
var fs = require('fs');

try{
    fs.mkdirSync('hello');
    console.log('����Ŀ¼�ɹ�');
}catch(e){
    throw e;
}
```

## ����Ŀ¼

ͬ���汾��ע�⣺`fs.readdirSync()`ֻ���һ�㣬������Ҫ�ж��ļ������Ƿ�Ŀ¼������ǣ�����еݹ������

```javascript
// fs.readdirSync(path[, options])

var fs = require('fs');
var path = require('path');

var getFilesInDir = function(dir){

    var results = [ path.resolve(dir) ];
    var files = fs.readdirSync(dir, 'utf8');

    files.forEach(function(file){

        file = path.resolve(dir, file);

        var stats = fs.statSync(file);

        if(stats.isFile()){
            results.push(file);
        }else if(stats.isDirectory()){
            results = results.concat( getFilesInDir(file) );
        }
    });

    return results;
};

var files = getFilesInDir('../');
console.log(files);
```

�첽�汾����TODO��

```javascript

```

## �ļ�������

```javascript
// fs.rename(oldPath, newPath, callback)
var fs = require('fs');

fs.rename('./hello', './world', function(err){
    if(err) throw err;
    console.log('�������ɹ�');
});
```

```javascript
fs.renameSync(oldPath, newPath)
var fs = require('fs');

fs.renameSync('./world', './hello');
```

## �����ļ��޸�

`fs.watch()`��`fs.watchFile()`��Ч�ܶࣨwhy��

### fs.watchFile()

ʵ��ԭ����ѯ��ÿ��һ��ʱ�����ļ��Ƿ����仯�������ڲ�ͬƽ̨�ϱ��ֻ�����һ�µġ�

```javascript
var fs = require('fs');

var options = {
    persistent: true,  // Ĭ�Ͼ���true
    interval: 2000  // ��ü��һ��
};

// curr, prev �Ǳ������ļ���״̬, fs.Statʵ��
// ����ͨ�� fs.unwatch() �Ƴ�����
fs.watchFile('./fileForWatch.txt', options, function(curr, prev){
    console.log('�޸�ʱ��Ϊ: ' + curr.mtime);
});
```

�޸�`fileForWatch.txt`�����Կ�������̨�´�ӡ����־

```powershell
/usr/local/bin/node watchFile.js
�޸�ʱ��Ϊ: Sat Jul 16 2016 19:03:57 GMT+0800 (CST)
�޸�ʱ��Ϊ: Sat Jul 16 2016 19:04:05 GMT+0800 (CST)
```

Ϊɶ�ӣ�Ī�ǵ��������ļ�Ҳ�ᴥ���ص���

>If you want to be notified when the file was modified, not just accessed, you need to compare curr.mtime and prev.mtime.

�� **v0.10** ֮��ĸĶ�������������ļ������ڣ�����ô��������

>Note: when an fs.watchFile operation results in an ENOENT error, it will invoke the listener once, with all the fields zeroed (or, for dates, the Unix Epoch). In Windows, blksize and blocks fields will be undefined, instead of zero. If the file is created later on, the listener will be called again, with the latest stat objects. This is a change in functionality since v0.10.

### fs.watch()

>fs.watch(filename[, options][, listener])
>fs.unwatchFile(filename[, listener])

��ӿڷǳ������ף���ǰ�����õ�v6.1.0�����ο� https://github.com/nodejs/node/issues/7420

>fs.watch(filename[, options][, listener])#

ע�⣺`fs.watch()`����ӿڲ����������е�ƽ̨��Ϊ��һ�£�������ĳЩ������ǲ����õġ�`recursive`���ѡ��ֻ��`mac`��`windows`�¿��á�

�������ˣ�

1. ��һ�µı��֡�
2. �����õĳ�����
3. linux��Ҫrecursiveզ����

>The fs.watch API is not 100% consistent across platforms, and is unavailable in some situations.
>The recursive option is only supported on OS X and Windows.

�����������õĳ��������������ļ�ϵͳ�ȡ�

>For example, watching files or directories can be unreliable, and in some cases impossible, on network file systems (NFS, SMB, etc), or host file systems when using virtualization software such as Vagrant, Docker, etc.

���⣬listener�ص��������������ֱ���`event`��`filename`�����У�`filename`����linux��windows�ϻ��ṩ�����Ҳ���100%�ṩ�����ԣ�������Ҫ����`filename`��

��linux��osx�ϣ�`fs.watch()`��������inode������ļ���ɾ���������´�������ôɾ���¼��ᴥ����ͬʱ��`fs.watch()`�����Ļ��������inode����API����ƾ��������ģ�

���ۣ���ô�����о����API�ܲ����ף���Ȼ���ܱ�fs.watchFile()Ҫ�ߺܶࡣ

���������ӣ���osx�²�����һ�£���ֱ���˾��������������Ǵ������޸ġ�ɾ���ļ���`evt`����`rename`������

```javascript
var fs = require('fs');

var options = {
    persistent: true,
    recursive: true,
    encoding: 'utf8'
};

fs.watch('../', options, function(event, filename){
    console.log('�����¼�:' + event);
    if(filename){
        console.log('�ļ�����: ' + filename);
    }else{
        console.log('�ļ�����û���ṩ');
    }
});
```

�޸���`fileForWatch.txt`��������������������о�����Ҳ���������API������

���»�����osx 10.11.4, node v6.1.0��

```powershell
�����¼�:rename
�ļ�����: fs/fileForWatch.txt___jb_bak___
�����¼�:rename
�ļ�����: fs/fileForWatch.txt
�����¼�:rename
�ļ�����: fs/fileForWatch.txt___jb_old___
�����¼�:rename
�ļ�����: .idea/workspace.xml___jb_bak___
�����¼�:rename
�ļ�����: .idea/workspace.xml
�����¼�:rename
�ļ�����: .idea/workspace.xml___jb_old___
```

## �޸�������

�ο�linux�����У����������ˡ�����

>fs.chown(path, uid, gid, callback)
>fs.chownSync(path, uid, gid)
>fs.fchown(fd, uid, gid, callback)
>fs.fchownSync(fd, uid, gid)

## �޸�Ȩ��

������`fs.chmod()`��Ҳ������`fs.fchmod()`�����ߵ��������ڣ�ǰ�洫�����ļ�·�������洫�ĵ��ļ������

1. `fs.chmod)`��`fs.fchmod()`���𣺴������ļ�·���������ļ������
2. `fs.chmod()`��`fs.lchmod()`��������ļ��������ӣ���ô`fs.chmod()`�޸ĵ���������ָ���Ŀ���ļ���`fs.lchmod()`�޸ĵ��������ӡ�

>fs.chmod(path, mode, callback)
>fs.chmodSync(path, mode)

>fs.fchmod(fd, mode, callback)
>fs.fchmodSync(fd, mode)

>fs.lchmod(path, mode, callback)#
>fs.lchmodSync(path, mode)


���ӣ�

```javascript
var fs = require('fs');

fs.chmod('./fileForChown.txt', '777', function(err){
    if(err) console.log(err);
    console.log('Ȩ���޸ĳɹ�');
});
```

ͬ���汾��

```
var fs = require('fs');

fs.chmodSync('./fileForChown.txt', '777');
```

## ��ȡ�ļ�״̬

����

* `fs.stat()` vs `fs.fstat()`�����ļ�·�� vs �ļ������
* `fs.stat()` vs `fs.lstat()`������ļ��������ӣ���ô`fs.stat()`����Ŀ���ļ���״̬��`fs.lstat()`���������ӱ����״̬��

>fs.stat(path, callback)
>fs.statSync(path)

>fs.fstat(fd, callback)
>fs.fstatSync(fd)

>fs.lstat(path, callback)
>fs.lstatSync(path)

��Ҫ��ע`Class: fs.Stats`��

�����Ƿ���

* stats.isFile()  -- �Ƿ��ļ�
* stats.isDirectory() -- �Ƿ�Ŀ¼
* stats.isBlockDevice() -- ʲô��
* stats.isCharacterDevice() -- ʲô��
* stats.isSymbolicLink() (only valid with fs.lstat()) -- ʲô��
* stats.isFIFO() -- ʲô��
* stats.isSocket() -- �ǲ���socket�ļ�

�������ӣ�

```javascript
{
  dev: 2114,
  ino: 48064969,
  mode: 33188,
  nlink: 1,
  uid: 85,
  gid: 100,
  rdev: 0,
  size: 527,
  blksize: 4096,
  blocks: 8,
  atime: Mon, 10 Oct 2011 23:24:11 GMT, // ����ʱ��
  mtime: Mon, 10 Oct 2011 23:24:11 GMT,  // �ļ������޸�ʱ��
  ctime: Mon, 10 Oct 2011 23:24:11 GMT,  // �ļ�״̬�޸�ʱ��
  birthtime: Mon, 10 Oct 2011 23:24:11 GMT  // ����ʱ��
}
```

  * atime��Access Time // ����ʱ��
  * mtime:: Modified Time  // �ļ������޸�ʱ��
  * ctime: Changed Time.  // �ļ�״̬�޸�ʱ�䣬�����޸��ļ������ߡ��޸�Ȩ�ޡ���������
  * birthtime: Birth Time // ����ʱ�䡣��ĳЩϵͳ���ǲ��ɿ��ģ���Ϊ�ò�����

���ӣ�

```javascript
var fs = require('fs');

var getTimeDesc = function(d){
    return [d.getFullYear(), d.getMonth()+1, d.getDate()].join('-') + ' ' + [d.getHours(), d.getMinutes(), d.getSeconds()].join(':');
};

fs.stat('./fileForStat.txt', function(err, stats){
    console.log('�ļ���С: ' + stats.size);
    console.log('����ʱ��: ' + getTimeDesc(stats.birthtime));
    console.log('����ʱ��: ' + getTimeDesc(stats.atime));
    console.log('�޸�ʱ��: ' + getTimeDesc(stats.mtime));
});
```

������£�

```powershell
/usr/local/bin/node stat.js
�ļ���С: 3613
����ʱ��: 2016-7-16 12:40:49
����ʱ��: 2016-7-16 12:40:49
�޸�ʱ��: 2016-7-16 12:40:49

Process finished with exit code 0
```

ͬ�������ӣ�

```javascript
var fs = require('fs');

var getTimeDesc = function(d){
    return [d.getFullYear(), d.getMonth()+1, d.getDate()].join('-') + ' ' + [d.getHours(), d.getMinutes(), d.getSeconds()].join(':');
};

var stats = fs.statSync('./fileForStat.txt');

console.log('�ļ���С: ' + stats.size);
console.log('����ʱ��: ' + getTimeDesc(stats.birthtime));
console.log('����ʱ��: ' + getTimeDesc(stats.atime));
console.log('�޸�ʱ��: ' + getTimeDesc(stats.mtime));
```

## ����/Ȩ�޼��

���ӣ�

```javascript
// fs.access(path[, mode], callback)
var fs = require('fs');

fs.access('./fileForAccess.txt', function(err){
    if(err) throw err;
    console.log('���Է���');
});
```

ͬ���汾��

```javascript
// fs.accessSync(path[, mode])
var fs = require('fs');

// ����ɹ����򷵻�undefined�����ʧ�ܣ����׳�����ʲô��
try{
    fs.accessSync('./fileForAccess.txt');
}catch(e){
    throw(e);
}
```

## �ļ���/�ر�

�Ƚϵײ�Ľӿڣ�ʵ����Ҫ�õ��Ļ��᲻�ࡣ��Ҫ�õ���ʱ����[�ĵ�](https://nodejs.org/api/fs.html#fs_fs_open_path_flags_mode_callback)���С�

* flags���ļ���ģʽ������`r`��`r+`��`w`��`w+`�ȡ���ѡģʽ�ǳ��ࡣ
* mode��Ĭ����`666`���ɶ�+��д��

>fs.open(path, flags[, mode], callback)
>fs.openSync(path, flags[, mode])
>fs.close(fd, callback)
>fs.closeSync(fd)

## �ļ���ȡ���ײ㣩

��Եײ�Ķ�ȡ�ӿڣ���������

* fd���ļ������
* buffer������ȡ���ļ�����д��buffer�
* offset��buffer��ʼд���λ�á�����offset��ʼд�룬����offset+1����
* length��Ҫ��ȡ���ֽ�����
* position���ļ����ĸ�λ�ÿ�ʼ��ȡ�������null����ô�ʹӵ�ǰλ�ÿ�ʼ��ȡ������ȡ�������¼����һ��λ�ã�

���⣬`callback`�Ļص�����Ϊ`(err, bytesRead, buffer)`

>fs.read(fd, buffer, offset, length, position, callback)


## ׷���ļ�����

>fs.appendFile(file, data[, options], callback)

* file���������ļ�·����Ҳ�������ļ����������������buffer����
* data��Ҫ׷�ӵ����ݡ�string����buffer��
* options
    * encoding�����룬Ĭ����`utf8`
    * mode��Ĭ����`0o666`
    * flag��Ĭ����`a`

ע�⣺���`file`���ļ��������ô

* ��ʼ׷������ǰ��file��Ҫ�Ѿ��򿪡�
* file��Ҫ�ֶ��رա�

```javascript
var fs = require('fs');

fs.appendFile('./extra/fileForAppend.txt', 'hello', 'utf8', function(err){
    if(err) throw err;
    console.log('append�ɹ�');
});
```

## �ļ����ݽ�ȡ

>fs.truncate(path, len, callback)
>fs.truncateSync(path, len)
>
>fs.ftruncate(fd, len, callback)
>fs.ftruncateSync(fd, len)

��;�ο�[linux˵���ĵ�](http://man7.org/linux/man-pages/man2/ftruncate.2.html)��

Ҫ�㣺

* `offset`����仯������ͨ��`fs.read()`��ȡ�ļ����ݣ�����Ҫ�ر�ע�⡣
* ���`len`С���ļ����ݳ��ȣ�ʣ���ļ����ݲ��ֻᶪʧ�����`len`�����ļ����ݳ��ȣ���ô�����Ĳ��֣�����`\0`������䡣
* ����������ļ�·������Ҫȷ���ļ��ǿ�д�ģ�����������ļ��������Ҫȷ���ļ�����Ѿ��򿪲��ҿ�д�롣

>The truncate() and ftruncate() functions cause the regular file named
by path or referenced by fd to be truncated to a size of precisely
length bytes.

>If the file previously was larger than this size, the extra data is
lost.  If the file previously was shorter, it is extended, and the
extended part reads as null bytes ('\0').

>The file offset is not changed.

> With ftruncate(), the file must be open for writing; with truncate(), the file must be writable.

## �޸��ļ����ԣ�ʱ�䣩

* path/fd���ļ�·��/�ļ����
* atime��Access Time����һ�η����ļ����ݵ�ʱ�䡣
* mtime��Modified Time���޸�ʱ�䡣

>fs.utimes(path, atime, mtime, callback)
>fs.utimesSync(path, atime, mtime)

>fs.futimes(fd, atime, mtime, callback)
>fs.futimesSync(fd, atime, mtime)

��ע�����������¿���

* ͨ��`stat`�鿴�ļ���״̬��Ϣ�������������atime��mtime��
* ͨ��`touch`�޸��⼸��ʱ�䡣

## �����ļ�����

>fs.symlink(target, path[, type], callback)
>fs.symlinkSync(target, path[, type])
>
>fs.link(srcpath, dstpath, callback)
>fs.linkSync(srcpath, dstpath)

>  link() creates a new link (also known as a hard link) to an existing file.
       
�����ӡ�Ӳ��������[�ο�](https://www.ibm.com/developerworks/cn/linux/l-cn-hardandsymb-links/) ���� [���]��(http://www.cnblogs.com/itech/archive/2009/04/10/1433052.html)

* Ӳ���ӣ�inode��ͬ�����������ɾ��һ��Ӳ�����ļ�������Ӱ����������ͬinode���ļ���
* �����ӣ����Լ���inode���û����ݿ���ָ���ļ���inode��
       
�ο�[����](http://man7.org/linux/man-pages/man2/link.2.html)��

## ������ʱĿ¼

>fs.mkdtemp(prefix, callback)
>fs.mkdtempSync(prefix)

����������ͨ������Ҹ�Ŀ¼��������������ֵ��ļ��У���ʲô����

����ʾ�����£�

```javascript
var fs = require('fs');

fs.mkdtemp('/tmp/', function(err, folder){
    if(err) throw err;
    console.log('������ʱĿ¼: ' + folder);
});
```

������£�

```powershell
/usr/local/bin/node mkdtemp.js
������ʱĿ¼: /tmp/Cxw51O
```

## �ҳ�������ָ�����ʵ·��

>fs.readlink(path[, options], callback)
>fs.readlinkSync(path[, options])

���������ӣ������˸�������ָ��`fileForReadLink.txt`��ͨ��`fs.readlink()`�Ϳ����ҳ�ԭʼ��·����

```javascript
var fs = require('fs');
var randomFileName = './extra/fileForReadLink-' + String(Math.random()).slice(2, 6) + '.txt';

fs.symlinkSync('./extra/fileForReadLink.txt', randomFileName);
fs.readlink(randomFileName, 'utf8', function(err, linkString){
    if(err) throw err;
    console.log('�����ļ�����: ' + linkString);
});
```

�����ն���ֱ������`readlink`�������������ļ���Ч��ͬ������롣����Ӳ���ӣ�û�������

```powershell
?  extra git:(master) ? readlink fileForReadLink-9827.txt
./extra/fileForReadLink.txt
?  extra git:(master) ? readlink fileForLinkHard.txt 
?  extra git:(master) ? readlink fileForLinkSoft.txt
./extra/fileForLink.txt
```

## ��ʵ·��

>fs.realpath(path[, options], callback)
>fs.realpathSync(path[, options])

���ӣ������������������ӣ���

```javascript
var fs = require('fs');
var path = require('path');

// fileForRealPath1.txt ����ͨ�ļ�,��������
fs.realpath('./extra/inner/fileForRealPath1.txt', function(err, resolvedPath){
    if(err) throw err;
    console.log('fs.realpath: ' + resolvedPath);
});

// fileForRealPath.txt ��������, �ᱨ��,��ʾ�Ҳ����ļ�
fs.realpath('./extra/inner/fileForRealPath.txt', function(err, resolvedPath){
    if(err) throw err;
    console.log('fs.realpath: ' + resolvedPath);
});

console.log( 'path.resolve: ' + path.resolve('./extra/inner/fileForRealpath.txt') );
```

������£�

```powershell
path.resolve: /Users/a/Documents/git-code/git-blog/demo/2015.05.21-node-basic/fs/extra/inner/fileForRealpath.txt
fs.realpath: /Users/a/Documents/git-code/git-blog/demo/2015.05.21-node-basic/fs/extra/inner/fileForRealPath1.txt
/Users/a/Documents/git-code/git-blog/demo/2015.05.21-node-basic/fs/realpath.js:12
    if(err) throw err;
            ^

Error: ENOENT: no such file or directory, realpath './extra/inner/fileForRealPath.txt'
    at Error (native)

Process finished with exit code 1
```

## ɾ��Ŀ¼

>fs.rmdir(path, callback)
>fs.rmdirSync(path)

�������£�
```javascript
var fs = require('fs');

fs.rmdir('./dirForRemove', function(err){
    if(err) throw err;
    console.log('Ŀ¼ɾ���ɹ�');
});
```

## ������

### ����������д������

>fs.fdatasync(fd, callback)
>fs.fdatasyncSync(fd)

���Բο����

>1��sync����
sync����ֻ�ǽ������޸Ĺ��Ŀ黺��������д���У�Ȼ��ͷ��أ��������ȴ�ʵ��д���̲���������
ͨ����Ϊupdate��ϵͳ�ػ����̻������Եأ�һ��ÿ��30�룩����sync��������ͱ�֤�˶��ڳ�ϴ�ں˵Ŀ黺����������sync(1)Ҳ����sync������
2��fsync����
fsync����ֻ�����ļ�������filedesָ���ĵ�һ�ļ������ã����ҵȴ�д���̲���������Ȼ�󷵻ء�
fsync���������ݿ�������Ӧ�ó�������Ӧ�ó�����Ҫȷ�����޸Ĺ��Ŀ�����д�������ϡ�
3��fdatasync����
fdatasync����������fsync������ֻӰ���ļ������ݲ��֡����������⣬fsync����ͬ�������ļ������ԡ�
�����ṩ����֧�ֵ����ݿ⣬�������ύʱ����Ҫȷ��������־���������������е��޸Ĳ����Լ�һ���ύ��¼����ȫд��Ӳ���ϣ����϶������ύ�ɹ������ظ�Ӧ�ò㡣

## ��ȷ��

1. ͨƪ��`mode`����ȷ�ϡ�
2. fs.access()�����÷����漰 fs.constants.F_OK��Ȩ�ޣ�
