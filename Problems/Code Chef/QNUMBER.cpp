// link to the problem -> https://www.codechef.com/submit/QNUMBER

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
#define print(a) cout << a << '\n'
#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >


void factorise(ll n, vector<pair<ll, ll>> &factors){
	for(ll i = 2; i*i <= n; i++){
		if(n%i == 0){
			int occ = 0;
			while(n%i == 0){
				occ++;
				n /= i;
			}
			factors.pb(make_pair(i, occ));
		}
	}
	if(n != 1){
		factors.pb(make_pair(n, 1));
	}
}

void divisors(vector<pair<ll, ll>> &factors, ll k){
	ll ans = 1;
	for(auto x : factors){
		ll pf = x.first;
		ll count = 0;
		while(k%pf == 0){
			count++;
			k /= pf;
		}
		ans *= (min(count, x.second) + 1);
	}

	print(ans);
}

void divisible(vector<pair<ll, ll>> &factors, ll k, ll n){
	if(k > n){
		print(0);
		return;
	}

	ll ans = 1;
	for(auto x : factors){
		ll pf = x.first;
		ll count = 0;
		while(k % pf == 0){
			count++;
			k /= pf;
		}
		if(count > x.second){
			print(0);
			return;
		}
		ans *= ((x.second - count) + 1);
	}
	if(k != 1){
		print(0);
		return;
	}
	print(ans);
}

void not_divisible(vector<pair<ll, ll>> &factors, ll k, ll n){
	ll total = 1;
	for(auto x : factors){
		total *= (x.second + 1);
	}

	if(k > n){
		print(total);
		return;
	}

	ll ans = 1;
	for(auto x : factors){
		ll pf = x.first;
		ll count = 0;
		while(k % pf == 0){
			count++;
			k /= pf;
		}
		if(count > x.second){
			ans = 0;
			break;
		}
		ans *= ((x.second - count) + 1);
	}

	if(k != 1){
		print(total);
		return;
	}
	print(total - ans);
}

void solve(vector<pair<ll, ll>> &factors, ll n){
	ll t, k;
	cin >> t >> k;
	if(t == 1)
		divisors(factors, k);
	else if(t == 2){
		divisible(factors, k, n);
	}
	else
		not_divisible(factors, k, n);

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	ll n, q;
	cin >> n >> q;
	vector<pair<ll, ll>> factors;
	factorise(n, factors);

	while(q--){
		solve(factors, n);
	}
}
