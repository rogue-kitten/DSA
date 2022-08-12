// link to problem -> https://codeforces.com/problemset/problem/282/A

#include <bits/stdc++.h>

using namespace std;

int main(){
	int ans = 0;
	int n;
	cin >> n;
	cin.get();
	for(int i = 0; i < n; i++){
		string s;
		getline(cin, s);
		int it = 0;
		if(s[it] == 'X') it++;
		if(s[it] == '+') ans++;
		if(s[it] == '-') ans--;
	}
	cout << ans << endl;
}
