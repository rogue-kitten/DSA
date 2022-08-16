#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define emod 1000000000
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

ll mod;

vector<vll> multiply(vector<vll> a, vector<vll> b){
	int k = a.size();
	vector<vll> ans(k, vll (k));
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			ans[i][j] = 0;
			for(int x = 0; x < k; x++){
				ans[i][j] = (ans[i][j] + (a[i][x]*b[x][j]) % mod) % mod;
			}
		}
	}
	return ans;
}

vector<vll> power(vector<vll> A, ll n){
	if(n == 1)
		return A;
	if(n&1)
		return multiply(A, power(A, n - 1));
	vector<vll> x = power(A, n/2);
	return multiply(x, x);
}

ll matExp(int k, ll n, vll b, vll c, vll s){
	if(n <= k)
		return s[n-1];

	vll f(k + 1);
	
	int j = k - 1;
	for(int i = 1; i <= k; i++){
		f[i] = b[j];
		j--;
	}

	f[0] = s[k-1];
	// create a transformation matrix
	vector<vll> T (k + 1, vll(k + 1, 0));
	T[0][0] = 1;
	for(int i = 1; i <= k; i++){
		T[0][i] = T[1][i] = c[i-1];
	}

	for(int i = 2; i <= k; i++){
		T[i][i-1] = 1;
	}

	// get the value of T^n-k
	T = power(T, n - k);
	// the answer would be the first element of F(n), so we compute only the first element and not the entire array
	ll res = 0;
	for(int i = 0; i <= k; i++){
		res = (res + (T[0][i]*f[i]) % mod) % mod;
	}
	return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		vll b(k), c(k), s(k);

		for(int i = 0; i < k; i++){
			cin >> b[i];
		}
		for(int i = 0; i < k; i++){
			cin >> c[i];
		}
		s[0] = b[0];
		for(int i = 1; i < k; i++){
			s[i] = s[i-1] + b[i];
		}
		ll m, n;
		cin >> m >> n >> mod;

		ll x = matExp(k, n, b, c, s);
		// print(x);
		ll y = matExp(k, m - 1, b, c, s);
		// print(y);
		ll ans = (x-y)%mod;
		ans += mod;
		ans %= mod;
		print(ans);
		
	}
}
