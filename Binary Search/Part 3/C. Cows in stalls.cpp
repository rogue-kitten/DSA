// link to the problem -> https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C

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

const int N = 1e4 + 1;
vll stalls(N, 0);
int n, k;

bool good(ll m) {
	int cows = 1, prev = 0;
	for (int i = 1; i < n; i++) {
		if (stalls[i] - stalls[prev] >= m) {
			prev = i;
			cows++;
			if (cows == k)
				return true;
		}
	}
	return false;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> stalls[i];
	}
	ll s = 0, e = stalls[n - 1] - stalls[0], m, ans = -1;

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
