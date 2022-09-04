// link to the problem -> https://codeforces.com/contest/1722/problem/B

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
	string s1, s2;
	cin >> s1;
	cin >> s2;

	for (int i = 0; i < n; i++) {
		if (s1[i] == 'R' && (s2[i] == 'G' || s2[i] == 'B')) {
			print("NO");
			return;
		}
		if (s2[i] == 'R' && (s1[i] == 'G' || s1[i] == 'B')) {
			print("NO");
			return;
		}
	}
	print("YES");
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
