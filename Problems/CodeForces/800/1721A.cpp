// https://codeforces.com/problemset/problem/1721/A

#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vvi vector<vector<int>>
#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl
#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >
 
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b); }
 
 
 
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		unordered_map<char, int> mp;
		char x;
		for(int i = 0; i < 4; i++){
			cin >> x;
			mp[x]++;
		}
 
		if(mp.size() == 1)
			print(0);
		else if(mp.size() == 2){
			print(1);
		}
		else if(mp.size() == 3){
			print(2);
		}
		else
			print(3);
	}
}
