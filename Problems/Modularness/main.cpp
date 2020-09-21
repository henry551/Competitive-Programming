//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll K, Q;
ll diff[5005];
ll diffNew[5005];
int main() {
    cin >> K >> Q;
    for (int i=0; i<K; i++){
        scanf("%lld", &diff[i]);
    }
    ll n, m, x;
    for (int q=0; q<Q; q++){
        scanf("%lld %lld %lld", &n, &x, &m);
        ll sub = 0;
        ll sumRem = x%m;
        ll sumTot = 0;
        for (ll i=0; i<K; i++){
            diffNew[i] = diff[i] % m;
            if (diffNew[i] == 0) {
                sub += (n-1)/K;
                if (i < n-1-(n-1)/K*K) sub++;
            }
            else {
                sumRem += (n-1)/K * diffNew[i];
                if (i < n-1-(n-1)/K*K) sumRem += diffNew[i];
                sumTot += sumRem/m;
                sumRem %= m;
            }
            //cout << i << " " << diffNew[i] << " " << sub << " " << sumTot << endl;
        }
        sub += sumTot;
        printf("%lld\n", n-1-sub);
    }
    return 0;
}
