#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, N, P;
ll press[1005][105];
ll dp[1005][2];
ll inf = 0x3f3f3f3f3f3f3f3f;
int main(){
    cin >> T;
    for (int t=1; t<=T; t++){
        scanf("%d %d", &N, &P);
        for (int i=1; i<=N; i++){
            for (int j=0; j<P; j++){
                scanf("%lld", &press[i][j]);
            }
        }
        for (int i=1; i<=N; i++){
            sort(press[i], press[i]+P);
        }

        memset(dp, inf, sizeof(dp));
        press[0][0] = 0; press[0][P-1] = 0;
        dp[0][0] = 0; dp[0][1] = 0;
        for (int i=1; i<=N; i++){
            int diff = press[i][P-1] - press[i][0];
            dp[i][0] = diff + min(dp[i-1][0]+abs(press[i-1][0]-press[i][P-1]), dp[i-1][1]+abs(press[i-1][P-1]-press[i][P-1]));
            dp[i][1] = diff + min(dp[i-1][0]+abs(press[i-1][0]-press[i][0]), dp[i-1][1]+abs(press[i-1][P-1]-press[i][0]));
        }
        
        printf("Case #%d: %lld\n", t, min(dp[N][0], dp[N][1]));
    }
    return 0;
}