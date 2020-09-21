#include <iostream>
using namespace std;
typedef long long ll;
ll N, M;
ll happiness[100005];
ll psa[100005];

ll numberGreater(ll m){
    ll l = 0, r = N-1;
    ll ans = 0;
    while (l <= r){
        if (happiness[l] + happiness[r] >= m) {
            ans += 2*(r-l)+1;
            r--;
        }
        else l++;
    }
    return ans;
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) scanf("%lld", &happiness[i]);
    sort(happiness, happiness+N);
//    for (int i=0; i<N; i++) cout << happiness[i] << " ";
//    cout << endl;
    for (int i=1; i<=N; i++) psa[i] = psa[i-1]+happiness[i-1];
    ll l = 0, r = 200001, m;
    while (l < r){
        m = (l+r)/2;
        if (numberGreater(m) < M) r = m;
        else l = m+1;
    }
    ll x = r-1;
    l = 0, r = N-1;
    ll ans = 0;

    while (l <= r){
        if (happiness[l] + happiness[r] >= x) {
            ans += (2*(r-l)+2)*happiness[r] + 2*(psa[r]-psa[l]);
            r--;
        }
        else l++;
    }
    if (numberGreater(x) > M) ans -= x*(numberGreater(x)-M);
    cout << ans << endl;
    return 0;
}
