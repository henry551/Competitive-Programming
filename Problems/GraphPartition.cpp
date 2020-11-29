#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> edges[205];
bool vis[205];
bool state[205];
int dist[205][205];
int INF = 0x3f3f3f3f;

bool bipartite(int v) {
    bool works = true;
    for (int e: edges[v]) {
        if (!vis[e]) {
            vis[e] = true;
            state[e] = !state[v];
            works = bipartite(e) && works;
        } else {
            if (state[v] == state[e]) works = false;
        }
    }
    return works;
}

int main() {
    cin >> N;
    string a;
    for (int i = 1; i <= N; i++) {
        cin >> a;
        for (int j = 0; j < N; j++) {
            if (a[j] - '0' == 1) edges[i].push_back(j + 1);
        }
    }
    state[1] = true;
    vis[1] = true;
    if (bipartite(1)) {
        memset(dist, INF, sizeof(dist));
        for (int i = 1; i <= N; i++) {
            dist[i][i] = 0;
            for (int e: edges[i]) dist[i][e] = 1;
        }
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                ans = max(ans, dist[i][j]);
            }
        }
        printf("%d\n", ans+1);
    } else {
        printf("-1\n");
    }
    return 0;
}