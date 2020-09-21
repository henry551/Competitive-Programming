//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll fact[200005];

ll power(ll b, ll e){
    ll res = 1;
    while (e > 0){
        if (e % 2 == 1) res = res * b % mod;
        b = b * b % mod;
        e /= 2;
    }
    return res;
}

ll inv(ll a){
    return power(a, mod-2);
}

ll factorial(int a){
    if (a == 0) return fact[a] = 1;
    if (fact[a] != -1) return fact[a];
    return fact[a] = factorial(a-1) * a % mod;
}

ll comb(int n, int r){
    if (n <= 200000) return factorial(n)* inv(factorial(n-r)) % mod * inv(factorial(r)) % mod;
    ll ans = 1;
    for (int i = n; i > n-r; i--){
        ans = (ans * i) % mod;
    }
    for (int i=1; i <= r; i++){
        ans = (ans * inv(i)) % mod;
    }
    return ans;
}

ll N, A, B;
int main() {
    cin >> N >> A >> B;
    memset(fact, -1, sizeof(fact));
    factorial(min(N, 200000LL));
    ll ans = ((((power(2,N) - comb(N, A) ) % mod - comb(N, B)) % mod) - 1) % mod;
    if (ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}
