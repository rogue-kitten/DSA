// link to problem -> https://codeforces.com/contest/1602/problem/C

// Approach: Let's note, that in one destruction for any bit 𝑖 (0 ≤ 𝑖 < 30) we either change all 𝑘-th non-zero bits into zero bits, or nothing changes. 
// So, the number of 𝑖-th non-zero bits in the array either decreases by 𝑘 or doesn't change. 
// In the end, all these numbers will be equal to 0. So, to be able to destruct the array, the number of 𝑖-th non-zero bits in the
// array should be divisible by 𝑘 for all bits 𝑖.

#include<bits/stdc++.h>

using namespace std;


int main(){

	int t;
	cin >> t;
	while(t--){
		vector<int> setBit(31, 0);
		int n,a;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a;
			for(int j = 0; j < 31; j++){
				if(a & (1 << j))
					++setBit[j];
			}
		}

		for(int i = 1; i <= n; i++){
			bool flag = true;
			for(int j = 0; j < 31; j++){
				if(setBit[j] % i)
					flag = false;
			}
			if(flag)
				cout << i << " ";
		}
		cout << endl;
	}

}
