#include <bits/stdc++.h>
using namespace std;
int T;
int colours[3][4];
int res[4];
int tot = 1000000;
int main(){
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        memset(colours, 0, sizeof(colours));
        for (int i=0; i<3; i++){
            for (int j=0; j<4; j++){
                scanf("%d", &colours[i][j]);
            }
        }
        memset(res, 0, sizeof(res));
        int rem = tot;
        for (int i=0; i<4; i++){
            int v = rem;
            for (int j=0; j<3; j++){
                v = min(v, colours[j][i]);
            }
            res[i] = v;
            rem -= v;
        }

        printf("Case #%d: ", t);
        if (rem > 0) printf("IMPOSSIBLE\n");
        else {
            for (int i=0; i<4; i++){
                printf("%d ", res[i]);
            }
            printf("\n");
        }
    }
    return 0;
}