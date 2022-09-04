// link to the problem -> https://codeforces.com/contest/1722/problem/D

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vvi vector<vector<int>>
#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << '\n'
#define pb push_back
#define maxHeap  priority_queue<ll>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
	ll n;
	cin >> n;
	char ch;
	// vll temp(n);
	maxHeap mp;
	ll count = 0;
	for (ll i = 0; i < n; i++) {
		cin >> ch;
		ll temp;
		if (ch == 'L') {
			temp = i;
		}
		else
			temp = n - i - 1;
		count += temp;
		ll x = max(i, n - i - 1);
		if (temp != x)
			mp.push(x - temp);
	}

	for (int i = 0; i < n; i++) {
		if (!mp.empty()) {
			count += mp.top();
			mp.pop();
		}
		cout << count << " ";
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
