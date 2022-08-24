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
void prime_sieve(int *p){
	// skip all even numbers and mark all odd as prime. 
	for(int i = 3; i <= 1000000; i+=2){
		p[i] = 1;
	} 

	//main sieve code
	for(ll i = 3; i <= 1000000; i++){
		if(p[i]){
			// marks all the multiples of i as not prime. 
			for(ll j = i*i; j <= 1000000; j += i){
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

	int sieve[1000005] = {0};
	prime_sieve(sieve);

	for(int i = 0; i<= n; i++){
		if(sieve[i])
			cout << i << " ";
	}

}
