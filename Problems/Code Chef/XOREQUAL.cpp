// link to problem -> https://www.codechef.com/problems/XOREQUAL

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl
#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

ll fastExp(ll a, ll n){
	if(a == 0)
		return 0;
	if(n == 0)
		return 1;
	if(n == 1)
		return a;

	ll x = (fastExp(a, n/2) % mod);
	if(n&1)
		return (a*((x*x)%mod))%mod;

	else
		return (x*x)%mod;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		ll ans = fastExp(2, n - 1);
		print(ans);
	}
}
