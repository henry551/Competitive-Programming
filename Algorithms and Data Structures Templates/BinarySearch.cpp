#include <iostream>
#include <vector>
using namespace std;
typedef pair <int,int> pii;

int n; //number of elements in list
pii list[105]; //elements are from 1 to 100
vector <int> arr;

//Time Complexity: O(logn)
int binarySearch(int key){
    int l=0, r=arr.size(); //r must be initialized to larger than the maximum index
    int m;
    while(r-l>1){
        m = l+(r-l)/2; //prevents overflow
        arr[m] <= key ? l=m : r=m;
    }
    if(arr[l] == key) return l;
    //if the key doesn't exist, l will point to the index
    //of the first element smaller than key unless key < arr[0]
    return -1;
}

//Finds first element b such that condition is true
bool cmp1(int a, pii b){
    return a < b.second;
}

bool cmp2(int a, pii b){
    return a <= b.second;
}

//Time Complexity: O(logn)
void arrSearch(int k){ //k represents element with index k
    //returns index of first element with second value <= list[k].first
    int a = upper_bound(list+1, list+n+1, list[k].first, cmp1)-list-1;
    //returns index of first element with second value < list[k].first
    int b = upper_bound(list+1, list+n+1, list[k].first, cmp2)-list-1;
}
