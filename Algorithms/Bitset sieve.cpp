// can use this bitset sieve method to check if a number is prime or not till the 10^14.
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

const int n = 10000000; //1e7
bitset<10000005> b;
vector<int> primes; // to store the prime numbers. 

// 1 marks for prime, zero marks for not prime. 
void sieve(){
	b.set(); // sets all the bits to 1. 
	b[0] = b[1] = 0;

	for(ll i = 2; i <= n; i++){
		if(b[i]){
			primes.pb(i);
			for(ll j = i*i; j <= n; j += i){
				b[j] = 0;
			}
		}
	}
}

int main(){
	sieve();
	int m;
	cin >> m;
	// prints the first m prime numbers. 
	for(int i = 0; i <= m; i++){
		cout << primes[i] << " ";
	}
}
