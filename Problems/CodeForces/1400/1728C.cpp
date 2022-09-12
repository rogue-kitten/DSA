// link to the problem -> https://codeforces.com/problemset/problem/1728/C

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 109546051211
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vb vector<bool>
#define vd vector<double>

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
#define mp make_pair

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

int getDigits(int n) {
	int count = 0;
	while (n > 0) {
		count++;
		n /= 10;
	}
	return count;
}

void solve() {
	int n, t;
	cin >> n;
	multiset<int> msa, msb;
	for (int i = 0; i < n; i++) {
		cin >> t;
		msa.insert(t);
	}
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (msa.count(t) == 0)
			msb.insert(t);
		else
			msa.erase(msa.find(t));
	}
	ll ans = 0;
	vi temp(10, 0);

	for (int x : msa) {
		if (x > 9) {
			x = getDigits(x);
			ans++;
		}
		temp[x]++;
	}

	for (int x : msb) {
		if (x > 9) {
			x = getDigits(x);
			ans++;
		}
		if (temp[x])
			temp[x]--;
		else {
			ans += 2;
			if (x == 1)
				ans -= 1;
		}
	}
	ans -= temp[1];
	print(ans);


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}
