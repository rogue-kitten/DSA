Link to the problem -> https://www.codechef.com/problems/DIVSUBS

## Approach
```
1. Although we need to find the number of subsets, this problem can be solved by 
   figuring out subarrays instead of a subset(Proof comes from PHP)
   a. Create the prefix sum array of all the elements, and then mod it with N(size of the array).
   b. We now have an array of size N, who's elements lie in the range of [0:N-1]
   c. Now, we consider 2 cases: 
    i) If zero is present in this modified prefix array -> we straight away found the subarray we want.
    ii) If zero is not present, this means that we now have N places and N-1 values. Thus by the php, we know that
        atleast one of these values will repeat and that will be our answer ((a-b)%n == a%n - b%n)
```

## Code
```cpp
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<long long>
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
		int n;
		cin >> n;
		vi arr(n), prefix(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			if(i == 0)
				prefix[i] = arr[i] % n;
			else
				prefix[i] = (arr[i] + prefix[i - 1]) % n;
		}
		umii freq;
		bool flag = false;
		for(int i = 0; i < n; i++){
			if(prefix[i] == 0){
				print(i + 1);
				for(int k = 0; k <= i; k++){
					cout << k + 1 << " ";
				}
				flag = true;
				break;
			}
			if(freq.find(prefix[i]) != freq.end()){
				int j = freq[prefix[i]];
				print(i - j);
				for(int k = j + 1; k <= i; k++){
					cout << k + 1 << " ";
				}
				break;
			}
			freq[prefix[i]] = i;
		}
		cout << endl;

	}
}
```
