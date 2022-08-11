// link to problem -> https://codeforces.com/problemset/problem/1541/A

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n & 1){
			int i = 2;
			while(n - i != 1){
				cout << i << " " << i - 1 << " ";
				i += 2;
			}
			cout << n << " " << i - 1 << " " << i;
		}
		else{
			for(int i = 2; i <= n; i+=2){
				cout << i << " " << i - 1 << " ";
			}
		}
		cout << endl;
	}
}
