#include <iostream>
using namespace std;
typedef long long ll;
ll N, K;
ll arr[100005];
ll fact[100005];
ll mod = 1000000007;
ll tot = 0;

ll factorial (ll num){
    if (num == 0) return fact[num] = 1;
    return fact[num] = num * factorial(num-1) % mod;
}

ll power (ll b, ll e){
    ll res = 1;
    while (e > 0){
        if (e % 2 == 1) res = res * b % mod;
        e /= 2;
        b = b * b % mod;
    }
    return res;
}

ll inverse (ll num){
    return power(num, mod-2);
}

/* Return nCr */
ll choose (ll n, ll r){
    return (fact[n] * inverse(fact[r]) % mod) * inverse(fact[n-r]) % mod;
}

int main() {
    cin >> N >> K;
    for (int i=0; i<N; i++){
        scanf("%lld", &arr[i]);
    }
    factorial(N);
    sort(arr, arr+N);
    for (int i=0; i<N; i++){
        if (i <= N-K){
            tot -= (arr[i] * choose(N-i-1, K-1) % mod);
            if (tot < 0) tot += mod;
        }
        //cout << tot << " ";
        if (i >= K-1){
            tot += (arr[i] * choose(i, K-1) % mod);
            tot %= mod;
        }
        //cout << tot << endl;
    }
    cout << tot << endl;
    return 0;
}
