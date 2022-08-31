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

void solve(int i) {
	ll a, b, c, x, y, g, x1, x2, y1, y2;
	cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
	// degenerate case
	if (a == 0 && b == 0) {
		if (c == 0) {
			print_case(i, (x2 - x1 + 1) * (y2 - y1 + 1));
			return;
		}
		else {
			print_case(i, 0);
			return;
		}
	}

	c = -c;
	// zero case
	if (a == 0) {
		// print("ENTER");
		if (c % b) {
			print_case(i, 0);
			return;
		}

		y = c / b;
		if (y >= y1 && y <= y2) {
			print_case(i, x2 - x1 + 1);
			return;
		}
		print_case(i, 0);
		return;
	}
	if (b == 0) {
		if (c % a) {
			print_case(i, 0);
			return;
		}

		x = c / a;
		if (x >= x1 && x <= x2) {
			print_case(i, y2 - y1 + 1);
			return;
		}
		print_case(i, 0);
		return;
	}

	g = gcd(abs(a), abs(b), x, y);

	if (c % g) {
		print_case(i, 0);
		return;
	}

	x *= c / g;
	y *= c / g;

	if (a < 0)
		x = -x;
	if (b < 0)
		y = -y;

	a /= g;
	b /= g;

	int sign_a = a < 0 ? -1 : 1;
	int sign_b = b < 0 ? -1 : 1;
	// print(maxx);
	// print(maxy);
	shift_solution(x, y, a, b, (x1 - x) / b);
	if (x < x1)
		shift_solution(x, y, a, b , sign_b);
	if (x > x2) {
		print_case(i, 0);
		return;
	}
	ll lx1 = x;
	// print(x);

	shift_solution(x, y, a, b, (x2 - x) / b);
	if (x > x2)
		shift_solution(x, y, a, b , -sign_b);
	ll rx1 = x;
	// print(x);

	shift_solution(x, y, a, b, -(y1 - y) / a);
	if (y < y1)
		shift_solution(x, y, a, b, -sign_a);
	if (y > y2) {
		print_case(i, 0);
		return;
	}
	ll lx2 = x;
	// print(x);

	shift_solution(x, y, a, b, -(y2 - y) / a);
	if (y > y2)
		shift_solution(x, y, a, b, sign_a);
	ll rx2 = x;
	// print(x);

	if (lx2 > rx2)
		swap(lx2, rx2);

	ll lx = max(lx1, lx2);
	ll rx = min(rx1, rx2);

	if (lx > rx) {
		print_case(i, 0);
		return;
	}

	print_case(i, (rx - lx) / abs(b) + 1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	fo(i , t) {
		solve(i + 1);
	}
}
