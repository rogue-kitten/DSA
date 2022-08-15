#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
#define mod (ll)1e9
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
 
ll p;
 
vector<vll> multiply(vector<vll> a, vector<vll> b){
	int k = a.size();
	vector<vll> ans(k, vll (k));
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			ans[i][j] = 0;
			for(int x = 0; x < k; x++){
				ans[i][j] = (ans[i][j] + (a[i][x]*b[x][j]) % p) % p;
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
 
ll matrixExp(int k, ll n, vll b, vll c){
	if(n <= k){
		ll sum = 0;
		for(int i = 0; i < n; i++){
			sum = (sum + (b[i] % p)) % p;
		}
		return sum;
	}
	else{
		// create a transformation matrix
		vector<vll> T (k + 1, vll(k + 1));
		for(int i = 0; i < k - 1; i++){
			for(int j = 0; j < k + 1; j++){
				if(j == i + 1)
					T[i][j] = 1;
				else
					T[i][j] = 0;
			}
		}
		for(int i = 0; i < k + 1; i++){
			if(i == k)
				T[k - 1][i] = 0;
			else
				T[k-1][i] = c[k - 1 - i];
		}
		for(int i = 0; i < k + 1; i++){
			if(i == 1 || i == k)
				T[k][i] = 1;
			else
				T[k][i] = 0;
		}
 
		// get the value of T^n-1
		T = power(T, n - 1);
		// the answer would be the last element of F(n), so we compute only the last element and not the entire array
		ll res = 0;
		for(int i = 0; i < k + 1; i++){
			res = (res + (T[k][i]*b[i]) % p) % p;
		}
		return res;	
	}
}
 
int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		vll b(k + 1), c(k);
 
		for(int i = 0; i < k; i++){
			cin >> b[i];
		}
		b[k] = b[0];
 
		for(int i = 0; i < k; i++){
			cin >> c[i];
		}
 
		ll m, n;
		cin >> m >> n >> p;
 
		ll x = matrixExp(k, n, b, c);
		if(m == 1){
			print(x);
			continue;
		}

		ll y = matrixExp(k, m - 1, b, c);
		print((x - y)%p);
 
	}
	return 0;
}
