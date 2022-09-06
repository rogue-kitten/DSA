// link to the problem -> https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

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

bool isPossible(ll w, ll h, ll n, ll x) {
	if ((x / w) * (x / h) * 1ll >= n)
		return true;
	return false;
}

void solve() {
	ll w, h, n;
	cin >> w >> h >> n;
	ll s = 0, e = 1, m, ans = -1;
	while (!isPossible(w, h, n, e))
		e = e << 1;
	while (s <= e) {
		m = s + (e - s) / 2;
		if (isPossible(w, h, n, m)) {
			ans = m;
			e = m - 1;
		}
		else
			s =  m + 1;
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
