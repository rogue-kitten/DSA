// link to the problem -> https://codeforces.com/problemset/problem/1728/B

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 109546051211
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vb vector<bool>
#define vd vector<double>

#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvs vector<vector<string>>

#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>

#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << '\n'

#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define mp make_pair

#define pb push_back
#define maxHeap  priority_queue<ll>
#define minHeap  priority_queue<int, vector<int>, greater<int> >

#define fo(i, n) for(int i = 0; i < n; i++)
#define rfo(i, n) for(int i = n; i >= 0; i--)
#define foll(i, n) for(ll i = 0; i < n; i++)
#define rfoll(i, n) for(ll i = n; i >= 0; i--)
#define foa(i, a, b) for(int i = a; i < b; i++)

#define print_case(i, x) cout << "Case " << i << ": " << x << '\n';

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }


void solve() {
   int n;
   cin >> n;
   if (n == 5) {
      for (int i = 1; i <= n; i++)
         cout << i << " ";
      cout << endl;
      return;
   }
   vi a(n + 1, 0);
   vb visited(n + 1, false);
   if (n & 1) {
      a[n - 1] = n;
      visited[n] = true;
      a[n - 2] = n / 2 + 1;
      visited[n / 2 + 1] = true;
      a[n - 3] = n / 2 - 1;
      visited[n / 2 - 1] = true;
      int j = 0;
      for (int i = n; i > 0; i--) {
         if (!visited[i])
            a[j++] = i;
      }
   }
   else {
      a[n - 1] = n;
      visited[n] = true;
      a[n - 2] = n - 1;
      visited[n - 1] = true;
      int j = 0;
      for (int i = n; i > 0; i--) {
         if (!visited[i])
            a[j++] = i;
      }
   }
   for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
   }
   cout << endl;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1;
   cin >> t;
   while (t--) {
      solve();
   }
}
