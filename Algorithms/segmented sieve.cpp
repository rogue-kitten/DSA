#include<iostream>
#include<vector>

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

const int N = 100000;
int sieve[N] = {0};
vector<int> primes;

void prime_sieve(){
	sieve[0] = sieve[1] = 1;
	for(int i = 2; i < N; i++){
		if(sieve[i] == 0){
			primes.pb(i);
			for(ll j = i; j < N; j += i){
				sieve[j] = 1; //not prime
			}
		}
	}
}

int main(){
	prime_sieve();
	int t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> m >> n;
		vector<bool> segment(n - m + 1, true);
		
		for(auto x : primes){
			if(x*x > n)
				break;

			int start = (m/x)*x;
			if(x >= m && x <= n)
				start = 2*x;

			for(int i = start; i <= n; i+= x){
				segment[i-m] = false;
			}
		}

		for(int i = m; i <= n; i++){
			if(segment[i - m] && i != 1)
				print(i);
		}
		cout << endl;
	}
	
}
