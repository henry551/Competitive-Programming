#include <bits/stdc++.h>
using namespace std;
int N;
int A[105], B[105], cop[105];
int main() {
    scanf("%d", &N);
    int a, b, tot, idx, sum;
    for (int i=0; i<N; i++){
        scanf("%d %d", &a, &b);
        A[a]++; B[b]++;
        tot = 0, idx = 100;
        for (int j=1; j<=100; j++){
            cop[j] = B[j];
        }
        for (int j=1; j<=100; j++){
            sum = A[j];
            while (sum > 0){
                if (cop[idx] == 0) {idx--; continue;}
                tot = max(tot, j+idx);
                if (sum >= cop[idx]) {
                    sum -= cop[idx];
                    cop[idx] = 0;
                }
                else {
                    cop[idx] -= sum;
                    sum = 0;
                }
            }
        }
        printf("%d\n", tot);
    }
    return 0;
}