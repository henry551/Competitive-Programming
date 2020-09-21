//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
int N, K;
ll height[305];
ll dp[305][305]; //dp[x][y], x -> rightmost element, y -> # of elements
ll INF = 0x3f3f3f3f3f3f3f3f;
int main() {
    cin >> N >> K;
    for (int i=1; i<=N; i++){
        scanf("%lld", &height[i]);
    }
    memset(dp, INF, sizeof(dp));
    for (int i=1; i<=N; i++) {
        dp[i][0] = 0;
        dp[i][1] = height[i];
    }
    for (int x=1; x<=N; x++){
        for (int y=2; y<=N-K; y++){
            for (int k=1; k<x; k++){
                dp[x][y] = min(dp[x][y], dp[k][y-1]+max(0LL, height[x]-height[k]));
            }
        }
    }
    ll ans = LONG_LONG_MAX;
    for (int i=1; i<=N; i++){
        ans = min(ans, dp[i][N-K]);
    }
    cout << ans << endl;
    return 0;
}