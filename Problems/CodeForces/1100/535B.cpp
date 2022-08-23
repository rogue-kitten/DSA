// link to problem -> https://codeforces.com/problemset/problem/535/B

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
	int n;
	cin >> n;
	if(n == 4){
		print(1);
		return 0;
	}
	if(n == 7){
		print(2);
		return 0;
	}

	ll temp = 0;
	int digits = 0;
	while(n > 0){
		if(n%10 == 7){
			temp += (1 << digits);
		}
		digits++;
		n /= 10;
	}
	ll x = ~((-1) << (digits));
	ll ans = x + temp;
	print(ans);
	return 0;
}
