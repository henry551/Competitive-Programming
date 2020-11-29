#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector <int> edge[1005];
bool vis[1005];
int dist[1005];
int previous[1005];
int best = INT_MAX;
vector <int> ans;

int bfs(int v){
    queue <int> q;
    q.push(v);
    dist[v] = 0;
    vis[v] = true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (int e: edge[node]){
            if (!vis[e]) {
                q.push(e);
                dist[e] = dist[node] + 1;
                previous[e] = node;
                vis[e] = true;
            } else if (e == v){
                if (dist[node] + 1 < best){
                    best = dist[node] + 1;
                    return node;
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
    }
    for (int i=1; i<=N; i++) {
        memset(vis, false, sizeof(vis));
        memset(dist, 0, sizeof(dist));
        memset(previous, 0, sizeof(previous));
        int p = bfs(i);
        if (p != -1){
            ans.clear();
            while (p != 0) {
                ans.push_back(p);
                p = previous[p];
            }
        }
    }
    if (best == INT_MAX) printf("-1\n");
    else {
        printf("%d\n", best);
        for (int a: ans){
            printf("%d\n", a);
        }
    }
    return 0;
}