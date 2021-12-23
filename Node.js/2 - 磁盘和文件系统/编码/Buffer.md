## ģ�����

Buffer��node�ĺ���ģ�飬�����߿�����������������������ݣ������ļ����Ķ�д�������������ݵĴ���ȡ�

Buffer��API�ǳ��࣬���Ľ���ѡ �Ƚϳ���/������� ��API���н��⣬����Bufferʵ���Ĵ������Ƚϡ����ӡ����������ҡ�����������ת������ȡ������ת���ȡ�

## ����

* new Buffer(array)
* Buffer.alloc(length)
* Buffer.allocUnsafe(length)
* Buffer.from(array)

### ͨ�� new Buffer(array)

```js
// Creates a new Buffer containing the ASCII bytes of the string 'buffer'
const buf = new Buffer([0x62, 0x75, 0x66, 0x66, 0x65, 0x72]);
```

��֤�£�

```js
var array = 'buffer'.split('').map(function(v){
    return '0x' + v.charCodeAt(0).toString(16)
});

console.log( array.join() );
// �����0x62,0x75,0x66,0x66,0x65,0x72
```

### ͨ�� Buffer.alloc(length)

```js
var buf1 = Buffer.alloc(10);  // ����Ϊ10��buffer����ʼֵΪ0x0
var buf2 = Buffer.alloc(10, 1);  // ����Ϊ10��buffer����ʼֵΪ0x1
```

```js
var buf3 = Buffer.allocUnsafe(10);  // ����Ϊ10��buffer����ʼֵ��ȷ��
```

```js
var buf4 = Buffer.from([1, 2, 3])  // ����Ϊ3��buffer����ʼֵΪ 0x01, 0x02, 0x03
```

### ͨ��Buffer.from()

����һ��Buffer.from(array)

```js
// [0x62, 0x75, 0x66, 0x66, 0x65, 0x72] Ϊ�ַ��� "buffer" 
// 0x62 Ϊ16���ƣ�ת��ʮ���ƾ��� 98������ľ�����ĸ b
var buf = Buffer.from([0x62, 0x75, 0x66, 0x66, 0x65, 0x72]);
console.log(buf.toString());
```

���Ӷ���Buffer.from(string[, encoding])

ͨ��string����buffer������bufferת���ַ���ʱ���ǵñ��뱣��һ�£���Ȼ��������룬������ʾ��

```js
var buf = Buffer.from('this is a t��st');  // Ĭ�ϲ���utf8

// �����this is a t��st
console.log(buf.toString());  // Ĭ�ϱ�����utf8������������ӡ

// �����this is a tC)st
console.log(buf.toString('ascii'));  // ת���ַ���ʱ�����벻��utf8����������
```

������ķ������£�

```js
var letter = '��';
var buff = Buffer.from(letter);  // Ĭ�ϱ�����utf8������ռ�������ֽ� <Buffer c3 a9>
var len = buff.length;  // 2
var code = buff[0]; // ��һ���ֽ�Ϊ0xc3����195������ascii�����֧�ַ�Χ
var binary = code.toString(2);  // 195�Ķ����ƣ�10101001
var finalBinary = binary.slice(1);  // ����λ��1��������ɣ�0101001
var finalCode = parseInt(finalBinary, 2);  // 0101001 ��Ӧ��ʮ���ƣ�67
var finalLetter = String.fromCharCode(finalCode);  // 67��Ӧ���ַ���C

// ͬ�� 0xa9����ת�ɵ�ascii�ַ�Ϊ)
// ���ԣ��������Ϊ this is a tC)st
```

��������Buffer.from(buffer)

�����µ�Bufferʵ��������buffer�����ݿ������µ�ʵ������ȥ��

```js
var buff = Buffer.from('buffer');
var buff2 = Buffer.from(buff);

console.log(buff.toString());  // �����buffer
console.log(buff2.toString());  // �����buffer

buff2[0] = 0x61;

console.log(buff.toString());  // �����buffer
console.log(buff2.toString());  // �����auffer
```


## buffer�Ƚ�

### buf.equals(otherBuffer)

�ж�����bufferʵ���洢�������Ƿ���ͬ������ǣ�����true�����򷵻�false��

