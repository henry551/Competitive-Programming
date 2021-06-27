#include <bits/stdc++.h>
using namespace std;
int arr[300];
int bit[301];
int n; //number of elements in input array

//Initialize: O(n)
//Update: O(logn)
//Sum: O(logn)

void update(int idx, int val){
    idx++;
    while (idx <= n){
        bit[idx] += val;
        idx += idx&(-idx);
    }
}

int getSum(int idx){
    idx++;
    int sum = 0;
    while (idx > 0){
        sum += bit[idx];
        idx -= idx&(-idx);
    }
    return sum;
}

void intialize(){
    for (int i=0; i<n; i++){
        bit[i+1]+=arr[i];
        int j = i+1+((i+1)&-(i+1));
        if (j<=n) bit[j]+=bit[i+1];
    }
}