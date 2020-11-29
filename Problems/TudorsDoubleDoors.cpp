#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long x, y;
    scanf("%llu %llu", &x, &y);
    printf("%llu", x*y/2);
    if (x%2==0 || y%2==0) printf(".0\n");
    else printf(".5\n");
    return 0;
}