#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct line {
    long long m, b;
};

long long floordiv(long long a, long long b) {
    return a / b - (a % b && ((a < 0) ^ (b < 0)));
}

long long intersectInt(line a, line b) {
    return floordiv(b.b - a.b, a.m - b.m);
}

double intersect(line a, line b) {
    return (double) (b.b - a.b) / (a.m - b.m);
}

// Necessary Invariant: cht[i].m is in decreasing or increasing order.
vector<line> cht;

//Time Complexity: O(1) amortized
void add(line l) {
    auto n = cht.size();
    while (n >= 2 &&
           intersect(cht[n - 1], cht[n - 2]) >= intersect(cht[n - 1], l)) {
        cht.pop_back();
        n = cht.size();
    }
    cht.push_back(l);
}

//Time Complexity: O(logn)
ll query(ll x) {
    int l = 0;
    int r = cht.size() - 1;
    // Find largest idx such that x <= intersect(cht[idx], cht[idx+1])
    while (l < r) {
        int mid = (l + r) / 2;
        if (intersect(cht[mid], cht[mid + 1]) < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return cht[l].m * x + cht[l].b;
}


int cp;
//Time Complexity: O(1)
void addIncreasingQuery(line l) {
    auto n = cht.size();
    while (n >= 2 &&
           intersect(cht[n - 1], cht[n - 2]) >= intersect(cht[n - 1], l)) {
        cht.pop_back();
        n = cht.size();
    }
    cht.push_back(l);
    cp = min(cp, (int) cht.size() - 1);
}

//Time Complexity: O(1)
long long queryIncreasingQuery(long long x) {
    while (cp + 1 != cht.size() &&
           intersect(cht[cp], cht[cp + 1]) < x)
        cp++;
    return cht[cp].m * x + cht[cp].b;
}


int dp[105];
int baseCaseCost = 0;
int m[105];
int N;
int p[105];

int runAlgorithm() {
// Base case:
    dp[0] = baseCaseCost;
    line l;
    l.m = m[0];
    l.b = dp[0];
    add(l);
    for (int i = 1; i < N; i++) {
        dp[i] = query(p[i]);
        line l;
        l.m = m[i];
        l.b = dp[i];
        add(l);
    }
    return 0;
}