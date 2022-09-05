// link to the problem -> https://www.spoj.com/problems/DIVSUM/

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


const ll N = 500001;
bool sieve[N] = {0};
vll primes;

void prime_sieve() {
	primes.pb(2);
	for (int i = 3; i < N; i += 2) {
		sieve[i] = true;
	}

	for (int i = 3; i < N; i += 2) {
		if (sieve[i]) {
			primes.pb(i);
			for (int j = i * i; j < N; j += i) {
				sieve[i] = false;
			}
		}
	}
}

ll FastExp(ll a, ll b) {
	ll res = 1ll;
	while (b > 0) {
		if (b & 1ll) {
			res *= a;
		}
		a *= a;
		b = b >> 1;
	}
	return res;
}

void solve() {
	ll n, temp;
	cin >> n;
	temp = n;
	ll sum = 1ll;
	for (auto x : primes) {
		if (x * x > n)
			break;
		if (n % x == 0) {
			int occ = 0;
			while (n % x == 0) {
				occ++;
				n /= x;
			}
			ll num = FastExp(x, occ + 1) - 1;
			ll denom = x - 1;

			sum *= (num / denom);
		}
	}
	if (n != 1) {
		sum *= (n + 1);
	}
	print(sum - temp);

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	prime_sieve();
	cin >> t;
	while (t--) {
		solve();
	}
}
