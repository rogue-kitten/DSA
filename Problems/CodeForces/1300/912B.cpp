// link to problem -> https://codeforces.com/problemset/problem/912/B

#include<iostream>
#include<cmath>

using namespace std;

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){
	uint64 n;
	int k;
	cin >> n >> k;

	if(k == 1){
		cout << n;
		return  0;
	}


	// we use a log2l function instead of a log2 because n is not an int, it can be long long as well. 
	int bits = (int)log2l(n) + 1;
	uint64 ans = ~((-(1ll)) << bits);

	cout << ans << endl;

	return 0;
}

// Appraoch -> on observing we can see that if the no of bits in n and x, they we can get a max xor sum of 2^x - 1 using atleast 2 numbers less than n. 
// If n == 1, return n itself.
