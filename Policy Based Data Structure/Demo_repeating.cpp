// cannot run this code here because this is not a gcc compiler, do this on replit
// code for having repeating values -> use a pair<int, int> of defining instead of just an int
// the first value would be the ip, second would be the unique integer. 

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, 
    rb_tree_tag, tree_order_statistics_node_update> 
    pbds;

int main(){
  pbds a;
  // {value, index} pair
  a.insert({1, 0});
  a.insert({3, 1});
  a.insert({4, 2});
  a.insert({15, 3});
  a.insert({10, 4});
  a.insert({1, 5});

  cout << "kth largest elements for all values of k" << endl;
  for(int i = 0; i < a.size(); i++){
    cout << i + 1 << "-> " << (*a.find_by_order(i)).first << " " << (*a.find_by_order(i)).second << endl;
  }

  // cout << "The number of elements strictly smaller than 11 are" << a.order_of_key(11) << endl;
}