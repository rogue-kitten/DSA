## Problem:
```
PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries b
etween a and b (inclusive) , However due to shortage of time he can't visit each and every country , 
So PM Modi decides to visit only those countries,for which country number has two divisors. So your 
task is to find number of countries Mr. Modi will visit.

Constraints:
a<=1000000 & b<=1000000.
N<=1000
```

## Approach
```
We need to precompute the sieve instead of running the sieve function for every query to save time. 
We can also precompute the cumulative count of primes until a number n to run all the queries in linear time.
```
## Code
```cpp
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 98765431
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vvi vector<vector<int>>
#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl
#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

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
	int t;
	cin >> t;

	// precomputing the prime sieve and the cumulative number of primes until n. 
	int sieve[1000005] = {0};
	prime_sieve(sieve);
	int cumSum[1000005] = {0};
	for(int i = 1; i <= 1000000; i++){
		cumSum[i] = cumSum[i-1] + sieve[i];
	}
	
	while(t--){
		int a, b;
		cin >> a >> b;

		print(cumSum[b] - cumSum[a-1]);
	}
}
```

TC -> O(N + 1e6) where N is the no of queries. 
