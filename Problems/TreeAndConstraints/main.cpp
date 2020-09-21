#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int N, M;
vector <int> edges[55];
int par[55];
int depth[55];
int ancestor[55][55];
int vertexA[55];
int vertexB[55];
int prefix[55];

void dfs(int v, int p, int d){
    par[v] = p;
    depth[v] = d;
    for (int e: edges[v]){
        if (e != p) dfs(e, v, d+1);
    }
}

int dfsCount(int v, int p){
    int ans = 0;
    for (int e: edges[v]){
        if (e != p) {
            ans += dfsCount(e, v);
            if (prefix[e] > 0) ans++;
            prefix[v] += prefix[e];
        }
    }
    return ans;
}

int lca(int u, int v){
    if (depth[u] < depth[v]) swap(u,v);
    while (depth[u] > depth[v]){
        u = par[u];
    }
    while (u != v){
        u = par[u];
        v = par[v];
    }
    return u;
}

void update(int v, int anc){
    //cout << v << " b " << anc << endl;
    prefix[v]++;
    prefix[anc]--;
}

int bitCount(ll msk){
    int tot = 0;
    for (ll i=0; i<64; i++) {
        if (msk & (1LL << i)) tot++;
    }
    return tot;
}

int main() {
    cin >> N;
    int a, b;
    for (int i=0; i<N-1; i++){
        scanf("%d %d", &a, &b);
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    dfs(0,0,0);
    cin >> M;
    for (int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        vertexA[i] = a-1;
        vertexB[i] = b-1;
        ancestor[b-1][a-1] = ancestor[a-1][b-1] = lca(a-1,b-1);
    }
    ll ans = 0;
    for (ll msk = 0; msk < (1LL<<M); msk++){
        memset(prefix, 0, sizeof(prefix));
        for (ll i = 0; i < M; i++) {
            if ((msk & (1LL<<i)) == 0) continue;
            update(vertexA[i], ancestor[vertexA[i]][vertexB[i]]);
            update(vertexB[i], ancestor[vertexA[i]][vertexB[i]]);
        }
        int val = dfsCount(0,0);
        //cout << val << endl;
        ans += (1LL << (N - 1 - val)) * ((bitCount(msk) % 2 == 0) ? 1 : -1);
        //cout << msk << " a " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
