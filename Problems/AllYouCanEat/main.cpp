//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair <int,int> pii;
int N, T;
pii dish[3005];
int dp[6005];
int main() {
    cin >> N >> T;
    for (int i=1; i<=N; i++){
        scanf("%d %d", &dish[i].first, &dish[i].second);
    }
    sort(dish+1, dish+N+1);
    int ans = 0;
    for (int i=1; i<=N; i++){
        for (int j=0; j<=T-1; j++){
            ans = max(ans, dp[j]+dish[i].second);
        }
        for (int j=T-1; j>=dish[i].first; j--){
            dp[j] = max(dp[j], dp[j-dish[i].first]+dish[i].second);
        }
    }
    cout << ans << endl;
    return 0;
}