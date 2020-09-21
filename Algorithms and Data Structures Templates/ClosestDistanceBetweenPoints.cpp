#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
#define px second
#define py first
typedef pair<long long, long long> pll;

const int INF = 0x3f3f3f3f;
int n;
vector <pll> pnts;
set<pll> box;
set<pll>::iterator it;

//Time Complexity: O(nlogn)

int compare(pll a, pll b) {
    return a.px < b.px;
}

double closestPair() {
    sort(pnts.begin(), pnts.end(), compare);
    double best = INF;
    box.insert(pnts[0]);
    int left = 0;
    for (int i = 1; i < n; i++) {
        while (left < i && pnts[i].px - pnts[left].px > best) box.erase(pnts[left++]);
        for (it = box.lower_bound({pnts[i].py - best, pnts[i].px - best});
             it != box.end() && pnts[i].py + best >= it->py; it++)
            best = min(best, sqrt(pow(pnts[i].py - it->py, 2.0) + pow(pnts[i].px - it->px, 2.0)));
        box.insert(pnts[i]);
    }
    return best;
}