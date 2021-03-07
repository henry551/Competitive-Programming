#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll p, q, n, m;
int main(){
    cin >> p >> q >> n >> m;
    ll r = -1, g = -1;
    for (ll d = ceil(1.0*n*(n-1)/q)*q; d <= m*(m-1); d += q){
        // cout << "d: " << d << endl;
        ll prod = (d/q)*p;
        if (prod % 2 != 0) continue;
        prod /= 2;
        // cout << prod << endl;

        ll discrim = 1+4*d;
        ll disSqrt = sqrt(discrim);
        if (disSqrt*disSqrt != discrim) {
            continue;
        }
        ll sum = 1 + disSqrt;
        if (sum % 2 != 0) continue;
        sum /= 2;
        // cout << "data" << endl;
        // cout << d << " " << sum << " " << prod << endl;
        
        discrim = sum*sum - 4 * prod;
        if (discrim < 0) continue;
        // cout << discrim << endl;
        disSqrt = sqrt(discrim);

        // cout << discrim << " " << disSqrt << endl;
        if (disSqrt*disSqrt != discrim) {
            continue;
        }
        // cout << disSqrt << endl;
        r = sum - disSqrt;
        if (r % 2 != 0) continue;
        r /= 2;
        g = sum - r;
        cout << r << " " << g << endl;
        return 0;
    }
    cout << "NO SOLUTION" << endl;
    return 0;
}