// link to problem -> https://www.spoj.com/problems/DCEPCA03/

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

const int N = 10001;
int phi[N];
ll sum[N];

void sieve(){
	for(int i = 1; i < N; i++){
		phi[i] = i;
	}
	sum[1] = 1;
	for(int i = 2; i < N; i++){
		if(phi[i] == i){
			for(int j = i; j < N; j += i){
				phi[j] *= (i - 1);
				phi[j] /= i;
			}
		}
		sum[i] = sum[i - 1] + phi[i];
	}
}

void solve(){
	int n;
	cin >> n;
	print(sum[n]*sum[n]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	sieve();
	while(t--){
		solve();
	}
	

}
