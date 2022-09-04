//  link to the problem -> https://codeforces.com/contest/1722/problem/C

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
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
	int n;
	cin >> n;
	unordered_map<string, vector<int>> mp;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s].push_back(1);
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s].push_back(2);
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s].push_back(3);
	}

	vector<int> ans(4, 0);
	for (auto x : mp) {
		if (x.second.size() == 1) {
			ans[x.second[0]] += 3;
		}
		else if (x.second.size() == 2) {
			ans[x.second[0]] += 1;
			ans[x.second[1]] += 1;
		}
	}

	for (int i = 1; i < 4; i++)
		cout << ans[i] << " ";
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
