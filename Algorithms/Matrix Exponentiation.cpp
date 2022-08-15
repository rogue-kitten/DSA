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

void matrixExp(int k, ll n, vll b, vll c){
	if(n == 0)
		print(0);
	else if(n <= k)
		print(b[n - 1]);
	else{
		// create a transformation matrix
		vector<vll> T (k, vll(k));
		for(int i = 0; i < k - 1; i++){
			for(int j = 0; j < k; j++){
				if(j == i + 1)
					T[i][j] = 1;
				else
					T[i][j] = 0;
			}
		}
		for(int i = 0; i < k; i++){
			T[k-1][i] = c[k - 1 - i];
		}
		// get the value of T^n-1
		T = power(T, n - 1);
		// the answer would be the first element of F(n), so we compute only the first element and not the entire array
		ll res = 0;
		for(int i = 0; i < k; i++){
			res = (res + (T[0][i]*b[i]) % mod) % mod;
		}
		print(res); 
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		vll b(k), c(k);

		for(int i = 0; i < k; i++){
			cin >> b[i];
		}
		for(int i = 0; i < k; i++){
			cin >> c[i];
		}
		ll n;
		cin >> n;

		matrixExp(k, n, b, c);
	}
	return 0;
}

