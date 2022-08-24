# Prime Sieve

Sieve of Eratosthenes and it's optimisations. 

```
A quick refresher:
1. A prime number is a number which has only 2 divisors, one and the number it self. 
2. Brute force method of checking if a number is prime or not: we try to divide
   it by all numbers in the range of [2:n-1] and if any one of these divides the 
   number, it's not a prime. 
   TC -> O(N) for one number
   		 O(N*N) for N numbers

3. A slight better way of computing this would be instead of iterating the loop
   from [2:N-1], we do it from [2:sqrt(N)]. 
   TC -> O(sqrt(N)) for one number
		  O(N*sqrt(N)) for N numbers
```

## Sieve of Eratosthenes
```
1. In this method, we directly generate an array containing prime numbers

Approach:
1. Create an array containing all the numbers from 1 - N. Initially we assume
   all the numbers to be prime.  
2. Start a loop from 2 to N and repeat the following steps:
	a. If the number if marked as prime, then mark all the multiples of this
	   number in the sieve as not prime. 
	b. Do nothing if it is already marked as not prime. 
3. Optimisation of the above: 
   a. In loop, were starting from the next multiple of the prime number. But, 
   	  we can start instead from n*n (based on the property that for a given 
   	  no less than n, there exists atleast one divisor which is less than
   	  sqrt(n), if the no is not prime). 
   b. Earlier, we were running the loop like p+p,p+2p, p+3p....
   	  Now, we will run the loop as p*p, p*p + p, p*p +2p ....
4. Another optimisation we can add to this is that all the even numbers can be skipped[except 2]

TC -> O(N/2 + N/3 + N/5 + N/7 ... ) == O(N*log(logN)) which is approximately linear. 
```

## Optimised code
```cpp
// 1 marks for prime, zero marks for not prime. 
void prime_sieve(int *p){
	// skip all even numbers and mark all odd as prime. 
	for(int i = 3; i <= 1000000; i+=2){
		p[i] = 1;
	} 

	//main sieve code
	for(ll i = 3; i <= 1000000; i++){
		if(p[i]){
			// marks all the multiples of i as not prime. 
			for(ll j = i*i; j <= 1000000; j += i){
				p[j] = 0;
			}
		}
	}

	// base cases
	p[2] = 1;
	p[1] = p[0] = 0;
}

int main(){
	int n;
	cin >> n;

	int sieve[1000005] = {0};
	prime_sieve(sieve);

	for(int i = 0; i<= n; i++){
		if(sieve[i])
			cout << i << " ";
	}

}
```
