//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int T, N;
int mat[105][105];
bool contain[105];
int main() {
    cin >> T;
    for (int i=0; i<T; i++){
        scanf("%d", &N);
        for (int j=1; j<=N; j++){
            for (int k=1; k<=N; k++){
                scanf("%d", &mat[j][k]);
            }
        }
        printf("Case #%d: ", i+1);
        int trace = 0;
        for (int j=1; j<=N; j++){
            trace += mat[j][j];
        }
        int row = 0;
        for (int j=1; j<=N; j++){
            memset(contain, false, sizeof(contain));
            for (int k=1; k<=N; k++){
                if (contain[mat[j][k]]) {
                    row++;
                    break;
                }
                contain[mat[j][k]] = true;
            }
        }
        int col = 0;
        for (int j=1; j<=N; j++){
            memset(contain, false, sizeof(contain));
            for (int k=1; k<=N; k++){
                if (contain[mat[k][j]]) {
                    col++;
                    break;
                }
                contain[mat[k][j]] = true;
            }
        }
        printf("%d %d %d\n", trace, row, col);
    }
    return 0;
}
