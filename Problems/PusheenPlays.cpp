#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c, d;
int Q;
int dp[10000005];

int func(int num){
    if (num <= 0) return 1;
    if (num <= 10000000)
        return dp[num];
    else
        return func(num/a-b)+func(num/c-d);
}

int main() {
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &Q);
    dp[0]=1;
    for (int i=1; i<=10000000; i++){
        int q = max(0, i/a-b);
        int w = max(0, i/c-d);
        dp[i] = dp[q]+dp[w];
    }
    int val;
    for (int i=0; i<Q; i++){
        scanf("%d", &val);
        printf("%d\n", func(val));
    }
    return 0;
}