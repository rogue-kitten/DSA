// Problem Statement: https://codeforces.com/problemset/problem/1324/D

// Approach: we basically need to find no of pairs (i,j) such that
// i < j && a[i] + a[j] > b[i] + b[j]
// A simple observation: on reordering the equation, we get
// a[i] - b[i] > b[j] - a[j] ==> c[i] > -c[j] for i < j;
// this becomes similar to the inversion count approach which was discussed earlier. 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
  int n;
  cout << "Enter size" << endl;
  cin >> n;
  pbds st;

  int a[n], b[n], c[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    c[i] = a[i] - b[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += i - st.order_of_key({-c[i], i});
    st.insert({c[i], i});
  }
  cout << sum << endl;
}