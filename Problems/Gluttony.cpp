#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N; ll K;
ll consumption[200005];
ll difficulty[200005];

ll trainingSets(ll m){
    ll cont = 0;
    for (int i=1; i<=N; i++){
        ll newIdx = m / difficulty[i];
        if (newIdx < consumption[i]) cont += consumption[i] - newIdx;
    }
    return cont;
}

int main() {
    scanf("%d %lld", &N, &K);
    for (int i=1; i<=N; i++){
        scanf("%lld", &consumption[i]);
    }
    for (int i=1; i<=N; i++){
        scanf("%lld", &difficulty[i]);
    }
    sort(consumption+1, consumption+1+N);
    sort(difficulty+1, difficulty+1+N, greater<ll>());
    ll l = 0, r = -1, m;
    for (int i=1; i<=N; i++) r = max(r, consumption[i]*difficulty[i]);
    while (r - l > 1LL){
        m = (l+r)/2LL;
        if (trainingSets(m) > K) l = m;
        else r = m;
    }
    if (l == 0){
        if (trainingSets(0) <= K) l--;
    }
    printf("%lld\n", ++l);
    return 0;
}