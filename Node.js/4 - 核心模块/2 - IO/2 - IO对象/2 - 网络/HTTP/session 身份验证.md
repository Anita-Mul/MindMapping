## �ĵ�����

���Ļ���express��express-sessionʵ���˼��׵ĵ�¼/�ǳ����ܣ������Ĵ���ʾ��������[����](https://github.com/chyingp/nodejs-learning-guide/tree/master/examples/2016.12.06-session)�ҵ���

## ������ʼ��

���ȣ���ʼ����Ŀ

```bash
express -e
```

Ȼ�󣬰�װ������

```bash
npm install
```

���ţ���װsession��صİ���

```bash
npm install --save express-session session-file-store
```

## session�������

�������£��������ӣ����Լ�����ע�ͣ����߲ο�[�ٷ��ĵ�](https://github.com/expressjs/session#options)��

```js
var express = require('express');
var app = express();
var session = require('express-session');
var FileStore = require('session-file-store')(session);

var identityKey = 'skey';

app.use(session({
    name: identityKey,
    secret: 'chyingp',  // ������session id��ص�cookie����ǩ��
    store: new FileStore(),  // ���ش洢session���ı��ļ���Ҳ����ѡ������store������redis�ģ�
    saveUninitialized: false,  // �Ƿ��Զ�����δ��ʼ���ĻỰ������false
    resave: false,  // �Ƿ�ÿ�ζ����±���Ự������false
    cookie: {
        maxAge: 10 * 1000  // ��Ч�ڣ���λ�Ǻ���
    }
}));
```

## ʵ�ֵ�¼/�ǳ��ӿ�

### ���������˻�����

���ȣ��ڱ��ش������ļ�������������ڵ�¼���˻���Ϣ�����ⴴ���������ݿ�ķ�����

```js
// users.js
module.exports = {
    items: [
        {name: 'chyingp', password: '123456'}
    ]
};
```

### ��¼���ǳ��ӿ�ʵ��

ʵ�ֵ�¼���ǳ��ӿڣ����У�

* ��¼������û����ڣ���ͨ��`req.regenerate`����session�����浽���أ���ͨ��`Set-Cookie`��session id���浽�û��ࣻ
* �ǳ�������session�������cookie��

```js
var users = require('./users').items;

var findUser = function(name, password){
    return users.find(function(item){
        return item.name === name && item.password === password;
    });
};

// ��¼�ӿ�
app.post('/login', function(req, res, next){
    
    var sess = req.session;
    var user = findUser(req.body.name, req.body.password);

    if(user){
        req.session.regenerate(function(err) {
            if(err){
                return res.json({ret_code: 2, ret_msg: '��¼ʧ��'});                
            }
            
            req.session.loginUser = user.name;
            res.json({ret_code: 0, ret_msg: '��¼�ɹ�'});                           
        });
    }else{
        res.json({ret_code: 1, ret_msg: '�˺Ż��������'});
    }   
});

// �˳���¼
app.get('/logout', function(req, res, next){
    // ��ע�������õ� session-file-store ��destroy �������û������cookie
    // ���Կͻ��˵� cookie ���Ǵ��ڣ����µ����� --> �˳���½�󣬷���˼�⵽cookie
    // Ȼ��ȥ���Ҷ�Ӧ�� session �ļ�������
    // session-file-store �����bug    

    req.session.destroy(function(err) {
        if(err){
            res.json({ret_code: 2, ret_msg: '�˳���¼ʧ��'});
            return;
        }
        
        // req.session.loginUser = null;
        res.clearCookie(identityKey);
        res.redirect('/');
    });
});
```

### ��¼̬�ж�

�û����� http://127.0.0.1:3000 ʱ���ж��û��Ƿ��¼������ǣ�������û�������棨��ª�ޱȣ������û�е�¼����������¼���棻

```js
app.get('/', function(req, res, next){
    var sess = req.session;
    var loginUser = sess.loginUser;
    var isLogined = !!loginUser;

    res.render('index', {
        isLogined: isLogined,
        name: loginUser || ''
    });
});

```

### UI����

��󣬿��µ�¼���ǳ�UI��صĴ��롣

```html
<!DOCTYPE html>
<html>
<head>
    <title>�Ự����</title>
</head>
<body>

<h1>�Ự����</h1>

<% if(isLogined){ %>
    <p>��ǰ��¼�û���<%= name %>��<a href="/logout" id="logout">�˳���½</a></p>
<% }else{ %>
    <form method="POST" action="/login">
        <input type="text" id="name" name="name" value="chyingp" />
        <input type="password" id="password" name="password" value="123456" />
        <input type="submit" value="��¼" id="login" />
    </form>
<% } %> 

<script type="text/javascript" src="/jquery-3.1.0.min.js"></script>
<script type="text/javascript">
    $('#login').click(function(evt){
        evt.preventDefault();

        $.ajax({
            url: '/login',
            type: 'POST',
            data: {
                name: $('#name').val(),
                password: $('#password').val()
            },
            success: function(data){
                if(data.ret_code === 0){
                    location.reload();
                }   
            }
        });
    });
</script>

</body>
</html>
```

## �������

https://github.com/expressjs/session