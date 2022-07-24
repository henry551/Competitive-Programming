#include <bits/stdc++.h>
using namespace std;
double dp[18][(1<<18)];
int n;
double rate[18][18];
int s, e;

double solve(int v, int mask) {
    if (v == e) {
        return dp[v][mask] = 1;
    }
    if (dp[v][mask] != -1) {
        return dp[v][mask];
    }
    double best = 1;
    for (int i=0; i<n; i++){
        if (mask & (1<<i)) {
            best = min(best, rate[v][i] * solve(i, mask ^ (1<<i)));
        }
    }
    return dp[v][mask] = best;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> rate[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<(1<<n); j++){
            dp[i][j] = -1;
        }
    }
    cin >> s >> e;
    cout << solve(s, ((1<<n)-1) ^ (1<<s)) << endl;
    return 0;
}