#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[40005];
ll mod = 100007;
ll N;

int main(){
    cin >> N;
    dp[0] = 1;
    for (ll i=1; i<=N; i++){
        for (ll j=1; j<=i; j++){
            dp[i] += j*dp[i-j]%mod;
            dp[i] %= mod;
        }
    }
    // for (int i=0; i<=N; i++){
    //     cout << dp[i] << " ";
    // } cout << endl;
    ll ans = 0;
    for (ll i=2; i<=N; i++){
        ans += (i-1)*i/2 * dp[N-i] % mod * N % mod;
        ans %= mod;
    }
    ans += N; // case when we have a circle on the outside
    ans %= mod;
    cout << ans << endl;
    return 0;
}