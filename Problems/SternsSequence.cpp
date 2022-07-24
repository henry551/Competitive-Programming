#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mod = 998244353;

ll row = 0;
ll col = 0;
string find(ll x, ll y, ll a = 0, ll b = 1, ll c = 1, ll d = 0) {
    ll m = a + c, n = b + d;
    if (x == m && y == n)
        return "";
    if (x*n < y*m){
        row++;
        return 'L' + find(x, y, a, b, m, n);
    }
    else{
        row++;
        return 'R' + find(x, y, m, n, c, d);
    }
}

ll power(ll b, ll e){
    ll res = 1;
    while (e > 0){
        if (e & 1) {
            res *= b;
            res %= mod;
        }
        e = e>>1;
        b *= b;
        b %= mod;
    }
    return res;
}

int main(){
    int x, y;
    cin >> x >> y;
    string loc = find(x, y, 0, 1, 1, 0);
    ll tot = power(2, row)-1;
    tot %= mod;
    if (tot < 0) tot += mod;
    ll extra = 0;

    int n = loc.length();
    for (int i=0; i<n; i++){
        if (loc[i] == 'R') {
            extra += power(2, i);
            extra %= mod;
        }
    }

    extra += 1;
    // cout << row << " " << extra << endl;
    cout << (tot + extra) % mod << endl;
    return 0;
}