#include <bits/stdc++.h>
using namespace std;

const int n = 105;
const int logn = (int) (log2(n) + 5);
vector <int> edge[105];
int sub[105], cpar[105];
bool inc[105];
int sz;

//Build Time Complexity: O(nlogn)
//LCA Time Complexity: O(logn)
//Distance Time Complexity: O(logn)

void dfs1(int v, int p){
    sub[v] = 1;
    sz++;
    for (int e: edge[v]){
        if (e != p && inc[e]){
            dfs1(e, v);
            sub[v] += sub[e];
        }
    }
}

int dfs2(int v, int p){
    for (int e: edge[v]){
        if (e != p && inc[e] && sub[e] > sz/2){
            return dfs2(e, v);
        }
    }
    return v;
}

void decompose(int root, int p){
    sz = 0;
    dfs1(root, root);
    int centroid = dfs2(root, root);
    if (p == -1) p = centroid;
    cpar[centroid] = p;
    inc[centroid] = false;
    for (int e: edge[centroid]){
        if (inc[e]) decompose(e, centroid);
    }
}
// driver function
void driver() {
    memset(inc, true, sizeof(inc));
    decompose(0, -1);
}