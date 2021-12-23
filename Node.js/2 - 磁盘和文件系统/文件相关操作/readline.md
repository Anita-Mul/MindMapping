## ģ�����

readline�Ǹ��ǳ�ʵ�õ�ģ�顣��������ʾ����Ҫ����ʵ�����ж�ȡ�������ȡ�û����룬���߶�ȡ�ļ����ݡ�����ʹ�ó��������漸�֣����Ļ���һ����˵����

* �ļ����ж�ȡ������˵������־������
* �Զ���ɣ���������npm���Զ���ʾ"help init install"��
* �����й��ߣ�����npm init�����ʴ�ʽ�Ľ��ּܹ��ߡ�

## ��������

�ȿ����򵥵����ӣ�Ҫ���û�����һ�����ʣ�Ȼ���Զ�ת�ɴ�д

```js
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Please input a word: ', function(answer){
    console.log('You have entered [%s]', answer.toUpperCase());
    rl.close();
});
```

�������£�

```bash
?  toUpperCase git:(master) ? node app.js 
Please input a word: hello
You have entered {HELLO}
```

## ���ӣ��ļ����ж�ȡ����־����

����������������־�ļ�access.log��������Ҫ��ȡ������ʱ��+���ʵ�ַ��������`readline`���Ժܷ���������־�����Ĺ�����

```
[2016-12-09 13:56:48.407] [INFO] access - ::ffff:127.0.0.1 - - "GET /oc/v/account/user.html HTTP/1.1" 200 213125 "http://www.example.com/oc/v/account/login.html" "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.98 Safari/537.36"
[2016-12-09 14:00:10.618] [INFO] access - ::ffff:127.0.0.1 - - "GET /oc/v/contract/underlying.html HTTP/1.1" 200 216376 "http://www.example.com/oc/v/account/user.html" "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.98 Safari/537.36"
[2016-12-09 14:00:34.200] [INFO] access - ::ffff:127.0.0.1 - - "GET /oc/v/contract/underlying.html HTTP/1.1" 200 216376 "http://www.example.com/oc/v/account/user.html" "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.98 Safari/537.36"
```

�������£�

```js
const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
    input: fs.createReadStream('./access.log')
});

rl.on('line', (line) => {
    const arr = line.split(' '); 
    console.log('����ʱ�䣺%s %s�����ʵ�ַ��%s', arr[0], arr[1], arr[13]);
});
```

���н�����£�

```bash
?  lineByLineFromFile git:(master) ? node app.js
����ʱ�䣺[2016-12-09 13:56:48.407]�����ʵ�ַ��"http://www.example.com/oc/v/account/login.html"
����ʱ�䣺[2016-12-09 14:00:10.618]�����ʵ�ַ��"http://www.example.com/oc/v/account/user.html"
����ʱ�䣺[2016-12-09 14:00:34.200]�����ʵ�ַ��"http://www.example.com/oc/v/account/user.html"
```

## ���ӣ��Զ���ɣ�������ʾ

��������ʵ��һ���򵥵��Զ���ɹ��ܣ����û�����npmʱ����tab�����Զ���ʾ�û���ѡ���������help��init��install��

* ����`np`������tab���Զ���ȫΪnpm
* ����`npm in`������tab���Զ���ʾ��ѡ������ init��install
* ����`npm inst`������tab���Զ���ȫΪ `npm install`

```js
const readline = require('readline');
const fs = require('fs');

function completer(line) {
    const command = 'npm';
    const subCommands = ['help', 'init', 'install'];

    // ����Ϊ�գ�����Ϊnpm��һ���֣���tab��ȫΪnpm
    if(line.length < command.length){
        return [command.indexOf(line) === 0 ? [command] : [], line];
    }

    // ���� npm��tab��ʾ help init install
    // ���� npm in��tab��ʾ init install
    let hits = subCommands.filter(function(subCommand){ 
        const lineTrippedCommand = line.replace(command, '').trim();
        return lineTrippedCommand && subCommand.indexOf( lineTrippedCommand ) === 0;
    })

    if(hits.length === 1){
        hits = hits.map(function(hit){
            return [command, hit].join(' ');
        });
    }
  
    return [hits.length ? hits : subCommands, line];
}

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  completer: completer
});

rl.prompt();
```

��������Ч�����£�������`npm in`������tab��������Զ���ʾ��ѡ������init��install��

```bash
?  autoComplete git:(master) ? node app.js
> npm in
init     install  
```

## ���ӣ������й��ߣ�npmt init

�������readlineʵ��һ��������`npm init`���ܣ����нű�ʱ��������Ҫ���û�����name��version��author���ԣ������Թ�����

�����õ�����`rl.question(msg, cbk)`��������������ڿ���̨����һ����ʾ�����û�������룬�û��س���`cbk`�ͻᱻ���ã������û�������Ϊ�������롣

```js
const readline = require('readline');
const fs = require('fs');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    prompt: 'OHAI> '
});

const preHint = `
This utility will walk you through creating a package.json file.
It only covers the most common items, and tries to guess sensible defaults.

See \`npm help json\` for definitive documentation on these fields
and exactly what they do.

Use \`npm install <pkg> --save\` afterwards to install a package and
save it as a dependency in the package.json file.

Press ^C at any time to quit.
`;

console.log(preHint);

// ����
let questions = [ 'name', 'version', 'author'];

// Ĭ�ϴ�
let defaultAnswers = [ 'name', '1.0.0', 'none' ];

// �û���
let answers = [];
let index = 0;

function createPackageJson(){
    var map = {};
    questions.forEach(function(question, index){
        map[question] = answers[index];
    });

    fs.writeFileSync('./package.json', JSON.stringify(map, null, 4));
}

function runQuestionLoop() {

    if(index === questions.length) {
        createPackageJson();
        rl.close();
        return;
    }
    
    let defaultAnswer = defaultAnswers[index];
    let question = questions[index] + ': (' + defaultAnswer +') ';
    
    rl.question(question, function(answer){
        answers.push(answer || defaultAnswer);
        index++;
        runQuestionLoop();
    });
}

runQuestionLoop();
```

����Ч�����£������ģ������������package.json������������

```bash
?  commandLine git:(master) ? node app.js

This utility will walk you through creating a package.json file.
It only covers the most common items, and tries to guess sensible defaults.

See `npm help json` for definitive documentation on these fields
and exactly what they do.

Use `npm install <pkg> --save` afterwards to install a package and
save it as a dependency in the package.json file.

Press ^C at any time to quit.

name: (name) hello
version: (1.0.0) 0.0.1
author: (none) chyingp
```

## д�ں���

�в��ٻ���readline����Ȥ�Ĺ��ߣ�������ֽ��ּܹ��ߡ�����ƪ����չ��������Ȥ��ͬѧ�����о��¡�

## �������

https://nodejs.org/api/readline.html