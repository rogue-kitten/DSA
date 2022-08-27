// link to the problem -> https://www.spoj.com/problems/LASTDIG/

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define print(x) cout << x << endl;

ll FastModularExp(ll a, ll b, ll m){
	ll res = 1ll;

	while(b > 0){
		if(b&1ll){
			res = ((res%m) * (a%m))	% m;
		}
		a =  ((a%m) * (a%m))	% m;
		b = b >> 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;

		if(a == 0){
			print(0);
			continue;
		}
		if(b == 0){
			print(1);
			continue;
		}
		if(a == 1){
			print(1);
			continue;
		}
		if(b == 1){
			print(a%10);
			continue;
		}
		print(FastModularExp(a, b, 10));
	}
}
