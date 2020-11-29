//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
int X, Y;
int p = 1000000007;
ll fact[1000005];

ll inverse(ll base){
    int e = p-2;
    ll res = 1;
    while (e > 0){
        if (e & 1) res = (res*base)%p;
        base = (base*base) % p;
        e /= 2;
    }
    return res;
}

ll comb(int n, int r){
    // returns nCr mod p
    fact[0] = 1;
    for (int i=1; i<=n; i++) fact[i] = (i*fact[i-1])%p;
    return fact[n] * inverse(fact[r]) % p * inverse(fact[n-r]) % p;
}

int main() {
    cin >> X >> Y;
    int a, b;
    a = (2*Y-X)/3;
    b = (2*X-Y)/3;
    if (a >= 0 && b >= 0 && 3*a == 2*Y-X && 3*b == 2*X-Y){
        cout << comb(a+b, a) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}