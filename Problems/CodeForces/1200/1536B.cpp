// link to the problem -> https://codeforces.com/problemset/problem/1536/B

#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define mod 9
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

#define endl '\n'
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl

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

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
	int n;
	cin >> n;
	char a[n];
	vi freq(26);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		freq[a[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (freq[i] == 0) {
			print((char)('a' + i));
			return;
		}
	}
	// length 2
	unordered_map<string, int> map;
	for (int i = 0; i < n - 1; ++i)
	{
		string temp;
		temp += a[i];
		temp += a[i + 1];
		map[temp]++;
	}
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			string temp;
			temp += (char)(i + 'a');
			temp += (char)(j + 'a');
			if (!map[temp]) {
				print(temp);
				return;
			}
		}
	}

	//length 3
	for (int i = 0; i < n - 2; ++i)
	{
		string temp;
		temp += a[i];
		temp += a[i + 1];
		temp += a[i + 2];
		map[temp]++;
	}
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			for (int k = 0; k < 26; ++k)
			{
				string temp;
				temp += (char)(i + 'a');
				temp += (char)(j + 'a');
				temp += (char)(k + 'a');
				if (!map[temp]) {
					print(temp);
					return;
				}
			}
		}
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
