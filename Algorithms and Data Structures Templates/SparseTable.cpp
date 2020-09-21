#include <iostream>
#include <cmath>
using namespace std;
int n;
int arr[300]; //values are stored from index 0 to n-1
const int k = (int) log2(n) + 1;
int lookup[300][(int) log2(300) + 1];

//Range Minimum Query Sparse Table
//O(nlogn)
void build() {
    for (int i = 0; i < n; i++) lookup[i][0] = arr[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            lookup[i][j] = lookup[i][j - 1] < lookup[i + (1 << (j - 1))][j - 1] ?
                    lookup[i][j - 1] : lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}

//O(1)
int query(int l, int r) {
    int j = (int) log2(r - l + 1);
    return min(lookup[l][j], lookup[r - (1 << j) + 1][j]);
}