```js
// ����һ������һ����������ͬ
var buf1 = Buffer.from('A');
var buf2 = Buffer.from('A');

console.log( buf1.equals(buf2) );  // true

// ���Ӷ�������һ�������ݲ�ͬ
var buf3 = Buffer.from('A');
var buf4 = Buffer.from('B');

console.log( buf3.equals(buf4) );  // false

// �����������벻һ����������ͬ
var buf5 = Buffer.from('ABC');  // <Buffer 41 42 43>
var buf6 = Buffer.from('414243', 'hex');

console.log(buf5.equals(buf6));    //true

//ֻҪ�Ƚϵ�����������ͬ,`buf.equals(otherBuffer)` �ͷ���true
```

### buf.compare(target[, targetStart[, targetEnd[, sourceStart[, sourceEnd]]]])

ͬ���Ƕ�����bufferʵ�����бȽϣ���ͬ���ǣ�

1. ����ָ���ض��Ƚϵķ�Χ��ͨ��start��endָ����
2. ����ֵΪ���������buf��target�Ĵ�С��ϵ

���践��ֵΪ

* `0`��buf��target��С��ͬ��
* `1`��buf����target��Ҳ����˵bufӦ������target֮��
* `-1`��bufС��target��Ҳ����˵bufӦ������target֮ǰ��

�����ӣ��ٷ�������ͦ�õģ�ֱ����һ�£�

```js
const buf1 = Buffer.from('ABC');
const buf2 = Buffer.from('BCD');
const buf3 = Buffer.from('ABCD');

// Prints: 0
console.log(buf1.compare(buf1));

// Prints: -1
console.log(buf1.compare(buf2));

// Prints: -1
console.log(buf1.compare(buf3));

// Prints: 1
console.log(buf2.compare(buf1));

// Prints: 1
console.log(buf2.compare(buf3));

// Prints: [ <Buffer 41 42 43>, <Buffer 41 42 43 44>, <Buffer 42 43 44> ]
// (This result is equal to: [buf1, buf3, buf2])
console.log([buf1, buf2, buf3].sort(Buffer.compare));
```

### Buffer.compare(buf1, buf2)

�� `buf.compare(target)` ��ͬС�죬һ����������ֱ�����ٷ����ӣ�

```js
const buf1 = Buffer.from('1234');
const buf2 = Buffer.from('0123');
const arr = [buf1, buf2];

// Prints: [ <Buffer 30 31 32 33>, <Buffer 31 32 33 34> ]
// (This result is equal to: [buf2, buf1])
console.log(arr.sort(Buffer.compare));
```

## ��Buffer.from([62])̸��

������΢�о���Buffer.from(array)�������ǹٷ��ĵ���API��˵����Ҳ����˵��ÿ��array��Ԫ�ض�Ӧ1���ֽڣ�8λ����ȡֵ��0��255��

>Allocates a new Buffer using an array of octets.

### ����Ԫ��Ϊ����

���ȿ��£������Ԫ��Ϊ���ֵĳ���������ֱ���10���ơ�8���ơ�16���ƣ���Ԥ���еĽ��һ�¡�

```js
var buff = Buffer.from([62])
// <Buffer 3e>
// buff[0] === parseInt('3e', 16) === 62
```

```js
var buff = Buffer.from([062])
// <Buffer 32>
// buff[0] === parseInt(62, 8) === parseInt(32, 16) === 50
```

```js
var buff = Buffer.from([0x62])
// <Buffer 62>
// buff[0] === parseInt(62, 16) === 98
```

### ����Ԫ��Ϊ�ַ���

�ٿ��£������Ԫ��Ϊ�ַ����ĳ�����

1. `0`��ͷ���ַ�������parseInt('062')ʱ�����Խ���Ϊ62��Ҳ���Խ���Ϊ50���˽��ƣ������￴�������˵�һ�ֽ��͡�
2. �ַ����ĳ�������parseInt()��û�й�ϵ����δ����̽����ֻ���������롣TODO����ʱ���о��£�

```js
var buff = Buffer.from(['62'])
// <Buffer 3e>
// buff[0] === parseInt('3e', 16) === parseInt('62') === 62
```

```js
var buff = Buffer.from(['062'])
// <Buffer 3e>
// buff[0] === parseInt('3e', 16) === parseInt('062') === 62
```

```js
var buff = Buffer.from(['0x62'])
// <Buffer 62>
// buff[0] === parseInt('62', 16) === parseInt('0x62') === 98
```

### ����Ԫ�ش�С����1���ֽ�

����Ȥ��ͬѧ����̽����

