// link to problem -> https://codeforces.com/contest/1712/problem/C

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
 
		vi a(n);
 
		unordered_map<int, vi> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]].push_back(i);
		}
 
		int i = n - 1;
		while(i > 0){
			if(a[i - 1] > a[i])
				break;
			i--;
			
		}
		
		if(i == 0){
			print(0);
			continue;
		}
 
		int count = 0;
		for(int j = 0; j < i; j++){
			if(a[j]){
				for(auto it : mp[a[j]]){
					a[it] = 0;
				}
				++count;
			}
		}
 
		i = n - 1;
		while(i >= 0 && a[i] != 0){
			i--;
		}
 
		for(int j = i; j >= 0; j--){
			if(a[j]){
				for(auto it : mp[a[j]]){
					a[it] = 0;
				}
				++count;
			}
		}
		print(count);
 
	}
}
