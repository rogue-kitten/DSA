// link to the problem -> https://www.codechef.com/submit/DISTNUMS

#include<bits/stdc++.h>

using namespace std;
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

#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << '\n'

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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll FastModularExp(ll a, ll b, ll m) {
	ll res = 1ll;
	a %= m;
	while (b > 0) {
		if (b & 1ll) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b = b >> 1;
	}
	return res;
}

ll modularInverse(ll a, ll m) {
	if (m == 1)
		return 0;
	ll m0 = m, y = 0, x = 1;

	while (a  > 1) {
		ll q = a / m, t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}

	if (x < 0)
		x += m0;

	return x;
}

ll powerSq(ll n, ll k) {
	if (k < 30) {
		return FastModularExp(n, (1 << k), mod);
	}
	ll temp = FastModularExp(2, k, mod - 1);
	return FastModularExp(n, temp, mod);
}

ll ans(ll n, ll p, ll k) {
	ll x1 = powerSq(n, k);
	ll x2 = FastModularExp(n, p - 1, mod);
	ll x3 = FastModularExp(x1, p, mod);
	ll x4 = modularInverse(n - 1, mod);

	return ((((x3 - x2 + mod) * x4) % mod) * n) % mod;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	ll res = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int p = 0;
			while (n % i == 0) {
				p++;
				n /= i;
			}
			res = (res * ans(i, p, k)) % mod;
		}
	}
	if (n != 1)
		res = (res * ans(n, 1, k)) % mod;
	print(res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}
