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

// 1 marks for prime, zero marks for not prime. 
vector<ll> prime_sieve(int *p, ll n){
	p[0] = p[1] = 0;
	p[2] = 1;
	vector<ll> primes;
	primes.push_back(2);
	//mark all the odd numbers as prime initially
	for(ll i = 3; i < n; i+=2){
		p[i] = 1;
	}

	//optimisation -> run only through the odd numbers
	for(ll i = 3; i < n; i+=2){
		if(p[i]){
			primes.push_back(i);
			for(ll j = i*i; j < n; j+= i){
				p[j] = 0;
			}
		}
	}
	return primes;

}

int main(){
	int n;
	cin >> n;

	ll N = 100005;
	int p[N] = {0};
	vector<ll> primes = prime_sieve(p, 100000);

	for(int i = 0; i<= n; i++){
		if(primes[i] > n)
			break;
		cout << primes[i] << " ";
	}

}
