// link to the problem -> https://www.spoj.com/problems/GCD2/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
   ll a;
   string b;
   cin >> a >> b;
   if (a == 0) {
      cout << b << endl;
      return;
   }
   if (b.size() == 1 && b[0] == '0') {
      cout << a << endl;
      return;
   }

   if (a == 1 || (b.size() == 1 && b[0] == '1')) {
      cout << 1 << endl;
      return;
   }

   ll pow = 1, temp = 0;
   for (int i = b.size() - 1; i >= 0; i--) {
      temp = (temp + (pow * ((b[i] - '0') % a)) % a) % a;
      pow = (pow * (10 % a)) % a;
   }
   cout << gcd(a, temp) << endl;
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
}
