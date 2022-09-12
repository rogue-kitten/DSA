// link to the problem-> https://www.codechef.com/submit/PBATTLE

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 109546051211
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


void solve() {
	ll n, x;
	cin >> n;
	vll a(n, 0), b(n, 0);
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]] = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	ll ans = 1;
	ll maxi = b[m[a[n - 1]]];
	for (int i = n - 2; i >= 0; i--) {
		if (b[m[a[i]]] > maxi) {
			ans++;
			maxi = b[m[a[i]]];
		}
	}
	print(ans);

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
