#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int N, M, L, Q;
vector <pii> edge[305];
int dist[305][305];
int INF = 0x3f3f3f3f;

void FloydWarshall() {
    memset(dist, INF, sizeof(dist));
    for (int i = 1; i <= N; i++) dist[i][i] = 0;
    for (int i = 1; i <= N; i++)
        for (pii v: edge[i])
            dist[i][v.first] = v.second;
    for (int k = 1; k <= N; k++) { //choose intermediate vertex between i and j
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j] && dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &L);
    for (int i=0; i<M; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    FloydWarshall();
    for (int i=1; i<=N; i++){
        edge[i].clear();
        for (int j=1; j<=N; j++){
            if (dist[i][j] <= L) edge[i].push_back({j, 1});
        }
    }
    FloydWarshall();
    scanf("%d", &Q);
    for (int i=0; i<Q; i++){
        int s, t;
        scanf("%d %d", &s, &t);
        if (s == t) printf("1\n");
        else {
            if (dist[s][t] != INF) printf("%d\n", dist[s][t]-1);
            else printf("-1\n");
        }
    }
    return 0;
}