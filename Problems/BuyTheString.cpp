#include <bits/stdc++.h>
using namespace std;
int t;
int n, c0, c1, h;
int main(){
    cin >> t;
    for (int tst = 0; tst < t; tst++){
        scanf("%d %d %d %d", &n, &c0, &c1, &h);
        string s;
        cin >> s;
        if (abs(c1 - c0) > h){
            if (c1 > c0) c1 = c0 + h;
            else c0 = c1 + h;
        }
        int ans = 0;
        for (int i=0; i<n; i++){
            int a = s[i] - '0';
            if (a==0) ans += c0;
            else ans += c1;
        }
        printf("%d\n", ans);
    }
    return 0;
}