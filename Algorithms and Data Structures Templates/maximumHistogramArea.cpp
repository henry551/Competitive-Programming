#include <iostream>
#include <deque>

using namespace std;
typedef pair<int, int> pii;
int n;
int histogram[300]; //values are stored from 0 to n-1
deque<pii> area;
int best = INT_MIN; //best stores the maximum area

//Time Complexity: O(n)
void findMaxArea() {
    for (int i = 0; i <= n; i++) {
        while (!area.empty() && area.back().first > histogram[i]) {
            int temp = area.back().first;
            area.pop_back();
            if (!area.empty()) best = max(best, temp * (i - area.back().second - 1));
            else best = max(best, temp * i);
        }
        area.push_back({histogram[i], i});
    }
}