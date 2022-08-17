// link to problem -> https://www.codechef.com/submit/HLEQN

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
		if(n < 5){
			print("NO");
			continue;
		}
		bool flag = false;
		for(int i = 1; i <= sqrt(n); i++){
			int a = n - 2*i;
			int b = i + 2;
			if(a % b == 0){
				flag =true;
				break;
			}
		}
		if(flag)
			print("YES");
		else
			print("NO");
		
	}
}
