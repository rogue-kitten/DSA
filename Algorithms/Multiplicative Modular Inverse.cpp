// calculative modular multiplicative inverse using extended eucledian algorithm. 

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 98765431
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

ll modularInverse(ll a, ll m){
	if(m == 1)
		return 0;
	ll m0 = m, y = 0, x = 1;

	while(a  > 1){
		ll q = a / m, t = m;
		m = a % m, a = t;
		t = y;
		y = x - q*y;
		x = t;
	}

	if(x < 0)
		x += m0;

	return x;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, m;
		cin >> a >> m;

		b = modularInverse(a, m);
		print(b);
	}
}
