#include <bits/stdc++.h>
using namespace std;

int T, N, M, A, B;
int main(){
    cin >> T;
    for (int tt=1; tt<=T; tt++){
        scanf("%d %d %d %d", &N, &M, &A, &B);
        if (N+M-1 > min(A,B)) printf("Case #%d: Impossible\n", tt);
        else {
        printf("Case #%d: Possible\n", tt);
            for (int i=0; i<N; i++){
                for (int j=0; j<M; j++){
                    if (i == 0){
                        if (j < M-1) {
                            printf("1 ");
                        } else {
                            printf("%d ", B-(N+M-2));
                        }
                    }
                    else if (i == N-1) {
                        if (j < M-1) {
                            printf("1 ");
                        } else {
                            printf("%d ", A-(N+M-2));
                        }
                    }
                    else {
                        if (j == 0) printf("1 ");
                        else printf("1000 ");
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}