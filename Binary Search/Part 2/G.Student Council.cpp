// link to the problem -> https://codeforces.com/edu/course/2/lesson/6/2/practice/status

#include<bits/stdc++.h>

using namespace std;
#define lli long long
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

// ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int k, n;
vector<lli>a;

bool good(long long int councils) {
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > councils) sum += councils;
		else sum += a[i];
	}
	return (sum / councils) >= k;
}

int main () {

	cin >> k >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long int l = 0, r = 25 * 1e9 + 10;
	while (l + 1 < r) {
		long long int mid = (l + r) / 2;
		if (good(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << "\n";
	return 0;
}
