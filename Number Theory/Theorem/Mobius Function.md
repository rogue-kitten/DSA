# Mobius Function

## Definition
```
For any integer n, we define meu(n) as the sum of the primitive nth roots of 
unity. It has the values {-1, 0, 1} depending on the factorisation of n into its
prime factors. 
meu(n) = 1 if n is a square free positive integer with even number of prime factors
meu(n) = -1 if n is a square free positive integer with odd number of prime factors
meu(n) = 0 if n is a squared number

square free means all the prime factors have a power of 1. 

All the prime numbers have meu value as -1

meu(1) = 1
meu(2) = -1
meu(3) = -1
meu(4) = 0
meu(5) = -1
meu(6) = 1 (2*3)
meu(7) = -1
meu(8) = 0 (2*2*2)
meu(9) = 0 (3*3)
meu(10) = 1
```

## Approach
```
How to generate all the mobius values effectively for N (N < 10^5)?

1. generate primes using sieve
2. create an array of size n and initialise it with 1 at the begining. 
3. also create another array to store how many primes are required to form the no.
3. now for every prime p, multiple p to all the arr[k*p]. 
4. At the end, if a[i] == i then the number is formed by exactly distinct primes
   and is free of any squares. Then check the no of primes to put 1 or -1. 
```

## Code
```cpp
const ll N = 100005;
vll arr(N, 1), prime_count(N, 0);

void mobius(){
	ll i, j;
	for(i = 2; i < N; i++){
		if(prime_count[i]) // not a prime no. 
			continue;
		for(j = i; j < N; j += i){
			prime_count[j]++;
			arr[j] *= i;
		}
	}

	for(int i = 1; i < N; i++){
		if(arr[i] == i){
			if(prime_count[i]&1)
				arr[i] = -1;
			else
				arr[i] = 1;
		}
		else
			arr[i] = 0;
	}
}

int main(){
	mobius();
	for(int i = 1; i < 30; i++){
		cout << arr[i] << " ";
	}

}
```



