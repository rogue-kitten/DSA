# Knapsack -2 
Link to the problem -> https://atcoder.jp/contests/dp/tasks/dp_e

## Approach: 
- This problem is highly similar to the previous one, but with the only difference that the values of weight go upto 1e9. 
- However, if we apply the same approach that we used in the previous one, it would give us tle. 
- Hence, we need to change the dp state which we had defined so that the loops run till a lower value. 
- State: `dp[i][j]: min weight of the first i items such that their values are equal to j `
	- from the constraints, we also see that the max sum of values can go upto 1e5. Hence this is an acceptable solution
- transition: `dp[i][j]: min(dp[i-1][j], dp[i-1][j-v[i]] + w[i])`
- base cases: `dp[0][0]= 0, rest all would be a very large number(1e9)`
- final answer :`max value of i such that dp[n][i] <= x (given weight)`

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
#define mod 1000000007
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
#define vvpii vector<vpii>
#define mp make_pair

#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<ll, vector<ll>, greater<ll>>

#define fo(i, n) for(int i = 0; i < n; i++)
#define rfo(i, n) for(int i = n; i >= 0; i--)
#define foll(i, n) for(ll i = 0; i < n; i++)
#define rfoll(i, n) for(ll i = n; i >= 0; i--)
#define foa(i, a, b) for(int i = a; i < b; i++)

#define print_case(i) cout << "Case #" << i << ": ";

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
	int n, x;
	cin >> n >> x;
	vi w(n, 0), v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> w[i] >> v[i];
	}
	int vmax = 1e5;
	vvll dp(n + 1, vll(vmax + 1, 1e9 + 1));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= vmax; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - v[i - 1] >= 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
		}
	}
	for (int i = vmax; i > 0; i--) {
		if (dp[n][i] <= x) {
			print(i);
			break;
		}
	}
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