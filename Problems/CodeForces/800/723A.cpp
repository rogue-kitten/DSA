// link to problem -> https://codeforces.com/problemset/problem/723/A

#include<bits/stdc++.h>

using namespace std;

int main() {
	int a[3];
	for(int i = 0; i < 3; i++) cin >> a[i];
	sort(a ,a + 3);
	int ans = a[2] - a[0];
	cout << ans << endl;
}
