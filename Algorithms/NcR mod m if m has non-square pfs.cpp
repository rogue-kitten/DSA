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

const int N = 1e6 + 5;
ll F[N];

vll get_factors(ll m) {
	vll ans;
	for (ll i = 2; i * i <= m; i++) {
		if (m % i == 0) {
			ans.pb(i);
			m /= i; // given that it has non square pfs only.
		}
	}
	if (m != 1)
		ans.pb(m);
	return ans;
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

ll lucas(ll n, ll r, ll m) {
	if (r > n)
		return 0;
	if (r == 0 || n == r)
		return 1;
	ll num = F[n] % m;
	ll denom = (F[r] * F[n - r]) % m;
	ll ans = (num * modularInverse(denom, m)) % m;
	return ans;
}

ll ncr(ll n, ll r, ll m) {
	if (r == 0 || n == r)
		return 1;
	if (n < r)
		return 0;
	ll ans = 1ll;
	F[0] = 1;
	for (int i = 1; i < m; i++) {
		F[i] = (F[i - 1] * i) % m;
	}
	while (n > 0 && r > 0) {
		ll n1 = n % m;
		ll r1 = r % m;
		n /= m;
		r /= m;
		ans = (ans * lucas(n1, r1, m)) % m;

	}
	return ans;
}

ll crt(vll &nums, vll &rem) {
	ll prod = 1;
	int k = nums.size();
	for (int i = 0; i < k; i++) {
		prod *= nums[i];
	}
	ll ans = 0;

	for (int i = 0; i < k; i++) {
		ll ppi = prod / nums[i];
		ans += (rem[i] * ppi * modularInverse(ppi, nums[i])) % prod;
	}
	return ans % prod;
}

void solve() {
	ll n, r, m;
	cin >> n >> r >> m;
	if (r == 0 || n == r) {
		print(1);
		return;
	}
	if (r > n) {
		print(0);
		return;
	}
	// generates the pfs of m
	vll facts = get_factors(m);
	// precomputing the factorials under mod m
	vll remainders(facts.size(), 0);
	for (int i = 0; i < facts.size(); i++) {
		remainders[i] = ncr(n, r, facts[i]);
	}

	// applying the crt formula
	print(crt(facts, remainders));
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
