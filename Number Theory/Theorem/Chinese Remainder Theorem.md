# Chinese Remainder Theorem

```
The CRT is used to solve a system of linear congruences. 

What is a linear congruence?
It is a way of representing modular equations

x%m = 1 => x => 1 mod m

System of linear congruences => a bunch of such equations. 
x % 2 = 1; x = 1 mod 2
x % 7 = 5; x = 5 mod 7
x % 3 = 2; x = 2 mod 3

In such equations, we use the crt to find the value of x satisfying these equations. 

Generalised form
x % num0 = rem0
x % num1 = rem1
x % num2 = rem2
```

## Approach 1: Brute Force
```
Run a loop from 1 till we get a value of x satisfying the equations. 
There can be multiple ans to this equation, since we are taking a mod. 
```

## Approach 2: Using the Chinese Remainder Theorem
```
Formula: 
x = sum(rem[i]*pp[i]*inv[i]) % prod. Here
rem[i] = i'th remainder term. 
prod = product of all the nums
pp[i] = product of all nums excpet the ith num (prod/num[i])
inv[i] = modular multiplicative inverse of pp[i] wrt num[i].


Intuition behind the formula. 
```

## Code
``` cpp
ll modularInverse(ll a, ll m){
	if(m == 1)
		return 0;
	ll m0 = m, y = 0, x = 1;

	while(a  > 1){
		ll q = a / m, t = m;
		m = a % m, a = t;
		t = y;
		y = x - q*y;
		x = t;
	}

	if(x < 0)
		x += m0;

	return x;
}

ll crt(vi &nums, vi &rem, int k){
	ll prod = 1;
	for(int i = 0; i < k; i++){
		prod *= nums[i];
	}
	ll ans = 0;

	for(int i = 0; i < k; i++){
		ll ppi = prod/nums[i];
		ans += (rem[i]*ppi*modularInverse(ppi, nums[i])) % prod;
	}
	return ans;
}

int main(){
	int k;
	cin >> k;
	vi nums(k), rem(k);
	for(int i = 0; i < k; i++){
		cin >> nums[i];
	}
	for(int i = 0; i < k; i++){
		cin >> rem[i];
	}

	print(crt(nums,rem, k));

}
```
