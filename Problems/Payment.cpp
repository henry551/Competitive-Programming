//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string N;
int num[1000005];
int dp[1000005][2];

int solve(int idx, int carry){
    if (idx < 0) return carry;
    if (dp[idx][carry] != -1) return dp[idx][carry];
    if (num[idx] == 9 && carry == 1) return dp[idx][carry] = solve(idx-1,1);
    return dp[idx][carry] = min(solve(idx-1,0)+num[idx]+carry, solve(idx-1,1) + (10 - (num[idx] + carry)));
}

int main() {
    cin >> N;
    int s = N.length();
    for (int i=s-1; i>=0; i--){
        num[s-1-i] = N[i]-'0';
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(s, 0) << endl;
    return 0;
}
