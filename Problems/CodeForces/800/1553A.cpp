// link to problem -> https://codeforces.com/problemset/problem/1553/A

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = n / 10;
		if(n % 10 == 9) ans++;
		cout << ans << endl;
	}
}
