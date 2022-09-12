// link to the problem -> https://www.codechef.com/submit/SUBARRY

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
#define minHeap  priority_queue<ll, vector<ll>, greater<ll> >

#define fo(i, n) for(int i = 0; i < n; i++)
#define rfo(i, n) for(int i = n; i >= 0; i--)
#define foll(i, n) for(ll i = 0; i < n; i++)
#define rfoll(i, n) for(ll i = n; i >= 0; i--)
#define foa(i, a, b) for(int i = a; i < b; i++)

#define print_case(i, x) cout << "Case " << i << ": " << x << '\n';

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }


void solve() {
	ll n;
	cin >> n;
	maxHeap maxi;
	minHeap mini;
	ll x;
	for (int i = 0; i < n; i++) {
		cin  >> x;
		maxi.push(x);
		mini.push(x);
	}
	if (maxi.top() >= 0 && mini.top() >= 0) {
		cout << mini.top() * mini.top() << " " << maxi.top() * maxi.top() << endl;
		return;
	}
	if (maxi.top() < 0 && mini.top() < 0) {
		cout << maxi.top() * maxi.top() << " " << mini.top() * mini.top() << endl;
		return;
	}
	else {
		cout << maxi.top() * mini.top() << " " << max(mini.top() * mini.top(), maxi.top() * maxi.top()) << endl;
		return;
	}
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
