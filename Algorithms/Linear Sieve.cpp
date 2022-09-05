// normal sieve generates primes with complexity O(nloglogn), linear sieve does the same job in O(n). 
// Why is this linear? because we visit every number only once in this.
// refer handnotes for more info about this. 
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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int N = 1000007; // 1e6 + 7
bool is_composite[N]; //marks 1 if it is composite, 0 if prime
vector<int> primes;

void linearSieve() {
	fill(is_composite, is_composite + N, false); //initialise the array as prime initially
	for (int i = 2; i < N; i++) {
		if (!is_composite[i]) { // if it is a prime number
			primes.pb(i);
			for (int j = 0; j < primes.size() && i * primes[j] < N; j++) {
				is_composite[i * primes[j]] = true;
				if (i % primes[j] == 0) //if p divides i, it should be the smallest prime that does that.
					break;
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;
	if (is_composite[n])
		print("Composite");
	else
		print("prime");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	linearSieve();
	cin >> t;
	while (t--) {
		solve();
	}
}
