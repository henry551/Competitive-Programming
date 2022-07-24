#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
int N;
ll A[10005];
unordered_map <ll, ll> factors;
unordered_map <ll, ll> newfactors;
ll mod = 1000000007;
ll lcm = 1;

ll power(ll b, ll e){
    ll res = 1;
    while (e > 0){
        if (e & 1) res = res * b % mod;
        e /= 2;
        b = b * b % mod;
    }
    return res;
}

ll inverse(ll num){
    return power(num, mod-2);
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++){
        scanf("%lld", &A[i]);
    }
    for (int i=0; i<N; i++){
        int p = sqrt(A[i])+1;
        int copy = A[i];
        for (int j=2; j<=p; j++){
            while (copy%j == 0) {
                newfactors[j]++;
                copy/=j;
            }
        }
        if (copy != 1) newfactors[copy]++;
        for (auto it: newfactors){
            factors[it.first] = max(factors[it.first], it.second);
        }
        newfactors.clear();
    }
    for (auto it: factors){
        lcm *= power(it.first, it.second);
        lcm %= mod;
    }
    ll sum = 0;
    for (int i=0; i<N; i++){
        sum += (lcm * inverse(A[i])) % mod;
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}
