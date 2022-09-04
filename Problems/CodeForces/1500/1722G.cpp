//  link to the problem -> https://codeforces.com/contest/1722/problem/G

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

const int N = 1003;

void solve() {
	int n;
	cin >> n;
	vi ans;
	if (n % 4 == 0) {
		int temp = 2;
		while (n > 0) {
			ans.pb(temp);
			ans.pb(temp + 2);
			ans.pb(temp + 1);
			ans.pb(temp + 3);
			temp += 4;
			n -= 4;
		}
	}
	else if (n % 4 == 1) {
		ans.pb(0);
		n--;
		int temp = 2;
		while (n > 0) {
			ans.pb(temp);
			ans.pb(temp + 2);
			ans.pb(temp + 1);
			ans.pb(temp + 3);
			temp += 4;
			n -= 4;
		}
	}
	else if (n % 4 == 2) {
		// 4 1 2 12 3 8
		ans.pb(4);
		ans.pb(1);
		ans.pb(2);
		ans.pb(12);
		ans.pb(3);
		ans.pb(8);
		n -= 6;
		int temp = 14;
		while (n > 0) {
			ans.pb(temp);
			ans.pb(temp + 2);
			ans.pb(temp + 1);
			ans.pb(temp + 3);
			temp += 4;
			n -= 4;
		}
	}
	else {
		ans.pb(1);
		ans.pb(2);
		ans.pb(3);
		int temp = 4;
		n -= 3;
		while (n > 0) {
			ans.pb(temp);
			ans.pb(temp + 2);
			ans.pb(temp + 1);
			ans.pb(temp + 3);
			temp += 4;
			n -= 4;
		}
	}
	printall(ans);
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
