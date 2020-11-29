#include <bits/stdc++.h>
using namespace std;
int x, y, xmin, ymin, xmax, ymax;
int main() {
    scanf("%d %d %d %d %d %d", &x, &y, &xmin, &ymin, &xmax, &ymax);
    double ans;
    if (xmin <= x && x <= xmax) ans = min(abs(y-ymin), abs(y-ymax));
    else if (ymin <= y && y <= ymax) ans = min(abs(x-xmin),abs(x-xmax));
    else {
        double dy = min(abs(y-ymin), abs(y-ymax));
        double dx = min(abs(x-xmin),abs(x-xmax));
        ans = sqrt(pow(dy,2)+pow(dx,2));
    }
    printf("%.3lf\n", ans);
    return 0;
}