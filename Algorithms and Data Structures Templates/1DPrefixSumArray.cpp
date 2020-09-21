#include <iostream>

using namespace std;
int arr[11]; //values stored from index 1 to 10
int psa[11];

//O(1) time complexity
int query(int l, int r) {
    return psa[r] - psa[l - 1];
}

//O(n) time complexity
void prefixSumArray() {
    for (int i = 1; i <= 10; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= 10; i++) {
        psa[i] = psa[i - 1] + arr[i];
    }
}