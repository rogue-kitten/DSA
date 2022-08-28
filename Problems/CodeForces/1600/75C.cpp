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

vll get_divisors(ll a){
	vll ans;
	for(int i = 1; i*i <= a; ++i){
		if(a%i == 0){
			ans.pb(i);
			if(i*i != a)
				ans.pb(a/i);
		}
	}
	return ans;
}

ll get_lowerBound(int n, vll &temp){
	ll s = 0, e = temp.size() - 1, m;
	ll ans = -1;
	while(s <= e){
		m = s +(e-s)/2;

		if(temp[m] <= n){
			ans = temp[m];
			s = m + 1;
		}
		else
			e = m - 1;

	}
	return ans;
}

ll get_upperBound(int n, vll &temp){
	ll s = 0, e = temp.size() - 1, m;
	ll ans = -1;
	while(s <= e){
		m = s +(e-s)/2;

		if(temp[m] >= n){
			ans = temp[m];
			e = m - 1;
		}
		else
			s = m + 1;

	}
	return ans;
}

void query(vll &temp, ll g){
	ll l, r;
	cin >> l >> r;

	if(l > g){
		print(-1);
		return;
	}

	if(l <= g && r > g){
		print(g);
		return;
	}

	ll x = get_upperBound(l, temp);
	ll y = get_lowerBound(r, temp);

	if(y >= l && y <= r){
		print(y);
		return;
	}
	print(-1);
}

void solve(){
	ll a, b, q;
	cin >> a >> b >> q;

	int g = gcd(a, b);

	vll divisors = get_divisors(a);

	vll temp;

	for(auto x : divisors){
		if(b%x == 0)
			temp.push_back(x);
	}

	sort(temp.begin(), temp.end());

	while(q--){
		query(temp, g);
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
