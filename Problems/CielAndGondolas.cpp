#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

int N, K;
int INF = 0x3f3f3f3f;
int psa[4005][4005];
int dp[2][4005];

int cost(int i, int j) {
    return (psa[j][j] - psa[i-1][j] - psa[j][i-1] + psa[i-1][i-1])/2;
}

// Search range for our DP is in the range [qL, qR]
// In this branch, calculating dp[k][cL,..cR]
void dnc(int qL, int qR, int cL, int cR, int k) {
    if (cL > cR) return;
    int bestpos = -1;
    int newcost;
    int mid = (cL + cR) / 2;
    dp[k][mid] = INF;
    for (int i = qL; i <= min(qR, mid); ++i) {
        newcost = dp[!k][i-1] + cost(i, mid);
        if (dp[!k][i-1] + cost(i, mid) < dp[k][mid]) {
            dp[k][mid] = newcost;
            bestpos = i;
        }
    }
    dnc(qL, bestpos, cL, mid - 1, k);
    dnc(bestpos, qR, mid + 1, cR, k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    cin.ignore();
    for (int i = 1; i <= N; ++i){
        string s;
        getline(cin, s);
        for (int j = 1; j <= N; ++j)
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + (int(s[2 * (j - 1)]) - 48);
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;

    for (int i=1; i<=K; i++) dnc(1, N, 1, N, i & 1);
    cout << dp[K & 1][N] << endl;
    return 0;
}