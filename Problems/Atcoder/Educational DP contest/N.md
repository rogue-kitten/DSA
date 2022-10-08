# Slimes
Link to the problem -> https://atcoder.jp/contests/dp/tasks/dp_n

## Approach: 
- Think about the last merge we will do: 
	- at some point we will be left with only 2 elements. 
	- The values of the two elements would depend upon the prefix sum of the first one and the suffix sum of the second one. 
	- So we fix what those prefixes will be (that is, saying that you will merge everyone from 1 to i before merging it with everyone from i+1 to n), we know exactly what will be the cost of the last operation. 
	- Now, here is the thing, if we do fix the last operation, we only care about what is the optimal way of merging a prefix of the array and a suffix of the array, which is the same subproblem that we had in the statrt!
- Hence, the state would be: `dp[i][j]: minimum cost of merging all the elements from i to j `
- Transition: `dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[i:j]) for all the values of k lying in the range.`
- Base case `dp[i][i] = 0`
- Final Answer: `dp[0][n-1]`

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
	int n;
	cin >> n;
	vll a(n, 0), sum(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (i)
			sum[i] = sum[i - 1];
		sum[i] += a[i];
	}

	vvll dp(n, vll(n, 1e18));
	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = 0;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			ll pre = sum[j];
			if (i)
				pre -= sum[i - 1];
			for (int k = i ; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + pre);
			}
		}
	}
	print(dp[0][n - 1]);
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