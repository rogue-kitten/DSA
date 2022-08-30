https://codeforces.com/problemset/problem/1721/D

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
 
 
bool works(int n, vi &a, vi &b){
	unordered_map<int, int> m;
	for(int i = 0; i < a.size(); i++){
		m[n^(a[i]&n)]++;
		m[b[i]&n]--;
	}
	
	for(auto x : m){
		if(x.second != 0)
			return 0;
	}
	return 1;
}
 
void solve(){
	int n;
	cin >> n;
	vi a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
 
	int ans = 0;
 
	for(int i = 30; i >= 0; i--){
		int temp = ((1ll << i) | ans);
 
		if(works(temp, a, b))
			ans = temp;
	}
	print(ans);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
