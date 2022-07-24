#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct line {
    ll m, b;
};

long long floordiv(long long a, long long b) {
    return a / b - (a % b && ((a < 0) ^ (b < 0)));
}

long long intersect(line a, line b) {
    return floordiv(b.b - a.b, a.m - b.m);
}

// Invariant: cht[i].m is in decreasing order.
vector<line> cht;

void add(line l) {
    auto n = cht.size();
    while (n >= 2 &&
           intersect(cht[n - 1], cht[n - 2]) >= intersect(cht[n - 1], l)) {
        cht.pop_back();
        n = cht.size();
    }
    cht.push_back(l);
}

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

ll dp[1000005];
int n, c;
ll x[1000005];
ll INF = 0x3f3f3f3f3f3f3f3f;

int main(){
    cin >> n >> c;
    for (int i=0; i<n; i++){
        scanf("%lld", &x[i]);
    }
    for (int i=0; i<n; i++){
        ll best = INF;
        if (i==0) {
            dp[i] = c;
            best = 0;
        } else {
            best = min(query(x[i]), dp[i-1] - x[i]*x[i]);
            dp[i] = best + c + x[i]*x[i];
        }
        line l;
        l.m = -2 * x[i];
        l.b = (i == 0 ? 0 : dp[i-1]) + x[i] * x[i];
        add(l);
    }
//    for (int i=0; i<n; i++){
//        cout << dp[i] << endl;
//    }
    cout << dp[n-1] << endl;
}