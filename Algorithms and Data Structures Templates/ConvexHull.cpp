#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> P;
vector<pii> H;

//Time Complexity: O(nlogn)
bool compare(pii a, pii b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

//positive if clockwise
double cross(pii O, pii A, pii B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

//Returns a list of points on the convex hull
void convexHull() {
    int n = P.size(), k = 0;
    if (n < 3) return;
    H.resize(2 * n);
    sort(P.begin(), P.end(), compare);

    //Lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    //Upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k - 1);
}