#include <bits/stdc++.h>
using namespace std;
int N, M;
vector <int> edges[180000];
double expectedValue[605];
double newValue[605];
bool vis[605];

double calculate1(int v){
    if (vis[v]) return expectedValue[v];
    vis[v] = true;
    double ans = 0;
    double out = edges[v].size();
    for (int e: edges[v]){
        ans += 1 / out * calculate1(e);
    }
    if (out > 0) ans++;
    return expectedValue[v] = ans;
}

double calculate2(int v){
    if (vis[v]) return newValue[v];
    vis[v] = true;
    double ans = 0;
    double out = edges[v].size();
    for (int e: edges[v]){
        ans += 1 / out * calculate2(e);
    }
    if (out > 0) ans++;
    return newValue[v] = ans;
}

int main() {
    cin >> N >> M;
    int s, t;
    for (int i=1; i<=M; i++){
        scanf("%d %d", &s, &t);
        edges[s].push_back(t);
    }
    memset(vis, false, sizeof(vis));
    double ans = calculate1(1);

    for (int i=1; i<N; i++){
        int largestIdx = 0, node;
        if (edges[i].size() > 1){
            for (int j=0; j<edges[i].size(); j++){
                if (expectedValue[edges[i][j]] > expectedValue[edges[i][largestIdx]]){
                    largestIdx = j;
                }
            }
            node = edges[i][largestIdx];
            edges[i].erase(edges[i].begin()+largestIdx);
            memset(vis, false, sizeof(vis));
            ans = min(ans, calculate2(1));
            edges[i].push_back(node);
        }
    }
    printf("%.6lf\n", ans);
    return 0;
}