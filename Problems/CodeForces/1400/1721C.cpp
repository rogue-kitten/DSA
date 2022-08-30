https://codeforces.com/problemset/problem/1721/C

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
		ll n;
		cin >> n;
		vll a(n), b(n), dmin(n), dmax(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int j = 0; j < n; j++){
			cin >> b[j];
		}
 
		// for(int i = 0, j = 0; i < n; i++){
		// 	while(a[i] > b[j])
		// 		j++;
		// 	dmin[i] = b[j] - a[i];
		// }
		// printall(dmin);
		// cout << endl;
 
		int maxi = n - 1, mini = n - 1;
		for(int i = n - 1; i >= 0; i--){
			while(mini > 0 && a[i] <= b[mini - 1])
				mini--;
			dmin[i] = b[mini] - a[i];
			dmax[i] = b[maxi] - a[i];
 
			if(i == mini){
				maxi = mini = i - 1;
			}
		}
		printall(dmin);
		cout << endl;
		printall(dmax);
		cout << endl;
 
	}
