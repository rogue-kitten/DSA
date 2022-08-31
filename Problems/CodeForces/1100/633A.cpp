https://codeforces.com/contest/633/problem/A

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

#define mp make_pair
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

ll gcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

void shift_solution(ll &x, ll &y, ll a, ll b, ll cnt) {
	x += cnt * b;
	y -= cnt * a;
}

void solve() {
	ll a, b, c, x, y, g;
	cin >> a >> b >> c;
	// degenerate case
	if (a == 0 && b == 0) {
		if (c == 0) {
			print("YES");
			return;
		}
		print("NO");
		return;
	}

	g = gcd(a, b, x, y);

	if (c % g) {
		print("NO");
		return;
	}

	x *= c / g;
	y *= c / g;

	a /= g;
	b /= g;

	ll minx = 0, miny = 0, maxx = c / a, maxy = c / b;
	// print(maxx);
	// print(maxy);
	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution(x, y, a, b , 1);
	if (x > maxx) {
		print("NO");
		return;
	}
	ll lx1 = x;

	shift_solution(x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution(x, y, a, b , -1);
	ll rx1 = x;

	shift_solution(x, y, a, b, -(miny - y) / a);
	if (y < miny)
		shift_solution(x, y, a, b, -1);
	if (y > maxy) {
		print("NO");
		return;
	}
	ll lx2 = x;

	shift_solution(x, y, a, b, -(maxy - y) / a);
	if (y > maxy)
		shift_solution(x, y, a, b, 1);
	ll rx2 = x;

	if (lx2 > rx2)
		swap(lx2, rx2);

	ll lx = max(lx1, lx2);
	ll rx = min(rx1, rx2);

	if (lx > rx) {
		print("NO");
		return;
	}

	print("YES");

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}
