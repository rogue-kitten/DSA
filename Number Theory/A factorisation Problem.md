## Question
```
Mike found an interesting problem. In this problem you are given two integers, n and k. 
You need to find the the maximum value of x, such that, n! % kx = 0.
```

## Approach
```
1. Find out all the prime factors of k and the power of it.
2. Find out how many times this prime factor comes in n! 
   This is done by the formula: occ = [n/k] + [n/k^2] + [n/k^3] ...
3. Do this for all the prime factors of k. The ans would be the min of count/occ,
   Count = count of the factor in n!, occ = power of the factor in k
```

## Code
```cpp
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


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int ans = INT_MAX;

		// int occ = 0;
		for(int i = 2; i * i <= k; i++){ //prime factorisation loop
			if(k%i == 0){
				int occ = 0;

				while(k%i == 0){
					occ++;
					k /= i;
				}

				int count = 0;
				ll temp = i;
				while(temp <= n){
					count += n/temp;
					temp = temp * i;
				}
				ans = min(ans, count / occ);
			}
		}
		// exception case, when we have one prime factor left (in k)
		if(k > 1){
			int count = 0;
			ll temp = k;
			while(temp <= n){
				count += n/temp;
				temp = temp * k;
			}
			ans = min(ans, count); // occurance for this prime factor would be 1
		}

		// if the factors of k are not present in n, then return 0.
		if(ans == INT_MAX){
			ans = 0;
		}

		print(ans);
	}
}
```
