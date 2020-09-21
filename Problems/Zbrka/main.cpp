#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N, C;
ll mod = 1000000007;
ll dp[2][10005];
int main() {
    scanf("%d %d", &N, &C);
    ll lim = min(C, N*(N-1)/2);
    ll sum = 0;
    dp[0][0]=1;
    for (int i=1; i<=N; i++){
        sum = 0;
        for (int j=0; j<=lim; j++){
            sum += dp[(i-1)%2][j];
            if (j - (i-1) > 0) sum -= dp[(i-1)%2][j-i];
            dp[i%2][j]=sum;
            dp[i%2][j]%=mod;
        }
    }
    printf("%lld\n", dp[N%2][C]);
    return 0;
}