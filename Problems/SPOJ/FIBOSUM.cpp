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

// ll matExp(ll n, int k, vll b, vll c, vll sum){
// 	if(n <= k)
// 		return sum[n-1];

// 	// create the tranformation matrix
// 	vector<vll> T(k + 1, vll(k + 1, 0));
// 	T[0][0] = 1;
// 	for(int i = 1; i <= k; i++){
// 		T[0][i] = T[1][i] = c[i-1];
// 	}

// 	for(int i = 2; i <= k; i++){
// 		T[i][i-1] = 1;
// 	}
// 	vll F(k + 1);
// 	F[0] = sum[k-1];
// 	for(int i = 1; i <= k; i++){
// 		F[i] = b[k - i];
// 	}
// 	// compute the power of T^(n-k)
// 	T = power(T, n-k);

// 	ull ans = 0;
// 	for(int i = 0; i <= k; i++){
// 		ans = (ans + (T[0][i]*F[i]) % mod) % mod;
// 	}
// 	return ans;
// }

ll fibSum(ll n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;

	vll F {1,0};
	vector<vll> T {{1,1},{1,0}};
	T = power(T,n);
	ll ans = 0;
	for(int i = 0; i < 2; i++){
		ans = (ans + (T[0][i]*F[i]) % mod) % mod;
	}
	return (ans - 1);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll m,n;
		cin >> m >> n;
		n += 1;
		if(m == 0){
			print(fibSum(n));
			continue;
		}
		ll x = fibSum(n);
		ll y = fibSum(m);
		ll ans = x - y;
		if(ans < 0)
			ans += mod;
		print(ans);
	}
}
