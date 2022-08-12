// link to problem -> https://codeforces.com/problemset/problem/1594/B

#include<iostream>
#include<cmath>

using namespace std;

typedef long long int ll;
typedef unsigned long long int  ull;

ull mod = 1e9 + 7;

int main(){
	// fastio();
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		ull ans = 0;
		ull temp = 1;
		while(k > 0){
			if(k&1){
				ans = (ans%mod + temp%mod)%mod;
			}
			k = k >> 1;
			temp = (temp * n) % mod;
		}
		cout << ans%mod << endl;
	}
}
