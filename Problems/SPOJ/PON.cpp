// link to problem : https://www.spoj.com/status/ns=29990743

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
#define print(a) cout << a << endl
#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll stringToInt(string a, ll m) {
	ll ans = 0;
	for (int i = 0; i < a.length(); i++) {
		ans = ((ans * 10) % m + (a[i] - '0')) % m;
	}
	return ans;
}

ll modularMultiplication(ll a, ll b, ll m) {
	ll res = 0;
	while (b > 0) {
		if (b & 1ll)
			res += a;
		a *= 2;
		b = b >> 1;
		res %= m;
		a %= m;
	}
	return res;
}

ll FastModularExp(ll a, ll b, ll m) {
	ll res = 1ll;

	while (b > 0) {
		if (b & 1ll) {
			res = modularMultiplication(res, a, m);
		}
		a = modularMultiplication(a, a, m);
		b = b >> 1;
	}
	return res;
}

bool miller_rabin(ll n) {
	// base case
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	// getting the values of d and s.
	ll d = n - 1, s = 0;
	while (d % 2 == 0) {
		s++;
		d /= 2;
	}
	// n - 1 = d * pow(2, s); d is odd.

	// selecting the values of A as 9 prime numbers
	vll a({2, 3, 5, 7, 11, 13, 17, 19, 23});

	for (int i = 0; i < 9; i++) {
		if (a[i] > n - 2) // range of a is [2, n-2]
			continue;
		ll ad = FastModularExp(a[i], d, n);

		if (ad % n == 1)
			continue;
		bool prime = false;
		for (int j = 0; j < s; j++) {
			ll rr = FastModularExp(2, j, n);
			ll ard = FastModularExp(ad, rr, n);
			if (ard % n == n - 1) {
				prime = true;
				break;
			}
		}
		if (!prime)
			return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (miller_rabin(n))
			print("YES");
		else
			print("NO");
	}

}
