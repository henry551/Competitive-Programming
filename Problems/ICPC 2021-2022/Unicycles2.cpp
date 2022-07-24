#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[40005];
ll mod = 100007;
ll N;

ll cycleComb(ll i){
    // i represents number of nodes
    return (i-1)*i/2;
}

int main(){
    cin >> N;
    dp[0] = 1;
    for (ll i=1; i<=N; i++){
        for (ll j=1; j<=i; j++){
            dp[i] += j*dp[i-j]%mod;
            dp[i] %= mod;
        }
    }
    ll ans = 0;

    for (ll i=0; i<=N-2; i++){
        for (ll j=0; i+j<=N-2; j++){
            ans += cycleComb(N-i-j) * dp[i] % mod * dp[j] % mod;
            ans %= mod;
        }
    }

    ans %= mod;
    cout << ans << endl;
    return 0;
}