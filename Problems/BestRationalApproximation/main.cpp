#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int main() {
    int M; double k;
    double minDiff = 10000000;
    pii ans;
    scanf("%d %lf", &M, &k);
    for (int q=1; q<=M; q++){
        double p;
        p = q*k;
        int a, b;
        a = (int) p;
        b = (int) p+1;
        if (abs(a*1.0/q-k) < minDiff){
            minDiff = abs(a*1.0/q-k);
            ans = {a, q};
        }
        if (abs(b*1.0/q-k) < minDiff){
            minDiff = abs(b*1.0/q-k);
            ans = {b, q};
        }
    }
    printf("%d/%d\n", ans.first, ans.second);
    return 0;
}