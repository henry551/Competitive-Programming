#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;

ll power(ll b, ll e) {
    ll res = 1;
    while (e > 0) {
        if (e & 1) {
            res = res*b;
            res %= mod;
        }
        e = e>>1;
        b = b*b;
        b %= mod;
    }
    return res;
}

int concatenatedBinary(int n) {
    long long ans = 0;
    for (int i=1; i<=n; i++){
        ans *= power(2, 32 - __builtin_clz(i));
        ans %= mod;
        ans += i;
        ans %= mod;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << concatenatedBinary(n) << endl;
    // cout << 32 - __builtin_clz(n) << endl;
    return 0;
}