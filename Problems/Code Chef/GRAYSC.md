Link to problem ->

## Approach
```
1. from the gray code, we know that Ai and Ai+1 differ at only one bit: 
    means that their XOR will have only one set bit. 
2. Thus from the pigeonhole principle, we see that if n >= 130 (65 pairs)
    we can definitely atleast one of the adjacent XORs repeating. hence it will always be true
3. for n < 130, we just do a normal search operation. 
```


## Code
```cpp
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


int main(){
	ull n;
	cin >> n;
	vull arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	if(n >= 130){
		print("Yes");
		return 0;
	}
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = j + 1; k < n; k++){
				ull num = arr[i]^arr[j]^arr[k];
				if(binary_search(arr.begin() + k + 1, arr.end(), num)){
					print("Yes");
					return 0;
				}
			}
		}
	}
	print("No");
}
```
