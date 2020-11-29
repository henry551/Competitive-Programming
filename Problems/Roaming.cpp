//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll fact[200005];
int N, K;

ll power (ll b, ll e){
    ll res = 1;
    while (e > 0){
        if (e % 2 == 1) res = (res * b) % mod;
        b = (b * b) % mod;
        e /= 2;
    }
    return res;
}

ll inv(ll a){
    return power(a, mod-2);
}

ll factorial(ll a){
    if (a == 0) return 1;
    if (fact[a] != -1) return fact[a];
    return fact[a] = factorial(a-1) * a % mod;
}

ll comb(ll n, ll r){
    return factorial(n) * inv(factorial(r)) % mod * inv(factorial(n-r)) % mod;
}

int main() {
    cin >> N >> K;
    memset(fact, -1, sizeof(fact));
    factorial(N);
    ll ans = 0;
    for (int i=0; i<=min(N, K); i++){
        ans = (ans + comb(N,i) * comb(N-1, i) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
