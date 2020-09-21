#include <bits/stdc++.h>
using namespace std;
int N, M, Q;
int logn;
unordered_map<int, int> g[50005];
int par[(int) (log2(50005) + 5)][50005], depth[50005], val[50005];

void dfs0(int u, int p) {
    for (auto it = g[u].begin(); it != g[u].end(); it++)
        if (it->first != p) {
            par[0][it->first] = u;
            depth[it->first] = depth[u] + 1;
            val[it->first] = val[u]+it->second;
            dfs0(it->first, u);
        }
}

void preprocess() {
    depth[1] = 0;
    par[0][1] = 0;
    dfs0(1, -1);

    for (int i = 1; i < logn; i++)
        for (int node = 1; node <= N; node++)
            par[i][node] = par[i - 1][par[i - 1][node]];
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int d = depth[v] - depth[u];

    for (int i = 0; i < logn; i++)
        if (d & (1 << i))
            v = par[i][v];

    if (u == v) return u;

    for (int i = logn - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

int dist(int u, int v) {
    return val[u] + val[v] - 2 * val[lca(u, v)];
}

int main() {
    scanf("%d %d", &N, &M);
    logn = (int) (log2(N) + 5);
    for (int i=0; i<M; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        g[a][b]=w;
        g[b][a]=w;
    }
    preprocess();
    scanf("%d", &Q);
    for (int i=0; i<Q; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dist(a,b));
    }
    return 0;
}