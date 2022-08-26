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


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		vi a(n), pre(n), post(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(i == 0)
				pre[i] = a[i];
			else
				pre[i] = gcd(pre[i-1], a[i]);
		}

		post[n - 1] = a[n - 1];
		for(int i = n -2; i >= 0; i--){
			post[i] = gcd(post[i + 1], a[i]);
		}

		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			l--; r--;
			if(l == 0){
				print(post[r + 1]);
				continue;
			}
			if(r == n - 1){
				print(pre[l-1]);
				continue;
			}
			print(gcd(pre[l-1], post[r+1]));
		}
		

	}
}
