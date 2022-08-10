// Problem Statement: https://www.interviewbit.com/problems/inversions/

// Approach: we created a pbds and iterate over the array. for every element, 
// we find the number of elements greater than that one which are already present in the array 
// using the find_by_order function. The find by order function tell us how many elements are strictly less than
// our element. so we subtract this from the size of pbds until that point to get the no of elements greater 
// than A[i] in the pbds. Here the size of the pbds would be the same as the value of i (observation). 
// After that we add this element in the pbds. 
// We use pair of int instead of int to handle the case of repetitions. 

// TC -> O(nlogn), SC -> O(n)

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, 
    rb_tree_tag, tree_order_statistics_node_update> 
    pbds;

int Solution::countInversions(vector<int> &A) {
    pbds a;
    int sum = 0;
    for(int i = 0; i < A.size(); i++){
        sum += i - a.order_of_key({A[i], i});
        a.insert({A[i], i});
    }
    return sum;
    
}
