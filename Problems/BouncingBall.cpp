#include <bits/stdc++.h>
using namespace std;
int t;
int n, p, k;
int bucket[100005];
int dp[100005];
int x, y;

int main(){
    cin >> t;
    for (int tst = 0; tst < t; tst++){
        scanf("%d %d %d", &n, &p, &k);
        string s;
        cin >> s;
        for (int i=0; i<n; i++){
            bucket[i] = s[i] - '0';
        }
        scanf("%d %d", &x, &y);
        for (int j=n-1; j>=0; j--){
            dp[j] = (j + k >= n ? 0 : dp[j+k]) + (bucket[j] == 0) * x;
        }
        int best = INT_MAX;
        for (int i=0; i + p - 1 < n; i++){
            best = min(best, dp[i+p-1] + y*i);
        }
        printf("%d\n", best);
    }
    return 0;
}