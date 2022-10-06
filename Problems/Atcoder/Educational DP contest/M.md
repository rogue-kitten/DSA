# Candies
Link to the problem -> https://atcoder.jp/contests/dp/tasks/dp_m

## Approach:
- state: `dp[i][x]: number of ways to distribute x candies among the first i children such that each child does not reciceve more than he is supposed to`
- transition: `dp[i][x]: dp[i-1][x] + dp[i-1][x-1] + dp[i-1][x-2] + ... + dp[i-1][x - a[i]]`
	- To save time, we store the values of the previous state in a prefix sum. 
- base case `dp[0][0]: 1`
- final ans: `dp[n][k] `

## Code
```cpp
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define ull unsigned long long
#define md 1000000007
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vb vector<bool>
#define vd vector<double>

#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvs vector<vector<string>>

#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>

#define endl '\n'
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl
#define noo cout << "NO" << endl;
#define yess cout << "YES" << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define mp make_pair

#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<ll, vector<ll>, greater<ll>>

#define fo(i, n) for(int i = 0; i < n; i++)
#define rfo(i, n) for(int i = n; i >= 0; i--)
#define foll(i, n) for(ll i = 0; i < n; i++)
#define rfoll(i, n) for(ll i = n; i >= 0; i--)
#define foa(i, a, b) for(int i = a; i < b; i++)

#define print_case(i, x) cout << "Case " << i << ": " << x << '\n';

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
	ll n, k; cin >> n >> k;
	ll a[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> a[i];

	vector<ll> dp(100005, 0);
	dp[0] = 1;
	for (ll i = 1; i <= n; i++) {
		vector<ll> pre(100005, 0);
		for (ll j = 0; j <= k; j++) {
			pre[j + 1] = (pre[j] + dp[j]) % md;
		}
		vector<ll> temp(100005, 0);
		temp[0] = 1;
		for (ll j = 1; j <= k; j++) {
			ll l = max(0LL, j - a[i]);
			temp[j] = (pre[j + 1] - pre[l] + md) % md;
		}
		dp = temp;
	}
	cout << dp[k];

}

int main() {
	fastio();
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}
```
#dp 