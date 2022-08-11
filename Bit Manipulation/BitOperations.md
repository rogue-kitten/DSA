# Bitwise shift operators

& -> and

| -> or

~ -> not

^ -> xor (exculsive or)


### And Gate

***Both the bits must be 1***

0 & 0 = 0

0 & 1 = 0

1 & 0 = 0

1 & 1 = 1

### Or Gate

***Atleast 1 bit must be 1***

0 | 0 = 0

0 | 1 = 1

1 | 0 = 1

1 | 1 = 1


### Not Gate

***Flip all bits***

~0 = 1

~1 = 0

### Xor Gate

***Excatly 1 but must be 1***

0 ^ 0 = 0

0 ^ 1 = 1

1 ^ 0 = 1

1 ^ 1 = 1


All these operators are binary operators -> they require two elements

eg) a = 5, b = 7, find a & b

In binary,

a = 101

b = 111 -> then and of the 2 gives

c = 101 => 5 in decimal


eg) a = 5, b = 6, find a | b

a = 101

b = 110

c = 111 => 7 in decimal



eg) a = 5, b = 7, a ^ b

a = 101

b = 111

c = 010 => 2 in decimal



**Imp property of XOR**
* Xor of same numbers is always zero -> 5 ^ 5 = 0
* Xor of any number with zero is the number itself -> 5 ^ 0 = 5;
* eg) 5 ^ 7 ^ 5 => 7 (5^5 is 0 and 0 ^ 7 is 7)


### Shift operators

<< => left shit

>> => right shift

5 << 1 -> this means that we will shift all the bits of 5 by one place to the left. the left most bit will be discarded and a zero will be added to the end

5 == 00101

5 << 1 ==01010 => 10

***left shift by 1 means that you have multiplied the number by 2***

a << 1 => a * 2

a << 2 => a * 2<sup>2</sup>

***To generalise***

a << b == a * 2<sup>b</sup>




Right shift performs the opposite(discards the rightmost bit and add a zero to the left in binary)

a >> b == a / a<sup>b</sup>
