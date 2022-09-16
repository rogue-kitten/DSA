// link to the problem -> https://cses.fi/problemset/task/1091/

#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

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

#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define mp make_pair

#define pb push_back
#define maxHeap  priority_queue<ll>
#define minHeap  priority_queue<ll, vector<ll>, greater<ll> >

#define fo(i, n) for(int i = 0; i < n; i++)
#define rfo(i, n) for(int i = n; i >= 0; i--)
#define foll(i, n) for(ll i = 0; i < n; i++)
#define rfoll(i, n) for(ll i = n; i >= 0; i--)
#define foa(i, a, b) for(int i = a; i < b; i++)

#define print_case(i, x) cout << "Case " << i << ": " << x << '\n';

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int getVal(vi &a, int x) {
	int y = lower_bound(a.begin(), a.end(), x) - a.begin();
	if (a[y] != x) {
		if (y == 0)
			return -1;
		else
			y--;
	}
	int ans = a[y];
	a.erase(a.begin() + y);
	return ans;
}

void solve() {
	int n, m, h;
	cin >> n >> m;
	multiset<int> s;
	for (int i = 0; i < n; ++i)
	{
		cin >> h;
		s.insert(h);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> h;
		auto it = s.upper_bound(h);
		if (it == s.begin())
			print(-1);
		else {
			print((*--it));
			s.erase(it);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

}
