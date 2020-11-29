#include <bits/stdc++.h>
using namespace std;
int R, C, N;
bool row[31005];
bool col[31005];
int main() {
    for (int q=0; q<5; q++){
        scanf("%d %d %d", &R, &C, &N);
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        for (int i=0, a, b; i<N; i++){
            scanf("%d %d", &a, &b);
            row[a] = true;
            col[b] = true;
        }
        int r = 0, c = 0;
        for (int i=1; i<=R; i++){
            if (row[i]) r++;
        }
        for (int j=1; j<=C; j++){
            if (col[j]) c++;
        }
        printf("%d\n", R*C - (r*C+c*R-r*c));
    }
    return 0;
}