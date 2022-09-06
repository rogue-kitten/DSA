// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D

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

const int N = 1000;
vll t(N, 0);
vll z(N, 0);
vll y(N, 0);
vll temp(N, 0);
vll res(N, 0);
ll n, m;

bool good(ll x) {
	fill(temp.begin(), temp.begin() + n, 0);
	ll balloons = m;
	for (int i = 0; i < n; i++) {
		ll count = 0, time = x, total = 0;
		while (time - t[i] >= 0) {
			time -= t[i];
			count++;
			balloons--;
			if (balloons == 0) {
				temp[i] = count;
				return true;
			}
			if (count % z[i] == 0) {
				if (time - y[i] < 0)
					break;
				else
					time -= y[i];
			}
		}
		temp[i] = count;
	}
	return false;
}

void solve() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> z[i] >> y[i];
	}
	
	ll s = 0, e = (t[0] + y[0]) * m, mid, ans = -1;
	while (s <= e) {
		mid = s + (e - s) / 2;
		if (good(mid)) {
			ans = mid;
			res = temp;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	print((ans == -1 ? 0 : ans));
	for (int i = 0 ; i < n; i++) {
		cout << res[i] << " ";
	}
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
