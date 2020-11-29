#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int logn;
int val[100005];
int N, Q;
vector <int> edge[100005];
int par[20][100005], depth[100005];
int ans[100005];

void dfs0(int u, int p) {
    for (int e: edge[u])
        if (e != p) {
            par[0][e] = u;
            depth[e] = depth[u]+1;
            ans[e] = ans[u]^val[e];
            dfs0(e, u);
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
    return ans[u]^ans[v]^val[lca(u, v)];
}

int main() {
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    scanf("%d %d", &N, &Q);
    logn = (int) (log2(N) + 5);
    for (int i=1; i<=N; i++){
        scanf("%d", &val[i]);
    }
    for (int i=1, a, b; i<N; i++){
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    preprocess();
    for (int i=0, a, b, c; i<Q; i++){
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            val[b] = c;
            preprocess();
        } else {
            printf("%d\n", dist(b, c));
        }
    }
    return 0;
}