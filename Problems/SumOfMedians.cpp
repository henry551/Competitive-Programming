#include <bits/stdc++.h>

using namespace std;
int t;
int n, k;
int arr[1000005];

int main(){
    cin >> t;
    for (int tst = 0; tst < t; tst++){
        scanf("%d %d", &n, &k);
        for (int i=1; i<=n*k; i++){
            scanf("%d", &arr[i]);
        }
        int idx = n*k - (n - (n+1)/2);
        int num = 0;
        long long ans = 0;
        while (num < k){
            ans += arr[idx];
            idx -= (n - (n+1)/2 + 1);
            num++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}