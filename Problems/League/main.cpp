#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int N;
unordered_map <int, vector <pii>> edges;
unordered_map <int, int> vis;
unordered_map <int, int> indegree;
unordered_set <int> roots;
unordered_map <int, int> depth;
int INF = 0x3f3f3f3f;
int base = 1005;

int convertTo(pii a){ return a.first*base + a.second; }
pii convertFrom(int a){ return {a/base, a%base}; }

int dfs(pii v){
    int node = convertTo(v);
    vis[node] = 1;
    for (pii e: edges[node]){
        if (!vis[convertTo(e)]) depth[node] = max(depth[node], dfs(e)+1);
        else if (vis[convertTo(e)] == 2)
            depth[node] = max(depth[node], depth[convertTo(e)]+1);
        else depth[node] = INF;
    }
    vis[node] = 2;
    return depth[node];
}

int main() {
    cin >> N;
    int prev, cur;
    for (int i=1; i<=N; i++){
        scanf("%d", &prev);
        for (int j=3; j<=N; j++){
            scanf("%d", &cur);
            edges[convertTo({min(i, prev), max(i, prev)})].push_back({min(i, cur), max(i, cur)});
            indegree[convertTo({min(i, cur), max(i, cur)})]++;
            prev = cur;
        }
    }
    for (int i=1; i<=N; i++){
        for (int j=i+1; j<=N; j++){
            vis[convertTo({i,j})] = false;
        }
    }
    for (int i=1; i<=N; i++){
        for (int j=i+1; j<=N; j++){
            if (indegree[convertTo({i,j})] == 0) roots.insert(convertTo({i,j}));
        }
    }
    if (roots.empty()) {
        printf("-1\n");
    } else {
        int ans = 0;
        for (auto it: roots){
            ans = max(ans, dfs(convertFrom(it)));
        }
        if (ans >= INF) printf("-1\n");
        else printf("%d\n", ans+1);
    }
    return 0;
}