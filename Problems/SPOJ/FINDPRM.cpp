// link to the problem -> https://www.spoj.com/problems/FINDPRM/

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

const int TOT = 10000001;
int prime[TOT + 1];
bool isPrime1[TOT + 1];
void sieve() {
	for (int i = 0; i <= TOT; ++i) {
		isPrime1[i] = true;
	}
	for (int i = 3; i * i <= TOT; i += 2) {
		if (isPrime1[i]) {
			for (int j = i * i; j <= TOT; j += 2 * i) {
				isPrime1[j] = false;
			}
		}
	}
	prime[2] = 1;
	for (int i = 3; i <= TOT; ++i) {
		if (isPrime1[i] && i % 2 != 0) {
			prime[i] = prime[i - 1] + 1;
		} else {
			prime[i] = prime[i - 1];
		}
	}
}

void solve() {
	int n;
	cin >> n;
	print(prime[n] - prime[n / 2]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}