```js
var buff = Buffer.from([256])
// <Buffer 00>
```

## Buffer.from('1')

һ��ʼ���Ծ��ĻὫ`Buffer.from('1')[0]`��`"1"`���Ⱥţ���ʵ`"1"`��Ӧ�ı�����49��

```js
var buff = Buffer.from('1')  // <Buffer 31>
console.log(buff[0] === 1)  // false
```

�����ԱȾ�֪���ˣ�����Ϊ1���Ǹ������ַ�����ʾ Start of Heading��

```js
console.log( String.fromCharCode(49) )  // '1'
console.log( String.fromCharCode(1) )  // '\u0001'
```

## buffer���ӣ�Buffer.concat(list[, totalLength])

��ע�����˾���`totalLength`�������ͦ����ģ��ӹٷ��ĵ��������Ǵ������������ĽǶȿ��ǡ������ڲ�ʵ��Ҳֻ�Ǳ���list����length�ۼӵõ�totalLength������������������Ż��Ǽ������Ժ��Բ��Ƶġ�

```js
var buff1 = Buffer.alloc(10);
var buff2 = Buffer.alloc(20);

var totalLength = buff1.length + buff2.length;

console.log(totalLength);  // 30

var buff3 = Buffer.concat([buff1, buff2], totalLength);

console.log(buff3.length);  // 30
```

���������ᵽ�������Ż���totalLength����������Ҫע�⡣����list��������buffer�ĳ����ۼӺ�Ϊlength

* totalLength > length�����س���ΪtotalLength��Bufferʵ�����������ȵĲ������0��
* totalLength < length�����س���ΪtotalLength��Bufferʵ�������沿��������

```js
var buff4 = Buffer.from([1, 2]);
var buff5 = Buffer.from([3, 4]);

var buff6 = Buffer.concat([buff4, buff5], 5);

console.log(buff6.length);  // 
console.log(buff6);  // <Buffer 01 02 03 04 00>

var buff7 = Buffer.concat([buff4, buff5], 3);

console.log(buff7.length);  // 3
console.log(buff7);  // <Buffer 01 02 03>
```

## ������buf.copy(target[, targetStart[, sourceStart[, sourceEnd]]])

ʹ�ñȽϼ򵥣�������Ժ��������������Ǿ��ǽ�buf�����ݿ�����target��ȥ��������ʾ��

```js
var buff1 = Buffer.from([1, 2]);
var buff2 = Buffer.alloc(2);

buff1.copy(buff2);

console.log(buff2);  // <Buffer 01 02>
```

�������������Ƚ�ֱ�ۣ�ֱ�ӿ��ٷ�����

```js
const buf1 = Buffer.allocUnsafe(26);
const buf2 = Buffer.allocUnsafe(26).fill('!');

for (let i = 0 ; i < 26 ; i++) {
  // 97 is the decimal ASCII value for 'a'
  buf1[i] = i + 97;
}

buf1.copy(buf2, 8, 16, 20);

// Prints: !!!!!!!!qrst!!!!!!!!!!!!!
console.log(buf2.toString('ascii', 0, 25));
```

## ���ң�buf.indexOf(value[, byteOffset][, encoding])

������Ĳ��Ҳ�࣬��Ҫע����ǣ�value������String��Buffer��Integer�е��������͡�

* String��������ַ�������ôencoding�������Ӧ�ı��룬Ĭ����utf8��
* Buffer�������Bufferʵ������ô�Ὣvalue�е��������ݣ���buf���жԱȡ�
* Integer����������֣���ôvalue�ᱻ�����޷��ŵ�8λ������ȡֵ��Χ��0��255��

���⣬����ͨ��`byteOffset`��ָ����ʼ����λ�á�

ֱ���ϴ��룬�ٷ��������׵ģ����Ŀ��������������ò���ˡ�

```js
const buf = Buffer.from('this is a buffer');

// Prints: 0
console.log(buf.indexOf('this'));

// Prints: 2
console.log(buf.indexOf('is'));

// Prints: 8
console.log(buf.indexOf(Buffer.from('a buffer')));

// Prints: 8
// (97 is the decimal ASCII value for 'a')
console.log(buf.indexOf(97));

// Prints: -1
console.log(buf.indexOf(Buffer.from('a buffer example')));

// Prints: 8
console.log(buf.indexOf(Buffer.from('a buffer example').slice(0, 8)));


const utf16Buffer = Buffer.from('\u039a\u0391\u03a3\u03a3\u0395', 'ucs2');

// Prints: 4
console.log(utf16Buffer.indexOf('\u03a3', 0, 'ucs2'));

// Prints: 6
console.log(utf16Buffer.indexOf('\u03a3', -4, 'ucs2'));
```

