## ģ����

`string_decoder`ģ�����ڽ�Bufferת�ɶ�Ӧ���ַ�����ʹ����ͨ������`stringDecoder.write(buffer)`�����Ի��buffer��Ӧ���ַ�����

��������֮�����ڣ��������buffer�����������������ֽڵ��ַ���ֻ���������������ڲ���ά��һ��internal buffer�����������ֽ�cacheס���ȵ�ʹ�����ٴε���`stringDecoder.write(buffer)`����ʣ����ֽڣ���ƴ���������ַ���

����������Ч����buffer�����������Ĵ��󣬶��ںܶೡ�����������������еİ�������ȣ��ǳ����á�

## ��������

��ڷֱ���ʾ��`decode.write(buffer)`��`decode.end([buffer])`������ҪAPI���÷���

����һ��

`decoder.write(buffer)`���ô�����Buffer����`<Buffer e4 bd a0>`����Ӧ�ķ����˶�Ӧ���ַ���`��`;

```javascript
const StringDecoder = require('string_decoder').StringDecoder;
const decoder = new StringDecoder('utf8');

// Buffer.from('��') => <Buffer e4 bd a0>
const str = decoder.write(Buffer.from([0xe4, 0xbd, 0xa0]));
console.log(str);  // ��
```

���Ӷ���

��`decoder.end([buffer])`������ʱ���ڲ�ʣ���buffer�ᱻһ���Է��ء������ʱ����`buffer`��������ô�൱��ͬʱ����`decoder.write(buffer)`��`decoder.end()`��

```javascript
const StringDecoder = require('string_decoder').StringDecoder;
const decoder = new StringDecoder('utf8');

// Buffer.from('���') => <Buffer e4 bd a0 e5 a5 bd>
let str = decoder.write(Buffer.from([0xe4, 0xbd, 0xa0, 0xe5, 0xa5]));
console.log(str);  // ��

str = decoder.end(Buffer.from([0xbd]));
console.log(str);  // ��
```

## ���ӣ��ֶ��д�����ֽ�

��������ӣ���ʾ�˷ֶ��д�����ֽ�ʱ��`string_decoder`ģ������ô����ġ�

���ȣ�������`<Buffer e4 bd a0 e5 a5>`��`��`����1���ֽڣ���ʱ��`decoder.write(xx)`����`��`��

Ȼ���ٴε���`decoder.write(Buffer.from([0xbd]))`����ʣ���1���ֽڴ��룬�ɹ�����`��`��

```javascript
const StringDecoder = require('string_decoder').StringDecoder;
const decoder = new StringDecoder('utf8');

// Buffer.from('���') => <Buffer e4 bd a0 e5 a5 bd>
let str = decoder.write(Buffer.from([0xe4, 0xbd, 0xa0, 0xe5, 0xa5]));
console.log(str);  // ��

str = decoder.write(Buffer.from([0xbd]));
console.log(str);  // ��
```
## ���ӣ�decoder.end()ʱ���ֽ����������Ĵ���

`decoder.end(buffer)`ʱ����������`��`�ĵ�1���ֽڣ���ʱ����`decoder.end()`��������`?`����Ӧ��bufferΪ`<Buffer ef bf bd>`��

```javascript
const StringDecoder = require('string_decoder').StringDecoder;

// Buffer.from('��') => <Buffer e5 a5 bd>
let decoder = new StringDecoder('utf8');
let str = decoder.end( Buffer.from([0xe5]) );
console.log(str);  // ?
console.log(Buffer.from(str));  // <Buffer ef bf bd>
```

�ٷ��ĵ�������������Ľ����������ģ����ϻ���ࣩ����Լ��Լ���׳��ˣ���`utf8`�����Чʱ���滻��`ef bf bd`��

>Returns any remaining input stored in the internal buffer as a string. Bytes representing incomplete UTF-8 and UTF-16 characters will be replaced with substitution characters appropriate for the character encoding.

## �������

��Ӧ�ü�ס��һ��UTF-8�ַ���EF BF BD��
http://liudanking.com/golang/utf-8_replacement_character/