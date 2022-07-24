#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii; // height, index
int n;
int histogram[300]; //values are stored from 0 to n-1
stack<pii> area;

//Time Complexity: O(n)
int findMaxArea() {
    int best = INT_MIN; //best stores the maximum area
    histogram[n] = -1;
    for (int i = 0; i <= n; i++) {
        while (!area.empty() && area.top().first > histogram[i]) {
            int temp = area.top().first;
            area.pop();
            if (!area.empty()) best = max(best, temp * (i - area.top().second - 1));
            else best = max(best, temp * i);
        }
        area.push({histogram[i], i});
    }
    return best;
}