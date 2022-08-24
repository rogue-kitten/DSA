// link to the problem -> https://codeforces.com/problemset/problem/26/A

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


void prime_sieve(int *p){
	// skip all even numbers and mark all odd as prime. 
	for(int i = 3; i <= 3000; i+=2){
		p[i] = 1;
	} 

	//main sieve code
	for(ll i = 3; i <= 3000; i++){
		if(p[i]){
			// marks all the multiples of i as not prime. 
			for(ll j = i*i; j <= 3000; j += i){
				p[j] = 0;
			}
		}
	}

	// base cases
	p[2] = 1;
	p[1] = p[0] = 0;
}

int main(){
	int n;
	cin >> n;

	int sieve[3000] = {0};
	prime_sieve(sieve);
	int almostPrimes[3000] = {0};

	for(int i = 2; i<= n/2; i++){
		if(sieve[i]){
			for(int j = 2*i; j <= n; j += i){
				almostPrimes[j]++;
			}
		}
	}
	int count = 0;
	for(int i = 2; i <= n; i++){
		if(almostPrimes[i] == 2)
			count++;
	}
	print(count);
}
