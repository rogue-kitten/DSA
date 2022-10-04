Link to the problem -> https://atcoder.jp/contests/dp/submissions/me

## Approach: 
- State: `dp[i][j]: probability of having j exactly j heads by tossing the first i coins`
- Transition: `dp[i][j] = (dp[i - 1][j - 1] * a[i - 1]) + (dp[i - 1][j] * (1 - a[i - 1]));`
	- To get exactly `j` heads from the first i coins, we have 2 options for the i'th coin, either it will land a head, or a tail. If it is a head, then we need exactly `j-1` heads from the remaining `i-1` tosses. If it is a tails, then we need exactly `j heads` from the remaining i-1 tosses
- Base case: `dp[0][0] = 1`
	- this basically means that the probability of getting zero heads from zero tosses which will always be equal to one. 
- Final ans `dp[n][i] where i > n/2`

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
#define vvd vector<vector<double>>

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
	int n;
	cin >> n;
	vd a(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vvd dp(n + 1, vd(n + 1, 0.000));
	dp[0][0] = 1.00;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] =  (dp[i - 1][j] * (1 - a[i - 1]));
			if (j)
				dp[i][j] += (dp[i - 1][j - 1] * a[i - 1]);

		}
	}

	double ans = 0.00;
	for (int i = n / 2 + 1; i <= n; i++) {
		ans += dp[n][i];
	}
	cout << setprecision(12) << fixed << ans << endl;
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