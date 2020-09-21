#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    double sum = 0;
    for (int i=0, a; i<N; i++){
        scanf("%d", &a);
        sum += a;
    }
    printf("%.1lf\n", sum/N);
    return 0;
}