// link to the problem -> https://www.spoj.com/problems/CSQUARE/

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
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


ll FastModularExp(ll a, ll b, ll m) {
	ll res = 1ll;
	a %= m;
	while (b > 0) {
		if (b % 10) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b = b >> 1;
	}
	return res;
}

void solve() {
	ll a, m;
	string b;
	cin >> a >> b >> m;
	// print(b);
	// print(b[0]);
	// print(m);
	ll ans = 1ll;
	int n = b.size();

	for (int i = n - 1; i >= 0; i--) {
		if (b[i] != '0') {
			ans = (ans * a) % m;
			if (b[i] == '2') {
				ans = (ans * a) % m;
			}
		}
		a = FastModularExp(a, 3, m);
	}
	print(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
}
