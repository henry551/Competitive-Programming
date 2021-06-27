#include <bits/stdc++.h>
using namespace std;

int arr[10005]; //values are stored from 0 to n-1
int block[105]; // decomposed array
int sz;         // block size

// Time Complexity: O(1)
void update(int idx, int val){
    int blockNumber = idx / sz;
    block[blockNumber] += val;
    arr[idx] += val;
}

// Time Complexity: O(sqrt(n))
int query(int l, int r){
    int sum = 0;
    while (l<r && l%sz!=0 && l!=0) {
        sum += arr[l];
        l++;
    }
    while (l+sz <= r) {
        sum += block[l/sz];
        l += sz;
    }
    while (l<=r) {
        sum += arr[l];
        l++;
    }
    return sum;
}

//Time complexity: O(n)
void initialize(int n){
    int group = -1;
    sz = (int) sqrt(n);

    for (int i=0; i<n; i++) {
        if (i%sz == 0) group++;
        block[group] += arr[i];
    }
}