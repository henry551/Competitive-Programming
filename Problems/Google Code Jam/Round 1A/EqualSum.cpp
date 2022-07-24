#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int T, N;
ll large = 1000000000;
set<ll, greater<ll>> B;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2 == 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

int main(){
    cin >> T;
    for (int t=1; t<=T; t++){
        cin >> N;

        // Input
        B.clear();
        ll inpTot = 0;
        ll v = 1;
        for (int i=0; i<=29; i++){
            printf("%lld ", v);
            inpTot += v;
            v *= 2L;
        }

        for (int i=0; i<70; i++){
            printf("%lld ", large-i);
            inpTot += large-i;
        }
        cout << endl;


        // Output
        ll val;
        ll sum = 0;
        for (int i=1; i<=N; i++){
            cin >> val;
            B.insert(val);
            sum += val;
        }
        sum += inpTot;
        sum /= 2;

        while (sum > inpTot) {
            auto it = B.begin();
            sum -= *it;
            printf("%lld ", *it);
            B.erase(it);
        }

        ll i = large;
        while (sum >= power(2, 30)) {
            sum -= i;
            printf("%lld ", i);
            i--;
        }

        ll exp = 1;
        while (sum > 0){
            if (sum % 2 == 1){
                printf("%lld ", exp);
            }
            sum /= 2;
            exp *= 2;
        }
        cout << endl;
    }
    return 0;
}