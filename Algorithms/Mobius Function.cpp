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

ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b); }

const ll N = 100005;
vll arr(N, 1), prime_count(N, 0);

void mobius(){
	ll i, j;
	for(i = 2; i < N; i++){
		if(prime_count[i]) // not a prime no. 
			continue;
		for(j = i; j < N; j += i){
			prime_count[j]++;
			arr[j] *= i;
		}
	}

	for(int i = 1; i < N; i++){
		if(arr[i] == i){
			if(prime_count[i]&1)
				arr[i] = -1;
			else
				arr[i] = 1;
		}
		else
			arr[i] = 0;
	}
}

int main(){
	mobius();
	for(int i = 1; i < 30; i++){
		cout << arr[i] << " ";
	}

}
