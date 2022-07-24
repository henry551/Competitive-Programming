//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll L, R;
ll mod = 1000000007;
ll dp[63][2][2][2]; //digit, deviated from l, deviated from r, initial bit has been set

ll solve(int dig, int x, int y, int firstBit){
    if (dig == -1) return 1LL;
    if (dp[dig][x][y][firstBit] != -1) return dp[dig][x][y][firstBit];
    dp[dig][x][y][firstBit] = 0;
    if (x == 1 || !(1LL<<dig & L)){ // x 0, y 0
        dp[dig][x][y][firstBit] += (1LL<<dig & R) ? solve(dig-1, x, 1, firstBit) : solve(dig-1, x, y, firstBit);
    }
    if ((x == 1 || !(1LL<<dig & L)) && (y == 1 || (1LL<<dig & R)) && firstBit){ // x 0, y 1
        dp[dig][x][y][firstBit] += solve(dig-1, x, y, firstBit);
    }
    if (y == 1 || (1LL<<dig & R)){ // x 1, y 1
        dp[dig][x][y][firstBit] += !(1LL<<dig & L) ? solve(dig-1, 1, y, 1) : solve(dig-1, x, y, 1);
    }
    dp[dig][x][y][firstBit] %= mod;
    return dp[dig][x][y][firstBit];
}

int main() {
    cin >> L >> R;
    memset(dp, -1, sizeof(dp));
    cout << solve(62, 0, 0, 0) << endl;
    return 0;
}