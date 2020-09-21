#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000013;
ll power(ll b, ll e){
    b%=mod;
    ll res = 1;
    while (e > 0){
        if (e%2==1) {
            res *= b;
            res %= mod;
        }
        b *= b;
        b %= mod;
        e /= 2;
    }
    return res;
}
ll N;
int main() {
    scanf("%lld", &N);
    ll tot = 0;
    if (N==1) printf("1\n");
    else {
        tot += power(2,N-2);
        ll temp = 0;
        if (N%2==0){
            temp = power(2,N/2-1);
            if (N%8==0) tot += temp;
            else if (N%8==4) tot -= temp;
        }
        else {
            temp = power(2,(N-3)/2);
            if (N%8==1 || N%8==7) tot += temp;
            else tot -= temp;
        }
        tot %= mod;
        if (tot < 0) tot += mod;
        printf("%lld\n", tot);
    }
    return 0;
}