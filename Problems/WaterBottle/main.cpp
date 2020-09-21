#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
int main() {
    int a, b, V;
    cin >> a >> b >> V;
    double ans;
    if (a*a*b >= 2*V){
        double x = 2.0*V/(a*b);
        ans = atan(b/x);
    } else {
        double x = 2.0*(b-1.0*V/(a*a));
        ans = atan(x/a);
    }
    ans *= 180/PI;
    printf("%.6lf\n", ans);
    return 0;
}