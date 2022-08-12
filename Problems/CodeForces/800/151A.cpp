// link to problem -> https://codeforces.com/problemset/problem/151/A

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;

	int td = k*l, ts = c*d;

	int ans = min(td/(n*nl),min(p/(n*np), ts/n));
	cout << ans << endl;
}
