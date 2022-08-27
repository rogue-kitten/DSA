// link to the problem -> 

// Approach: generate all the common divisors of a, b in an array, sort the array and then find 
// if there are any common divisors lying in the range. 

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


vll get_divisors(ll n){
	vll ans;

	for(ll i = 1; i*i <= n; i++){
		if(n%i == 0){
			ans.push_back(i);
			if(i*i != n){
				ans.push_back(n/i);
			}
		}
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a,b;
	cin >> a >> b;
	int q;
	cin >> q;
	ll x = min(a,b), y = max(a,b);
	ll g = gcd(a,b);
	vll divisors = get_divisors(x);

	vll temp;
	for(auto d : divisors){
		if(y%d == 0)
			temp.pb(d);
	}

	sort(temp.begin(), temp.end());


	while(q--){
		ll l, r;
		cin >> l >> r;

		if(l > g){
			print(-1);
			continue;
		}

		if(l <= g && r > g){
			print(g);
			continue;
		}

		ll s = 0, e = temp.size() - 1, m;
		ll ans = -1;
		while(s <= e){
			m = s + (e - s)/2;

			if(temp[m] >= l && temp[m] <= r){
				ans = max(ans, temp[m]);
				s = m + 1;
			}
			else if(temp[m] < l)
				s = m + 1;
			else
				e = m - 1;
		}
		print(ans);

	}
}
