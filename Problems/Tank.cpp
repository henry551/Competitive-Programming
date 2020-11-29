#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pii;
ll N, P, M;
pii def[200005];
ll psa[200005];
ll phy[200005];
ll mag[200005];
ll val[200005];
ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    scanf("%lld %lld %lld", &N, &P, &M);
    for (int i=1; i<=N; i++){
        scanf("%lld %lld", &def[i].first, &def[i].second);
    }
    for (int i=1; i<=P; i++){
        scanf("%lld", &phy[i]);
    }
    sort(phy+1, phy+P+1);
    for (int i=1; i<=P; i++){
        psa[i] = psa[i-1]+phy[i];
    }
    for (int i=1; i<=N; i++){
        int l = 1, r = P+1, m;
        while (r-l > 1){
            m = (l+r)/2;
            if (def[i].first >= phy[m]) l = m;
            else r = m;
        }
        if (phy[l] < def[i].first) l++;
        if (l <= P) val[i] += psa[P] - psa[l-1] - def[i].first*(P-l+1);
    }

    memset(psa, 0, sizeof(psa));
    for (int i=1; i<=M; i++){
        scanf("%lld", &mag[i]);
    }
    sort(mag+1, mag+M+1);
    for (int i=1; i<=M; i++){
        psa[i] = psa[i-1]+mag[i];
    }
    for (int i=1; i<=N; i++){
        int l = 1, r = M+1, m;
        while (r-l > 1){
            m = (l+r)/2;
            if (def[i].second >= mag[m]) l = m;
            else r = m;
        }
        if (mag[l] < def[i].second) l++;
        if (l <= M) val[i] += psa[M] - psa[l-1] - def[i].second*(M-l+1);
    }
    ll best = INF, idx = 0;
    for (int i=1; i<=N; i++){
        if (val[i] < best){
            best = val[i];
            idx = i;
        }
    }
    printf("%lld\n", idx);
    return 0;
}