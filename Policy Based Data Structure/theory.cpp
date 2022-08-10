// Defn, syntax, declaration and use cases
// Policy based Data Structures in G++
// The g++ compiler supports certain DS that are not a part of the Cpp compiler,
// such ds are called as PBDS. 

// header files to be included
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// namespaces to be included
using namespace __gnu_pbds;

// declaration for the tree based container. Read more in detail here -> https://gcc.gnu.org/onlinedocs/libstdc++/manual/policy_data_structures_design.html#container.tree.interface
template<
      // Key type -> integer or pair, string anything 
      // (basically what do you want the DS to store)
      typename Key,
      // Mapped-Policy -> null_type is set, null mapped is map type
      typename Mapped,
      // comparator -> how do you want the ds to compare the keys
      typename Cmp_Fn = std::less<Key>,
      // Specifies which underlying data structure to use.
      // rb_tree_tag -> functions like an red black tree
      typename Tag = rb_tree_tag,
      template<
      typename Const_Node_Iterator,
      typename Node_Iterator,
      typename Cmp_Fn_,
      typename Allocator_>

      // A policy for updating node invariants
      class Node_Update = null_node_update,
      // an allocator type
      typename Allocator = std::allocator<char> >

class tree;

// defining the pbds
typedef tree<int, null_type, less<int>, rb_tree_tag, 
            tree_order_statistics_node_update> 
            new_data_set;


// Final Declaration we will use
typedef tree <int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
            ordered_set;

//The pbds works like a set and has all the functionalities that any normal set has. 
// But on top of that, it has two more special functions:
// 1) find_by_order(k) => returns the iterator to the k'th largest element in the ds(0-indexed)
// 2) order_of_key(k) => returns the number of elements which are strictly less than the given key
// TC for both these functions -> log(n)

// to simplify, it creates a set like ds which stores all the values in an increasing order,
// and we can use these 2 functions to access the elements of the set.
// if we insert 1, 4, 15, 10, 3 into this ds, 
// they will get stored as          1, 3, 4, 10, 15
// and they will have indexes like  0, 1, 2, 3 , 4
// so if i call find_by_order(3) -> will point to 10 [pass the index to find the value]
// similarly: order_of_key(10) -> give me 3 [pass the value to find the index]

// exception case -> what if the given element is not in the set: order_of_key(11) -> 4
// basically says that if 11 was also present in the set, on which index would it be there. 
