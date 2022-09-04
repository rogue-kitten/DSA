// link to the problem -> https://codeforces.com/contest/1722/problem/E

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
#define maxHeap  priority_queue<ll>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int N = 1003;

void solve() {
	int n, q;
	cin >> n >> q;

	ll x, y;
	ll grid[N][N] = {0};
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		grid[x][y] += (1ll * x * y);
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++)
			grid[i][j] += grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
	}
	ll hs, ws, hb, wb;
	while (q--) {
		cin >> hs >> ws >> hb >> wb;
		hb--;
		wb--;
		ll ans = grid[hb][wb] + grid[hs][ws] - grid[hb][ws] - grid[hs][wb];
		print(ans);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
