#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N; ll K;
ll adj[52][52];
ll res[52][52];
ll cop[52][52];
ll mod = (ll) round(1e9+7);
ll tot = 0;

void mult(ll a[52][52], ll b[52][52]){
    memset(cop, 0, sizeof(cop));
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            for (int k=0; k<N; k++){
                cop[i][j] += a[i][k]*b[k][j];
                cop[i][j] %= mod;
            }
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            a[i][j] = cop[i][j];
        }
    }
}

void power(ll exp){
    while (exp > 0){
        if (exp % 2 == 1) mult(res, adj);
        exp /= 2;
        mult(adj, adj);
    }
}

int main() {
    scanf("%d %lld", &N, &K);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%lld", &adj[i][j]);
        }
        res[i][i] = 1;
    }
    power(K);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            tot += res[i][j];
        }
    }
    printf("%lld\n", tot%mod);
    return 0;
}