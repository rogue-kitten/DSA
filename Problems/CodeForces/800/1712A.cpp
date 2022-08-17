// link to problem -> https://codeforces.com/contest/1712/problem/A

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
		int n, k;
		cin >> n >> k;
		int sum = 0, x;
		for(int i = 1; i <= n; i++){
			cin >> x;
			if(i <= k){
				if(x > k)
					sum++;
			}
		}
		print(sum);
 
	}
}
