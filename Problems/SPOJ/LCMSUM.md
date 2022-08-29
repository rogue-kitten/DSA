Link to the problem -> https://www.spoj.com/problems/LCMSUM/

## Approach
```
1. We can derive the formula for the lcm sum of n numbers as 
   ∑LCM(i, n) = ((∑(d * phi(d)) + 1) * n) / 2, where d is the divisor of n.
2. Based on this formula, we precompute the value of d*phi(d) for every divisor of n
   using an approach similar to sieve. 
3. TC -> O(Nlog(logN)) for precompute and O(1) for every query
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
#define print(a) cout << a << '\n'
#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

const int N = 1000010;
ll phi[N];
ll res[N] = {0};

void sieve(){
	for(int i = 1; i < N; i++){
		phi[i] = i;
	}

	for(int i = 2; i < N; i++){
		if ( phi[i] == i ) {
	        for ( int j = i; j < N; j += i ) {
	            phi[j] /= i;
	            phi[j] *= (i - 1);
	        }
	    }
	}

	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j += i){
			res[j] += (i*phi[i]);
		}
	}
}

void solve(){
	int n;
	cin >> n;
	ll ans = res[n] + 1;
	ans *= n;
	ans /= 2;
	print(ans);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	sieve();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
}
```
