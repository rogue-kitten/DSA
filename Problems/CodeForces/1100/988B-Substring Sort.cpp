// link to problem - https://codeforces.com/problemset/problem/988/B

// Approach -> based on observation of the test cases, we see that the strings get sorted based upon the length of the string first. If length is equal
// they are sorted based on lexicographical order. Hence a custom comp function is made to handle this. After that we just need to check for ever
// string that the one coming before it in the sorted order is a substring of it or not, using the find function. If at any point it is not, cout NO.

#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
	if(a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main(){
	int n;
	cin >> n;
	cin.get();
	vector<string> s(100);
	for(int i = 0; i < n; i++){
		getline(cin, s[i]);
	}

	sort(s.begin(), s.begin() + n, cmp);

	for(int i = 1; i < n; i++){
		if(s[i].find(s[i - 1]) == -1){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
		cout << s[i] << endl;
	}
}
