// cannot run this code here because this is not a gcc compiler, do this on replit
// code for having non repeating values.
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
            tree_order_statistics_node_update> 
            pbds;

int main(){
  pbds a;
  // insertion takes log(n) time. 
  a.insert(1);
  a.insert(3);
  a.insert(4);
  a.insert(15);
  a.insert(10);

  cout << "kth largest elements for all values of k" << endl;
  // each function call takes log(n) time. 
  for(int i = 0; i < a.size(); i++){
    cout << i + 1 << "-> " << *a.find_by_order(i) << endl;
  }

  cout << "The number of elements strictly smaller than 11 are " << a.order_of_key(11) << endl;
}