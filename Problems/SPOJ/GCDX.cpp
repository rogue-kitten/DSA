// link to problem -> https://www.spoj.com/problems/GCDEX/


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
#define print(a) cout << a << '\n'
#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

const int N = 1000002;
ll phi[N];
ll sum[N] = {0};

void sieve() {
	for (int i = 1; i < N; i++) {
		phi[i] = i;
	}
	for (int i = 2; i < N; i++) {
		if (phi[i] == i) {
			for (int j = i; j < N; j += i) {
				phi[j] *= (i - 1);
				phi[j] /= i;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i)
			sum[j] += (i * phi[j / i]);
		sum[i] -= i;
		sum[i] += sum[i - 1];

	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	ll t;
	cin >> t;
	while (t != 0) {
		print(sum[t]);
		cin >> t;
	}

}
