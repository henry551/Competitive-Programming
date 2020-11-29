#include <iostream>
#include <vector>

using namespace std;

int N, K;
int INF = 0x3f3f3f3f;
int dp[2][4005];

int cost(int i, int j);

// Time Complexity: O(NKlogN)
// Necessary Condition: optimal_pos[k][i] <= optimal_pos[k][i+1]
// Search range for our DP is in the range [qL, qR]
// In this branch, calculating dp[k][cL,..cR]
void dnc(int qL, int qR, int cL, int cR, int k) {
    if (cL > cR) return;
    int bestpos = -1;
    int newcost;
    int mid = (cL + cR) / 2;
    dp[k][mid] = INF;
    for (int i = qL; i <= min(qR, mid); ++i) {
        // !k represents the k-1 row (mod 2)
        newcost = dp[!k][i-1] + cost(i, mid);
        if (dp[!k][i-1] + cost(i, mid) < dp[k][mid]) {
            dp[k][mid] = newcost;
            bestpos = i;
        }
    }
    dnc(qL, bestpos, cL, mid - 1, k);
    dnc(bestpos, qR, mid + 1, cR, k);
}

void runDivideAndConquery(){
    for (int i=1; i<=K; i++) dnc(1, N, 1, N, i & 1);
    cout << dp[K & 1][N] << endl;
}