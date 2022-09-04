//  link to the problem -> https://www.spoj.com/problems/CUBEFR/

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
bool sieve[N] = {0};
bool cube[N] = {0};
vi arr;
void prime_sieve() {
	arr.pb(1);
	for (int i = 2; i < N; i++) {
		if (sieve[i] == false) {
			ll temp = i * i * i;
			for (ll j = i; j < N; j += i) {
				sieve[j] = true;
				if (j % temp == 0)
					cube[j] = true;
			}
		}
		if (cube[i] == false) {
			arr.pb(i);
		}
	}
}

int found(int n) {
	int s = 0, e = arr.size() - 1, m;
	while (s <= e) {
		m = s + (e - s) / 2;
		if (arr[m] == n)
			return m;
		if (arr[m] > n)
			e = m - 1;
		else
			s = m + 1;
	}
	return -1;
}

void solve() {
	int n;
	cin >> n;
	int pos = found(n);
	if (pos != -1)
		print(pos + 1);
	else
		print("Not Cube Free");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	prime_sieve();
	ll t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
}
