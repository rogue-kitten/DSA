// link to the problem -> https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 109546051211
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vb vector<bool>

#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvs vector<vector<string>>

#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>

#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << '\n'

#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define pb push_back
#define maxHeap  priority_queue<ll>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

#define fo(i, n) for(int i = 0; i < n; i++)
#define rfo(i, n) for(int i = n; i >= 0; i--)
#define foll(i, n) for(ll i = 0; i < n; i++)
#define rfoll(i, n) for(ll i = n; i >= 0; i--)
#define foa(i, a, b) for(int i = a; i < b; i++)

#define print_case(i, x) cout << "Case " << i << ": " << x << '\n';

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

unordered_map<char, int> freq;
ll nb, ns, nc, pb, ps, pc, r;
// b, s, c
bool good(ll m) {
	ll tb = m * freq['B'], ts = m * freq['S'], tc = m * freq['C'];
	tb = max(0ll, tb - nb);
	ts = max(0ll, ts - ns);
	tc = max(0ll, tc - nc);

	ll cost = tb * pb + ts * ps + tc * pc;
	return cost <= r;
}

void solve() {
	string str;
	cin >> str;
	for (auto x : str) {
		freq[x]++;
	}
	cin >> nb >> ns >> nc >> pb >> ps >> pc;
	cin >> r;

	ll s = 0, e = 1, m, ans;
	while (good(e)) e = e << 1;

	while (s <= e) {
		m = s + (e - s) / 2;
		if (good(m)) {
			ans = m;
			s = m + 1;
		}
		else
			e = m - 1;
	}
	print(ans);
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
