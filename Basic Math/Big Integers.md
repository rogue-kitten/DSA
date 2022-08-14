# Big Factorial

In cpp, the range of int -> 10<sup>9</sup> and long long -> 10<sup>18</sup>

To get the factorial of a large no(100), we need to store the digits of the number in an array and perform multiplication by n.

## Approach
```
1. create an array of the size of the max number of digits in the ans, initialise with 0 (integers would be stored in the reverse order in this array)
2. put a[0] = 1;
3. run a loop for i = 1 to n
	a. multiply each digit of the array with n(take care of the carry)
4. print the array in the reverse order
```

## Code
```cpp
#include<bits/stdc++.h>

using namespace std;
//we are passing the no of digits by reference since we will need it later to print the array (to prevent printing extra zeros before the number)
void multiply(int *a, int n, int &digits){ 
	int carry = 0, prod;
	for(int i = 0; i < digits; i++){
		prod = (a[i]*n) + carry;
		carry = prod/10;
		a[i] = prod % 10;
	}
	while(carry){
		a[digits] = carry % 10;
		carry /= 10;
		++digits;
	}
}

void big_factorial(int n){

	int *a = new int[1000]; //assuming the answer has 1000 digits at max;
	for(int i = 0; i < 1000; i++){
		a[i] = 0;
	}

	a[0] = 1;
	int digits = 1; // will have the number of digits at any instance
	for(int i = 2; i <= n; i++){
		multiply(a, i, digits);
	}

	for(int i = digits - 1; i >= 0; i--)
		cout << a[i];
	cout <<"\n";
}

int main(){
	
	int n;
	cin >> n;
	big_factorial(n);
	return 0;
}
```

## Side Note

While facing large numbers, if possible do it in python, because it handles these cases internally. 
```py
n = int(input())

ans = 1
for i in range(1, n + 1):
	ans = ans * i
print(ans)
```
