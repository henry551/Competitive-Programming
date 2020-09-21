#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//~~~~~~~~~~~~~~~~~~~~Binary Lifting~~~~~~~~~~~~~~~~~~~~~~
//Time Complexity
//Build: O(nlogn)
//Query: O(logn)
const int n = 105;
const int logn = (int) (log2(n)+5);

int depth[105]; int par[logn][105];
vector <int> edge[105];

void dfs(int v, int p) {
    for (int e: edge[v])
        if (e != p) {
            par[0][e] = v;
            depth[e] = depth[v] + 1;
            dfs(e, v);
        }
}

void preprocess() { //1 is one of the nodes
    depth[1] = 0;
    par[0][1] = 0;
    dfs(1, 0);

    for (int i = 1; i < logn; i++)
        for (int node = 0; node < n; node++)
            par[i][node] = par[i - 1][par[i - 1][node]];
}

int lca1(int u, int v) {
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

void driver1(){
    preprocess();
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sparse Table~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Build: O(nlogn)
//Query: O(1)
const int sz = 105;
const int logsz = (int) (log2(sz)+5);
vector <int> adj[sz];    // stores the tree
vector <int> euler;      // tracks the eulerwalk
vector <int> dep;   // depth for each node corresponding

int fir[sz];     // stores first appearance index of every node
int lev[sz];   // stores depth for all nodes in the tree
int ptr;         // pointer to euler walk
int dp[sz][logsz];  // sparse table

void build(int m) {
    for (int i=0; i<m; i++)
        dp[i][0] = i;

    for (int j=1; (1<<j)<=m; j++){
        for (int i=0; i+(1<<j)-1 < m; i++){
            dp[i][j] = dep[dp[i][j - 1]] <= dep[dp[i + (1 << (j - 1))][j - 1]] ?
                       dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
        }
    }
}

int query(int l, int r){
    int dx = (int) (log2(r-l+1));
    return dep[dp[l][dx]] > dep[dp[r-(1<<dx)+1][dx]] ? dp[r-(1<<dx)][dx] : dp[l][dx];
}

void dfs(int cur,int prev, int depth){
    if (fir[cur]==-1) fir[cur] = ptr;
    lev[cur] = depth;
    euler.push_back(cur);
    ptr++;

    for (int x: adj[cur]){
        if (x != prev){
            dfs(x,cur,depth+1);
            euler.push_back(cur);
            ptr++;
        }
    }
}

int lca2(int u,int v){
    if (u==v) return u;
    if (fir[u] > fir[v]) swap(u,v);
    return euler[query(fir[u], fir[v])];
}

void driver2(){
    ptr = 0;
    memset(fir,-1,sizeof(fir));
    dfs(1,0,0);
    for (int x : euler) dep.push_back(lev[x]);
    memset(dp,-1,sizeof(dp));
    build(dep.size());
}