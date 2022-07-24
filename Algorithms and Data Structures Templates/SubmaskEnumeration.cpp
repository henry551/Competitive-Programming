#include <bits/stdc++.h>
using namespace std;

int n = 10;

// Time Complexity: O(3^n)
// Generates every submask of every mask
int main() {
    for (int m=0; m<(1<<n); ++m) {
        for (int s=m; s; s=(s-1)&m) {
            continue;
        }
    }
    return 0;
}