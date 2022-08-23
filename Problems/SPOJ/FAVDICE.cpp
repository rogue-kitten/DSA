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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		double ans = 0.00;
		for(double i = 1.00; i <= n; i++){
			ans += (1.00/i);
		}
		ans *= n;
		printf("%.2f",ans);
		cout << endl;
	}
}
