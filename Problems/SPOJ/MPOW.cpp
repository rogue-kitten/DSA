// link to problem -> https://www.spoj.com/problems/MPOW/

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007
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


vector<vll> matMult(vector<vll> a, vector<vll> b){
	int m = a.size();
	vector<vll> ans(m, vll(m));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			ans[i][j] = 0;
			for(int k = 0; k < m; k++){
				ans[i][j] = (ans[i][j] + ((a[i][k]*b[k][j])%mod)) % mod;
			}
		}
	}
	return ans;
}

vector<vll> matPow(vector<vll> a, int n){
	// base case
	if(n == 1)
		return a;
	if(n&1)
		return(matMult(a, matPow(a,n-1)));
	vector<vll> x = matPow(a, n/2);
	return matMult(x, x);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int m, n;
		cin >> m >> n;
		vector<vll> a(m, vll(m, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		if(n == 0){
			for(int i = 0; i < m; i++){
				for(int j = 0; j < m; j++){
					cout << 1 << " ";
				}
				cout <<endl;
			}
			continue;
		}
		a = matPow(a, n);

		for(int i = 0; i < m; i++){
			printall(a[i]);
			cout << "\n";
		}
		
	}
}
