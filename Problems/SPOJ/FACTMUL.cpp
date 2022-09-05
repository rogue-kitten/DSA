// link to the problem -> 

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

const int N = 10000001;
ll Fpf1[N];
ll F1[N];
ll Fpf2[N];
ll F2[N];

void factorials() {
	Fpf1[0] = Fpf2[0] = F1[0] = F2[0] = 1;
	for (int i = 1; i < N; i++) {
		Fpf2[i] = (Fpf2[i - 1] * i) % 587117;
		F2[i] = (F2[i - 1] * Fpf2[i]) % 587117;
		Fpf1[i] = (Fpf1[i - 1] * i) % 186583;
		F1[i] = (F1[i - 1] * Fpf1[i]) % 186583;
	}
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
	return (ans + prod) % prod;
}

void solve() {
	int n;
	cin >> n;
	vll pfs{186583, 587117};
	vll rems{F1[n], F2[n]};
	print(crt(pfs, rems));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	factorials();
	solve();
}
