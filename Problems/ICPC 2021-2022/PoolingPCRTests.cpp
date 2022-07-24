#include <bits/stdc++.h>
using namespace std;

double p;
double all_neg;
int main(){
    cin >> p;
    bool all_greater = true;
    int hIdx = 0;
    double best = INT_MAX;
    for (int i=1; i<=16; i++){
        all_neg = pow(1-p, i);
        double expected = all_neg + i*(1-all_neg);
        if (expected < i-0.00000001) all_greater = false;
        expected /= i;
        if (expected < best) {
            best = expected;
            hIdx = i;
        }
        // cout << i << " " << expected << " " << best << " " << hIdx << endl;
    }
    if (all_greater) cout << 1 << endl;
    else cout << hIdx << endl;
}