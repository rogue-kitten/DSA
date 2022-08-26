Link to problem -> https://www.spoj.com/problems/DCEPC11B/

## Approach
```
Direct application of wilson's theorem. [(p-1)! % p = p - 1, if p is prime]
1. Trivial case => n >= p straight return 0, since p%p = 0.
2. for the case n < p, we know that from wilsons theorem
    (p-1)! mod p = (p-1)
    this n! mod p = [(p-1) / (n+1)(n+2)...(p-1)] mod p. [you need to take modular inverse here
3. This one will work because we have been told that n and p lie near each other
```

## Code
```cpp
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
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

ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b); }

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

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, p;
		cin >> n >> p;

		if(n >= p){
			print(0);
			continue;
		}

		ll ans = 1;
		for(ll i = n + 1; i < p; i++){
			ans = (ans * i) % p;
		}

		ans = ((p-1) * modularInverse(ans, p)) % p;
		print(ans);
	}
}
```

