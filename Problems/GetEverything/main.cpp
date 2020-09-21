#include <iostream>
#include <vector>
#include <cstring>
typedef long long ll;

using namespace std;
int N, M; //boxes, keys
ll dp[2][1<<12];
ll unlock;
ll INF = 0x3f3f3f3f3f3f3f3f;
int main() {
    scanf("%d %d", &N, &M);
    ll a, b;
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for (int i=1; i<=M; i++){
        scanf("%lld %lld", &a, &b);
        unlock = 0;
        ll c;
        for (ll j=0; j<b; j++){
            scanf("%lld", &c);
            unlock |= (1<<(c-1));
        }
        for (int j=0; j<=(1<<N)-1; j++) dp[i%2][j] = dp[(i+1)%2][j];
        for (ll j=1; j<=(1<<N)-1; j++){
                if (unlock & j) {
                    dp[i%2][j] = min(dp[i%2][j], dp[(i + 1)%2][j ^ (unlock & j)] + a);
                }
        }
    }
    if (dp[M%2][(1<<N)-1] == INF) printf("-1\n");
    else printf("%lld\n", dp[M%2][(1<<N)-1]);
    return 0;
}