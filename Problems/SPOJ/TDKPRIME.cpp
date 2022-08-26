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

const ll N = 90000001;

bool sieve[N] = {false};
vector<ll> primes;

void prime_sieve(){
	sieve[0] = sieve[1] = true;
	primes.pb(2);
	for(ll i = 3; i < 90000001; i+=2){
		if(sieve[i] == false){
			primes.pb(i);
			for(ll j = i*i; j <= 90000001; j+= i)
				sieve[j] = true;
		}
	}
}

int main(){
	int t;
	cin >> t;
	prime_sieve();
	while(t--){
		ll n;
		cin >> n;
		print(primes[n - 1]);
	}
}
