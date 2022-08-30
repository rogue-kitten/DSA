https://codeforces.com/problemset/problem/1721/B

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
		int n, m, sx, sy, d;
		cin >> n >> m >> sx >> sy >> d;
 
		if(n + m - sx - sy <= d)
			print(-1);
 
		else if((sx - d <= 1 && sy - d <= 1) || (sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m) || (sx + d >= n && sy + d >= m))
			print(-1);
		else
			print(n + m - 2);
	}	
}
