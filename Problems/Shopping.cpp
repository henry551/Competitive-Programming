#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int N, Q;
ll items[200005];
int nxt[200005];
stack <int> pre;
ll sparse[20][200005];

void build(){
    for (int i=0; i<N; i++) sparse[0][i] = items[i];
    for (int i=1; i <= 31-__builtin_clz(N); i++){
        for (int j=0; j <= N-(1<<i); j++){
            sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j+(1<<(i-1))]);
        }
    }
}

ll query(int l, int r){
    int k = 31-__builtin_clz(r-l+1);
    return min(sparse[k][l], sparse[k][r-(1<<k)+1]);
}

int main() {
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &items[i]);
    }
    build();

    for (int i = 0; i < N; i++) {
        while (!pre.empty() && items[pre.top()] > items[i]) {
            nxt[pre.top()] = i;
            pre.pop();
        }
        pre.push(i);
    }

    ll a; int b, c;
    for (int i=0; i<Q; i++){
        scanf("%lld %d %d", &a, &b, &c);
        b--; c--;
        int idx = b;
        while (c >= idx && query(idx,c) <= a){
            //cout << idx << " " << c << " " << a << " " << query(idx, c) << endl;
            a %= items[idx];
            if (nxt[idx] == 0) break;
            idx = nxt[idx];
            //cout << a << " " << idx << endl;
        }
        printf("%lld\n", a);
    }

    return 0;
}