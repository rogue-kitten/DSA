// link to the problem -> https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A

// Apply binary search on the time, and for every middle time we get base don the limts, find the range of 
// the ranges of the distance the person can reach to in time t. If this range intersects for all the people, 
// then this time is possible and we find a smaller one, else we find a larger time span.

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

const double eps = 1e-6;
const int N = 1e5;
vd x(N, 0.0);
vd v(N, 0.0);
int n;

bool good(double m) {
	double start = -1e9, end = 1e9;
	for (int i = 0; i < n; i++) {
		start = max(start, x[i] - v[i] * m);
		end = min(end, x[i] + v[i] * m);
		if (start > end)
			return false;
	}
	return true;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i];
	}

	double s = 0, e = 1, m, ans = -1;
	while (!good(e))  e *= 2.00;
	while (e - s > eps) {
		m = s + (e - s) / 2;
		if (good(m)) {
			ans = m;
			e = m;
		}
		else
			s = m;
	}
	cout << setprecision(10) << fixed << s + (e - s) / 2;
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
