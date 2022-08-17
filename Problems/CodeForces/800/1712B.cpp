// link to problem -> https://codeforces.com/contest/1712/problem/B


#include<bits/stdc++.h>
 
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl
 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi a(n + 1);
		int temp = n;
		while(n > 1){
			a[n] = n - 1;
			a[n - 1] = n;
			n -= 2;
		}
		if(n == 1)
			a[1] = 1;
 
		for(int i = 1; i <= temp; i++){
			cout << a[i] << " ";
		} 
		cout << endl;
	}
}