## д��buf.write(string[, offset[, length]][, encoding])

��sringд��bufʵ����ͬʱ����д����ֽ�����

�������£�

* string��д����ַ�����
* offset����buf�ĵڼ�λ��ʼд�룬Ĭ����0��
* length��д����ٸ��ֽڣ�Ĭ���� buf.length - offset��
* encoding���ַ����ı��룬Ĭ����utf8��

����������

```js
var buff = Buffer.alloc(4);
buff.write('a');  // ���� 1
console.log(buff);  // ��ӡ <Buffer 61 00 00 00>

buff.write('ab');  // ���� 2
console.log(buff);  // ��ӡ <Buffer 61 62 00 00>
```

## ��䣺buf.fill(value[, offset[, end]][, encoding])

��`value`���buf�������ڳ�ʼ��buf������˵�����£�

* value�������������ݣ�������Buffer��String��Integer��
* offset���ӵڼ�λ��ʼ��䣬Ĭ����0��
* end��ֹͣ����λ�ã�Ĭ���� buf.length��
* encoding�����`value`��String����ôΪ`value`�ı��룬Ĭ����utf8��

���ӣ�

```js
var buff = Buffer.alloc(20).fill('a');

console.log(buff.toString());  // aaaaaaaaaaaaaaaaaaaa
```

## ת���ַ���: buf.toString([encoding[, start[, end]]])

��buf������ַ������÷��Ƚ�ֱ�ۣ�������

```js
var buff = Buffer.from('hello');

console.log( buff.toString() );  // hello

console.log( buff.toString('utf8', 0, 2) );  // he
```

## ת��JSON�ַ�����buf.toJSON()

```js
var buff = Buffer.from('hello');

console.log( buff.toJSON() );  // { type: 'Buffer', data: [ 104, 101, 108, 108, 111 ] }
```

## ������buf.values()��buf.keys()��buf.entries()

���ڶ�`buf`����`for...of`������ֱ�ӿ����ӡ�

```js
var buff = Buffer.from('abcde');

for(const key of buff.keys()){
    console.log('key is %d', key);
}
// key is 0
// key is 1
// key is 2
// key is 3
// key is 4

for(const value of buff.values()){
    console.log('value is %d', value);
}
// value is 97
// value is 98
// value is 99
// value is 100
// value is 101

for(const pair of buff.entries()){
    console.log('buff[%d] === %d', pair[0], pair[1]);
}
// buff[0] === 97
// buff[1] === 98
// buff[2] === 99
// buff[3] === 100
// buff[4] === 101
```

## ��ȡ��buf.slice([start[, end]])

���ڽ�ȡbuf��������һ���µ�Bufferʵ������Ҫע����ǣ����ﷵ�ص�Bufferʵ����ָ�����Ȼ��buf���ڴ��ַ�����Զ���Bufferʵ�����޸ģ�Ҳ��Ӱ�쵽buf��

```js
var buff1 = Buffer.from('abcde');
console.log(buff1);  // <Buffer 61 62 63 64 65>

var buff2 = buff1.slice();
console.log(buff2);  // <Buffer 61 62 63 64 65>

var buff3 = buff1.slice(1, 3);
console.log(buff3);  // <Buffer 62 63>

buff3[0] = 97;  // parseInt(61, 16) ==> 97
console.log(buff1);  // <Buffer 62 63>
```

## TODO

1. ��������������ȡ��ת��������
2. buffer��arraybuffer��dataview��typedarray
3. buffer vs ����
4. Buffer.from()��Buffer.alloc()��Buffer.alocUnsafe()
5. Buffer vs TypedArray

## �ĵ�ժҪ

����buffer�ڴ�ռ�Ķ�̬����

>Instances of the Buffer class are similar to arrays of integers but correspond to fixed-sized, raw memory allocations outside the V8 heap. The size of the Buffer is established when it is created and cannot be resized.

## �������

unicode���ձ�
https://unicode-table.com/cn/#control-character

�ַ�����ʼǣ�ASCII��Unicode��UTF-8
http://www.ruanyifeng.com/blog/2007/10/ascii_unicode_and_utf-8.html
