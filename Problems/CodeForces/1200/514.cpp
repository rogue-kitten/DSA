// link to problem -> https://codeforces.com/contest/514/problem/A

#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	string ans;
	for(int i = 0; i < s.length(); i++){
		if(s[i]  == '9' && i == 0){
			ans.push_back(s[i]);
			continue;	
		} 
		if(s[i] >= '5'){
			ans.push_back('0' + '9' - s[i]);
		}
		else ans.push_back(s[i]);
	}
	cout << ans << endl;
}
