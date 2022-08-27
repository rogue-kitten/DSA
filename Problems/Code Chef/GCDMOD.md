Link to the problem: https://www.codechef.com/problems/GCDMOD

## Approach:
```
For problems of finding gcd where one of the two numbers is beyond the scope of
what we can store in any data type, we use the following method. 
1. Find the divisors of the smaller numbers. 
2. For each divisors, check which one divides a^n + b^n (use modulo props)
3. Return the max such divisor.
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

ll modularMultiplication(ll a, ll b, ll m){
	ll res = 0;
	while(b > 0){
		if(b&1ll)
			res += a;
		a *= 2;
		b = b >> 1;
		res %= m;
		a %= m;
	}
	return res;
}

ll FastModularExp(ll a, ll b, ll m){
	ll res = 1ll;

	while(b > 0){
		if(b&1ll){
			res = modularMultiplication(res, a, m);
		}
		a = modularMultiplication(a, a, m);
		b = b >> 1;
	}
	return res;
}

vll get_divisors(ll n){
	vll ans;

	for(ll i = 1; i*i <= n; i++){
		if(n%i == 0){
			ans.push_back(i);
			if(i*i != n){
				ans.push_back(n/i);
			}
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll a, b, n;
		cin >> a >> b >> n;
		//we need to first generate the divisors of (a-b)
		if(a == b){
			ll ans = FastModularExp(a, n, mod) + FastModularExp(b, n, mod);
			print(ans % mod);
			continue;
		}

		vll divisors = get_divisors(a - b);
		// now we need to check which of these divisors is the gcd. 
		ll ans = 1;
		for(auto d : divisors){
			ll a0 = FastModularExp(a, n, d), b0 = FastModularExp(b, n, d);
			if((a0+b0) % d == 0)
				ans = max(ans, d);
		}
		
		print(ans % mod);
	}
}
```
