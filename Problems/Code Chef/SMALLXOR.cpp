// link to problem -> https://www.codechef.com/submit/SMALLXOR

#include<bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl
#define maxHeap  priority_queue<int>
#define minHeap    priority_queue<int, vector<int>, greater<int> >

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x, y;
		cin >> n >> x >>y;
		minHeap m;
		for(int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			m.push(temp);
		}

		int temp, top;
		while(y){
			top = m.top();
			temp = x ^ top;
			m.pop();
			if(temp < top)
				break;
			m.push(temp);
			--y;
		}

		if(y){
			if(y&1)
				m.push(temp);
			else
				m.push(top);
		}
		while(!m.empty()){
			cout << m.top() << " ";
			m.pop();
		}
		cout << endl;

	}
}
