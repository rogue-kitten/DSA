# Deque
Link to the problem -> https://atcoder.jp/contests/dp/tasks/dp_l

## Approach: 
- state: `dp[i][j]: value of the difference between the two strings such that the game was played between positions i, j`
- transition: `dp[i][j]: max(a[i] - dp[i+1][j], a[j] - dp[i][j-1])`
- base case: `dp[i][i]: a[i]`
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
#define mod 9
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
	vi a(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll dp[n][n] = {0};
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (i == j)
				dp[i][j] = a[i];
			else
				dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
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