#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 0x3F3F3F3F;

const int ROOT = 1;
int N, Q;
vector<pii> adj[105];
int par[105], depth[105], sz[105], top[105], segPos[105]; // node info
int weight[105], deeper[105]; // edge info
int base[105], tree[3 * 105]; // segtree info
int edgeCnt = 1;

void dfs(int u, int prev) {
    par[u] = prev;
    sz[u] = 1;

    for (pii e : adj[u]) {
        int v = e.first;
        int i = e.second;
        if (v != prev) {
            depth[v] = depth[u] + 1;
            deeper[i] = v;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }

}

void hld(int u, int e, int prev) {
    top[u] = prev;
    segPos[u] = edgeCnt;
    base[edgeCnt] = weight[e];
    edgeCnt++;

    int heavyC = -1, heavyE = -1;
    for (pii e : adj[u]) {
        int v = e.first;
        int i = e.second;
        if (v != par[u]) {
            if (heavyC == -1 || sz[v] > sz[heavyC]) {
                heavyC = v;
                heavyE = i;
            }
        }
    }

    if (heavyC != -1) hld(heavyC, heavyE, top[u]);

    for (pii e : adj[u]) {
        int v = e.first;
        int i = e.second;
        if (v != par[u] && v != heavyC) {
            hld(v, i, v);
        }
    }
}

void build(int node, int s, int e) {
    if (s==e) tree[node]=base[s];
    else{
        int m = (s+e)/2;
        build(2*node, s, m);
        build(2*node+1, m+1, e);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

void updateSeg(int node, int s, int e, int idx, int val) {
    if (s==e) tree[node]=val;
    else {
        int m = (s+e)/2;
        if (s <= idx && idx <= m) updateSeg(2*node, s, m, idx, val);
        else updateSeg(2*node+1, m+1, e, idx, val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int querySeg(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return 0;
    else if (l <= s && e <= r) return tree[node];
    else {
        int m = (s+e)/2;
        return querySeg(2*node, s, m, l, r) + querySeg(2*node+1, m+1, e, l, r);
    }
}

void update(int e, int x) {
    updateSeg(1, 1, N, segPos[deeper[e]], x);
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]]) {
            swap(u, v);
        }
        u = par[top[u]];
    }
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    return v;
}

int crawl(int u, int v) {
    int ans = -INF;
    while (1) {
        if (top[u] == top[v]) {
            ans = max(ans, querySeg(1, 1, N, segPos[v] + 1, segPos[u]));
            break;
        } else {
            ans = max(ans, querySeg(1, 1, N, segPos[top[u]], segPos[u]));
            u = par[top[u]];
        }
    }
    return ans;
}

int query(int u, int v) {
    int a = lca(u, v);
    return max(crawl(u, a), crawl(v, a));
}

void driver() {
    depth[ROOT] = 0;
    dfs(ROOT, ROOT);
    fill(top, top + N + 1, -1);
    hld(ROOT, 0, ROOT);
    build(1, 1, N);
}