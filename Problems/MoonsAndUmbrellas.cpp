#include <bits/stdc++.h>
using namespace std;
int T, X, Y;
string s;
int dp[1005][2];
int INF = 0x3f3f3f3f;

int main(){
    cin >> T;
    for (int tt=0; tt<T; tt++){
        cin >> X >> Y >> s;
        memset(dp, 0, sizeof(dp));
        int L = s.length();
        for (int i=1; i<L; i++){
            if (s[i] == 'J'){
                if (s[i-1] == 'C') {
                    dp[i][1] = dp[i-1][0] + X;
                } else if (s[i-1] == 'J'){
                    dp[i][1] = dp[i-1][1];
                } else {
                    dp[i][1] = min(dp[i-1][1], dp[i-1][0] + X);
                }
                dp[i][0] = INF;
            }
            else if (s[i] == 'C'){
                if (s[i-1] == 'C'){
                    dp[i][0] = dp[i-1][0];
                } else if (s[i-1] == 'J'){
                    dp[i][0] = dp[i-1][1] + Y;
                } else {
                    dp[i][0] = min(dp[i-1][0], dp[i-1][1] + Y);
                }
                dp[i][1] = INF;
            }
            else {
                if (s[i-1] == 'C'){
                    dp[i][0] = dp[i-1][0];
                    dp[i][1] = dp[i-1][0] + X;
                } else if (s[i-1] == 'J'){
                    dp[i][1] = dp[i-1][1];
                    dp[i][0] = dp[i-1][1] + Y;
                } else {
                    dp[i][0] = min(dp[i-1][0], dp[i-1][1] + Y);
                    dp[i][1] = min(dp[i-1][1], dp[i-1][0] + X);
                }
            }
        }
        // for (int i=0; i<L; i++){
        //     cout << dp[i][0] << " " << dp[i][1] << endl;
        // }
        printf("Case #%d: %d\n", tt+1, min(dp[L-1][0], dp[L-1][1]));
    }
    return 0;
}