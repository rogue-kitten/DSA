// link to problem -> https://www.codechef.com/submit/TWOTRAINS

#include<bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi time(n-1);
		vi a(n-1);
		vi b(n-1);
		for(int i = 0; i < n - 1; i++){
			cin >> time[i];
			if(i == 0)
				a[i] = time[i];
			else
				a[i] = a[i - 1] + time[i];
		}

		b[0] = 2*a[0];
		for(int i = 1; i < n - 1; i++){
			int diff = 0;
			if(a[i] >= b[i - 1])
				diff += a[i] - b[i - 1];
			b[i] = b[i - 1] + time[i] + diff;
		}
		print(b[n - 2]);
	}
}
