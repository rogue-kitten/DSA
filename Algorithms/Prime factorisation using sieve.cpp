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

vector<int> prime_sieve(int *p, int n){
	p[0] = p[1] = 0;
	p[2] = 1;
	vector<int> primes;
	primes.push_back(2);
	//mark all the odd numbers as prime initially
	for(int i = 3; i <= n; i+=2){
		p[i] = 1;
	}

	//optimisation -> run only through the odd numbers
	for(int i = 3; i <= n; i+=2){
		if(p[i]){
			primes.push_back(i);
			for(int j = i*i; j <= n; j+= i){
				p[j] = 0;
			}
		}
	}
	return primes;

}

vector<int> factorize(int n, vector<int> &primes){
	vector<int> ans;

	for(auto x : primes){
		if(x*x > n)
			break;
		if(n%x == 0){
			ans.push_back(x);
			while(n%x == 0){
				n /=x;
			}
		}
	}
	if(n != 1)
		ans.push_back(n);
	return ans;
}

int main(){
	int N = 1000000;
	int p[N] = {0};
	vector<int> primes = prime_sieve(p, 100);

	// printall(primes);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		vector<int> factors = factorize(n, primes);

		for(auto f : factors)
			cout << f << " ";
		cout << endl;
	}
}
