#include <bits/stdc++.h>
using namespace std;
int T, N;
int D[100005];
int f[100005];
int b[100005];
int main(){
    cin >> T;
    for (int t=1; t<=T; t++){
        scanf("%d", &N);
        memset(D, 0, sizeof(D));
        memset(f, 0, sizeof(f));
        memset(b, 0, sizeof(b));
        for (int i=1; i<=N; i++){
            scanf("%d", &D[i]);
        }
        int prev = 0;
        int prevScore = 0;
        for (int i=1; i<=N; i++){
            if (D[i] >= prev){
                prevScore++;
                prev = D[i];
            }
            f[i] = prevScore;
        }

        prev = 0;
        prevScore = 0;
        for (int i=N; i>=1; i--){
            if (D[i] >= prev){
                prevScore++;
                prev = D[i];
            }
            b[i] = prevScore;
        }

        int ans = 0;
        for (int i=0; i<=N; i++){
            ans = max(ans, f[i] + b[i+1]);
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}