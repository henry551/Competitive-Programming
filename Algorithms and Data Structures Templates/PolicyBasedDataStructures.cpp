#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//key, mapped policy, basis of comparison, type of tree, contains various operations
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set arr;

void driver(){
    int k = 100, i = 1;

    //Insert node  O(logN)
    arr.insert(k);
    //Delete node  O(logN)
    arr.erase(k);
    //Find ith value in tree  O(logN)
    *(arr.find_by_order(i));
    //Find number of elements strictly less than k  O(logN)
    arr.order_of_key(k);
}