**数据存储**
**一、	原码、反码、补码**
*1、计算机中整形有符号数和无符号数有原码、反码、补码三种表示方式。*
*整形分为：（有符号位/无符号位）*
a、	char ：signed char/unsigned char
b、	short：signed short/unsigned short
c、	 int：  signed int / unsigned int
d、	long：signed long/unsigned long

2、数据在计算机中以补码存储在内存中，并以补码进行运算。

```c
Int a = 20;
//原码：0000 0000 0000 0000 0000 0000 0001 0100
//反码：0000 0000 0000 0000 0000 0000 0001 0100
//补码：0000 0000 0000 0000 0000 0000 0001 0100
//内存： 0    0	   0	   0	   0	   0	   1	   4
//以小端存储，故为：14 00 00 00 


Int b = -10;
//原码：1000 0000 0000 0000 0000 0000 0000 1010
//反码：1111 1111 1111 1111 1111 1111 1111 0101
//补码：1111 1111 1111 1111 1111 1111 1111 0110
//内存： F    F    F    F    F    F    F    6
//以小端存储，故为：F6 FF FF FF 
```

**二、	大端、小端**
1、	大端（存储）模式：指数据低位保存在内存高地址，而数据高位保存在内存低地址。
2、	小端（存储）模式：指数据低位保存在内存低地址，而数据高位保存在内存高地址。
