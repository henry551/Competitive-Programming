#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T;
int N, M;
int grid[305][305];

int neighbors(int i, int j){
    if (i == 0 || i == N-1) {
        if (j == 0 || j == M-1) return 2;
        else return 3;
    }
    if (j == 0 || j == M-1) return 3;
    return 4;
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++){
        scanf("%d %d", &N, &M);
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                scanf("%d", &grid[i][j]);
            }
        }

        bool works = true;
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                if (grid[i][j] > neighbors(i, j)) {
                    works = false;
                }
            }
        }

        if (!works) printf("NO\n");
        else {
            printf("YES\n");
            for (int i=0; i<N; i++){
                for (int j=0; j<M; j++){
                    printf("%d ", neighbors(i,j));
                }
                printf("\n");
            }
        }
    }
    return 0;
}
