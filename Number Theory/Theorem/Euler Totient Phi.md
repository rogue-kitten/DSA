# Euler Toitent Phi Function

```
Phi(n) = no of positive numbers that are less than n and are co-prime with n. 
co-prime = gcd is 1. 

Phi(8) = [1,3,5,7] = 4;
Phi(9) = [1,2,4,5,7,8] = 6;
```

## General Formula
```
phi(n) = n*[1-(1/p1)]*[1-(1/p2)]*[1-(1/p3)] .....
Where, p1,p2,p3 are the prime factors of n. 
```
## Code for single queries
```cpp
vi primeFactors(int n){
	vector<int> ans;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			int occ = 0;
			while(n%i == 0){
				occ++;
				n /= i;
			}
			ans.push_back(i);
		}
	}
	if(n != 1){
		ans.push_back(n);
	}

	return ans;
}

int main(){
	int n;
	cin >> n;
	vi factors = primeFactors(n);

	ll phi = n;
	for(auto x : factors){
		n = n - n/x;
	}
	print(n);

}
```

## Code for large number of queries
Using the prime sieve method to compute all the primes untill the maximum range 
and then using that to get the prime factor for every query in logn time. 
```cpp
vector<int> prime_sieve(int *p, int n){
	p[0] = p[1] = 0;
	p[2] = 1;
	vector<int> primes;
	primes.push_back(2);
	//mark all the odd numbers as prime initially
	for(int i = 3; i <= n; i+=2){
		p[i] = 1;
	}

	//optimisation -> run only through the odd numbers
	for(int i = 3; i <= n; i+=2){
		if(p[i]){
			primes.push_back(i);
			for(int j = i*i; j <= n; j+= i){
				p[j] = 0;
			}
		}
	}
	return primes;

}

vector<int> factorize(int n, vector<int> &primes){
	vector<int> ans;

	for(auto x : primes){
		if(x*x > n)
			break;
		if(n%x == 0){
			ans.push_back(x);
			while(n%x == 0){
				n /=x;
			}
		}
	}
	if(n != 1)
		ans.push_back(n);
	return ans;
}

int main(){
	int N = 1000000;
	int p[N] = {0};
	vector<int> primes = prime_sieve(p, 100);

	// printall(primes);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		vi factors = factorize(n ,primes);

		for(auto x : factors){
			n = n - n/x;
		}
		print(n);

	}
}
```
