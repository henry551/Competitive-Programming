#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int T;
ll tim[3];
ll r = 4.32e13;

ll mod(ll a, ll m = r) {
    a %= m;
    if (a < 0) {
        a += m;
    }
    return a;
}

ll divisible(ll a, ll b) {
    if (a/b*b == a) {
        return true;
    } else {
        return false;
    }
}

int main(){
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        ll n = -1, k = -1;
        cin >> tim[0] >> tim[1] >> tim[2];
        do {
            ll h = tim[0], m = tim[1], s = tim[2];
            n = -1, k = -1;
            ll tik = mod(m - h);
            ll shift = mod(s-60*m);
            bool success = false;
            for (ll i=0; i<11; i++){
                if (divisible(r*i+tik, 11)){
                    // cout << i << " " << r*i+tik << " " << tik << endl;
                    n = (r*i+tik)/11;
                    // cout << "HUH " << mod(m-h) << " " << tik << " " << mod(11*n) << endl;
                    for (ll i = 0; i<59; i++){
                        if (divisible(r*i+shift, 59)){
                            // cout << i << " " <<  r*i+shift << " " << shift << endl;
                            k = (r*i+shift)/59;
                            // cout << "DAHELL" << " " << mod(s-60*m) << " " << mod(59*k) << " " << mod(shift) << endl;
                            // cout << "WTF " << mod(h) << " " << mod(n-k) << endl;
                            // cout << "AAA " << mod(m) << " " << mod(12*n-k) << endl;
                            // cout << mod(mod(12*n-k) - mod(n-k)) << endl;
                            if (mod(h) == mod(n-k) && mod(m) == mod(12*n-k) && mod(s) == mod(720*n-k)){
                                success = true;
                                break;
                            }
                        }
                    }
                    if (success) {
                        break;
                    }
                }
            }
            // cout << n << " " << k << endl;
            if (success) {
                ll hour = mod(n)/(r/12);
                ll minute = mod(12*n)/(r/60);
                ll second = mod(720*n)/(r/60);
                cout << mod(mod(720*n), r/60) << endl;
                cout << n << " " << k << endl;
                ll nano = mod(n, 1e9);

                break;
            }
        } while (next_permutation(tim, tim+3));
    }
    return 0;
}