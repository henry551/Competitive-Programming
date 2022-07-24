#include <bits/stdc++.h>
using namespace std;
unordered_map <int, int> dp;

int solve(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != 0) return dp[n];
    int bit = 31-__builtin_clz(n);
    int a = (1<<(bit-1));
    int b = (1<<bit) + (1<<(bit-1));
    dp[a] = solve(a);
    dp[n^b] = solve(n^b);
    return dp[a] + dp[n^b] + 1;
}

int main(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}