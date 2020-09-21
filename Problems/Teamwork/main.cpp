#include <bits/stdc++.h>
using namespace std;
int N, K;
int arr[10005];
int dp[10005];

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++){
        scanf("%d", &arr[i]);
    }
    for (int i=1; i<=N; i++){
        int mx = 0;
        for (int j=i-1; j>=max(0, i-K); j--){
            mx = max(mx, arr[j+1]);
            dp[i] = max(dp[i], dp[j]+(i-j)*mx);
        }
    }
    printf("%d\n", dp[N]);
    return 0;
}