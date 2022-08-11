# Common BitOperations

### Finding if a number is odd or even using bits

if last bit is 1 -> no is odd, else it's even

to check if last bit is odd, do bitwise and with 1. if output is 1, that means it's odd, else if is even

```cpp
#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n & 1)
		cout << "Odd" << endl;
	else
		cout << "Even" << endl;
}
```

This is a very efficient method to find if a number is odd or even



### Getting the i<sup>th</sup> bit in a number

Approach for this -> create a mask.
* Create a number such who's i<sup>th</sup> bit is 1, rest all are zero (let's call this new number as the mask). We will use left shift operator for this.
* do bitwise and operation between the number and the mask. if the ans is greater than zero, means that the i<sup>th</sup> bit was 1, if the ans was zero, the i<sup>th</sup> bit was zero.

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, i;
	cin >> n >> i;
	int mask = 1 << i; // mask will have only the ith bit set. 	
	cout << (int)((n & mask) > 0) << endl;
}
```

### Setting the i<sup>th</sup> bit of a number

Approach -> create a suitable mask and do bitwise or with that mask
* Mask -> 1 << i
* then perform an or with the number to get the ans

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, i;
	cin >> n >> i;
	int mask = 1 << i;
	cout << (n | mask) << endl;
}
```

### Clearing the i<sup>th</sup> bit of a number

3 step approach
* get a number who's i<sup>th</sup> bit is set(1 << i)
* negate this number to get our mask(this mask will have all bits as 1 except the ith bit, which will be 0)
* then perform an and operation between the two

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, i;
	cin >> n >> i;
	int mask = ~(1 << i);
	cout << (n & mask) << endl;
}
```
### Update bit at position i

You will be given a number n, a position i and another number v(either 0 or 1). You need to update the ith bit of the number to v.

Approach
* Clear the bit at that position. 
* create a mask such that v is at the i<sup>th</sup> place and all others are zero. Then perform OR operation.

```cpp
#include <iostream>

using namespace std;

int main(){
	int n, i, v;
	cin >> n >> i >> v;
	// step 1: clearing the ith bit
	int mask = ~(1 << i);
	int ans = n & mask;
	// step 2, creating a mask and doing the or operation. 
	mask = v << i;
	ans = ans | mask;
	cout << ans << endl;
}
```
