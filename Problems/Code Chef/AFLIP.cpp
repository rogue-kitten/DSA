// link to problem -> https://www.codechef.com/submit/AFLIP

#include<bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, x;
		cin >> n >> m;
		unordered_map<int, pair<int, int>> a;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> x;
				if(a.find(x) == a.end()){
					a[x] = {0,0};
				}
				if((i+j)&1)
					a[x].second++;
				else
					a[x].first++;
			}
		}
		bool flag = true;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> x;
				if(a.find(x) == a.end()){
					flag = false;
					continue;
				}
				if((i+j)&1){
					if(a[x].second == 0){
						flag = false;
						// continue;
					}
					else
						a[x].second--;
				}
				else{
					if(a[x].first == 0){
						flag = false;
						// continue;
					}
					else
						a[x].first--;
				}
			}
		}
		if(flag)
			print("YES");
		else
			print("NO");

	}
}
