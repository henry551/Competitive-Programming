#include <bits/stdc++.h>
using namespace std;
int N, M;
vector <int> edge[200005];
int cont = 0;
bool vis[200005];

void dfs(int v, int p){
    vis[v] = true;
    for (int e: edge[v]){
        if (e == p) continue;
        if (vis[e]) cont++;
        else {
            dfs(e, v);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0, a, b; i<M; i++){
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i=1; i<=N; i++){
        if (!vis[i]) dfs(i, -1);
    }
    if (cont > 2) printf("NO\n");
    else printf("YES\n");
    return 0;
}