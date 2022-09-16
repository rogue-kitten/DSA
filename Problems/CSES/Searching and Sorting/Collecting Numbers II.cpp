// link to the problem -> https://cses.fi/problemset/task/2217/

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

void solve() {
	int n, m;
	cin >> n >> m;
	vi a(n + 1, 0);
	vi map(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		map[a[i]] = i;
	}
	int round = 1, prev = map[1];
	for (int i = 2; i <= n; i++) {
		if (map[i] < prev) {
			round++;
		}
		prev = map[i];
	}
	// print(round);
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		set<pair<int, int>> s;
		if (a[x] != 1)
			s.insert(mp(a[x] - 1, a[x]));
		if (a[x] != n)
			s.insert(mp(a[x], a[x] + 1));
		if (a[y] != 1)
			s.insert(mp(a[y] - 1, a[y]));
		if (a[y] != n)
			s.insert(mp(a[y], a[y] + 1));

		for (auto x : s) {
			if (map[x.first] > map[x.second])
				round--;
		}
		map[a[x]] = y;
		map[a[y]] = x;
		swap(a[x], a[y]);
		for (auto x : s) {
			if (map[x.first] > map[x.second])
				round++;
		}
		print(round);
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
