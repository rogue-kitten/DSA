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

ll x, y, GCD;

void extendedEuclid(ll a, ll b){
	//base case
	if(b == 0){
		x = 1;
		y = 0;
		GCD = a;
		return;
	}

	extendedEuclid(b, a%b);

	ll cx, cy;
	cx = y;
	cy = x - (a/b)*y;
	x = cx;
	y = cy;
}

int main(){
	ll a, b;
	cin >> a >> b;
	extendedEuclid(a,b);
	cout << x << " " << y << endl;
	print(GCD);
}
