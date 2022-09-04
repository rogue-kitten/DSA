// link to the problem -> https://www.spoj.com/problems/NFACTOR/

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
ll sum[N] = {0};
unordered_map<int, vi> m;

void prime_sieve() {
	for (int i = 2; i < N; i++) {
		if (sieve[i] == false)
			for (ll j = i; j < N; j += i) {
				sieve[j] = true;
				sum[j]++;
			}
		m[sum[i]].pb(i);
	}
}

int lowerBound(int a, vi & arr) {
	int start = 0, end = arr.size() - 1, mid;
	int ans = -1;
	while (start <= end) {
		mid = start + (end  - start) / 2;
		if (arr[mid] == a)
			return mid;
		if (arr[mid] < a) {
			ans = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	return ans;
}

int upperBound(int a, vi & arr) {
	int start = 0, end = arr.size() - 1, mid;
	int ans = -1;
	while (start <= end) {
		mid = start + (end  - start) / 2;
		if (arr[mid] == a)
			return mid;
		if (arr[mid] > a) {
			ans = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return ans;
}

void solve() {
	ll a, b, n;
	cin >> a >> b >> n;
	int count = 0;
	if (n == 0) {
		if (a == 1)
			print(1);
		else
			print(0);
		return;
	}
	if (m[n].size() == 0) {
		print(0);
		return;
	}
	int start = upperBound(a, m[n]), end = lowerBound(b, m[n]);
	if (start == -1 || start > end) {
		print(0);
		return;
	}

	if (end == -1)
		print(m[n].size() - start);
	else
		print(end - start + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	prime_sieve();
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
}
