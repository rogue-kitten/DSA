// this is a rendation of the famous stars and bars type of a problem. You can find more resources for this on YT

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 98765431
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


ll binomialCoeff(ll n, ll k)
{
    ll res = 1ll;
 
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
 
    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll  n, k;
		cin >> n >> k;
		if(k > n){
			print(0);
			continue;
		}
		if(k == n){
			print(1);
			continue;
		}

		print(binomialCoeff(n-1, k-1));
	}
}
