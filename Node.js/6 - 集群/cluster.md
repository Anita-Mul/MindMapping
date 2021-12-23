## clusterģ�����

nodeʵ���ǵ��߳���ҵ�ġ��ڷ���˱���У�ͨ���ᴴ�����nodeʵ��������ͻ��˵������Դ�����ϵͳ�������ʡ����������nodeʵ�������ǳ�֮Ϊcluster����Ⱥ����

����node��clusterģ�飬�����߿����ڼ������޸�ԭ����Ŀ�����ǰ���£���ü�Ⱥ��������ĺô���

��Ⱥ���������ֳ�����ʵ�ַ�������node�Դ���clusterģ�飬�����˷�������

### ����һ�����nodeʵ��+����˿�

��Ⱥ�ڵ�nodeʵ�������Լ�����ͬ�Ķ˿ڣ����ɷ������ʵ�����󵽶���˿ڵķַ���

* �ŵ㣺ʵ�ּ򵥣���ʵ����Զ�������Է����ȶ����кô���
* ȱ�㣺���Ӷ˿�ռ�ã�����֮��ͨ�űȽ��鷳��

### �����������������ӽ���ת������

��Ⱥ�ڣ�����һ��������(master)���Լ����ɸ��ӽ���(worker)����master�����ͻ����������󣬲������ض��Ĳ��ԣ�ת����worker��

* �ŵ㣺ͨ��ֻռ��һ���˿ڣ�ͨ����Լ򵥣�ת�����Ը���
* ȱ�㣺ʵ����Ը��ӣ��������̵��ȶ���Ҫ��ϸߡ�

## ����ʵ��

��clusterģ���У������̳�Ϊmaster���ӽ��̳�Ϊworker��

�������£�������CPU��Ŀ��ͬ�ķ����ʵ����������ͻ�������ע�⣬���Ǽ����Ķ���ͬ���Ķ˿ڡ�

```js
// server.js
var cluster = require('cluster');
var cpuNums = require('os').cpus().length;
var http = require('http');

if(cluster.isMaster){
  for(var i = 0; i < cpuNums; i++){
    cluster.fork();
  }
}else{
  http.createServer(function(req, res){
    res.end(`response from worker ${process.pid}`);
  }).listen(3000);

  console.log(`Worker ${process.pid} started`);
}
```

����������ű���./req.sh��

```bash
#!/bin/bash

# req.sh
for((i=1;i<=4;i++)); do   
  curl http://127.0.0.1:3000
  echo ""
done 
```

������¡����Կ�������Ӧ���Բ�ͬ�Ľ��̡�

```bash
response from worker 23735
response from worker 23731
response from worker 23729
response from worker 23730
```

## clusterģ��ʵ��ԭ��

�˽�clusterģ�飬��Ҫ�����3�����⣺

1. master��worker���ͨ�ţ�
2. ���serverʵ�������ʵ�ֶ˿ڹ���
2. ���serverʵ�������Կͻ��˵�������ηַ������worker��

�������ʾ��ͼ���н��ܣ�Դ�뼶��Ľ��ܣ����Բο� [���ߵ�github](https://github.com/chyingp/nodejs-learning-guide)��

## ����1��master��worker���ͨ��

�������Ƚϼ򵥡�master����ͨ�� cluster.fork() ������ worker���̡�cluster.fork() �ڲ� ��ͨ�� child_process.fork() �������ӽ��̡�

Ҳ����˵��

1. master���̡�worker�����Ǹ����ӽ��̵Ĺ�ϵ��
2. master���̡�woker���̿���ͨ��IPCͨ������ͨ�š�����Ҫ��

## ����2�����ʵ�ֶ˿ڹ���

��ǰ��������У����woker�д�����server������ͬ���˿�3000��ͨ����˵��������̼���ͬ���˿ڣ�ϵͳ�ᱨ��

Ϊʲô���ǵ�����û�����أ�

�������ڣ�netģ���У��� listen() �������������⴦�����ݵ�ǰ������master���̣�����worker���̣�

1. master���̣��ڸö˿��������������󡣣�û�����⴦��
2. worker���̣�����serverʵ����Ȼ��ͨ��IPCͨ������master���̷�����Ϣ����master����Ҳ���� server ʵ�������ڸö˿��ϼ������󡣵��������ʱ��master���̽�����ת����worker���̵�serverʵ����

�������������ǣ�master���̼����ض��˿ڣ������ͻ�����ת����worker���̡�

����ͼ��ʾ��

![](https://www.chyingp.com/wp-content/uploads/2018/04/4c1692183865cb201df83f8ee357d070.png)

### ����3����ν�����ַ������worker

ÿ��worker���̴���serverʵ�����������󣬶���ͨ��IPCͨ������master�Ͻ���ע�ᡣ���ͻ������󵽴master�Ḻ������ת������Ӧ��worker��

����ת�����ĸ�worker��������ת�����Ծ����ġ�����ͨ����������NODE_CLUSTER_SCHED_POLICY���ã�Ҳ������cluster.setupMaster(options)ʱ���롣

Ĭ�ϵ�ת����������ѯ��SCHED_RR����

���пͻ����󵽴master����ѯһ��worker�б��ҵ���һ�����е�worker��Ȼ�󽫸�����ת������worker��

## master��worker�ڲ�ͨ��С����

�ڿ��������У����ǻ�ͨ�� process.on('message', fn) ��ʵ�ֽ��̼�ͨ�š�

ǰ���ᵽ��master���̡�worker������serverʵ���Ĵ��������У�Ҳ��ͨ��IPCͨ������ͨ�ŵġ��ǻ᲻������ǵĿ�����ɸ����أ����磬�յ�һ����ʵ������Ҫ���ĵ���Ϣ��

�𰸿϶��ǲ��᣿��ô����ô�������أ�

�����͵���Ϣ����`cmd`�ֶΣ��Ҹ��ֶ���`NODE_`��Ϊǰ׺�������Ϣ�ᱻ��Ϊ�ڲ���������Ϣ������ͨ��`message`�¼��׳���������ͨ������'internalMessage'����

��worker����֪ͨmaster���̴���serverʵ��Ϊ���ӡ�workerα�������£�

```javascript
// woker����
const message = {
  cmd: 'NODE_CLUSTER',
  act: 'queryServer'
};
process.send(message);
```

masterα�������£�

```javascript
worker.process.on('internalMessage', fn);
```

## �������

�ٷ��ĵ���[https://nodejs.org/api/cluster.html](https://nodejs.org/api/cluster.html)

Nodeѧϰ�ʼǣ�[https://github.com/chyingp/nodejs-learning-guide](https://github.com/chyingp/nodejs-learning-guide)
