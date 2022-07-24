#include <bits/stdc++.h>
using namespace std;
int T;
int N;
vector<int> edge[55];
int gold[55];
bool vis[55];
int dp[2][55]; //don't use extra path, use extra path

void dfs(int v){
    vis[v] = true;
    if ((v == 0 && edge[v].size() == 0) || (v != 0 && edge[v].size() == 1)){
        dp[v][0] = dp[v][1] = gold[v];
        return;
    }
    vector <int> subRes[2];
    for (int e: edge[v]){
        if (!vis[e]) {
            dfs(e);
            subRes[0].push_back(dp[e][0]);
            subRes[1].push_back(dp[e][1]);
        }
    }
    subRes[0].push_back(0);
    subRes[1].push_back(0);
    sort(subRes[0].begin(), subRes[0].end(), greater<>());
    sort(subRes[1].begin(), subRes[1].end(), greater<>());
    dp[v][0] = subRes[0][0]+gold[v];
    dp[v][1] = gold[v] + subRes[0][0] + subRes[0][1];
}

int main(){
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cin >> N;
        for (int i=0; i<N; i++) {
            edge[i].clear();
            scanf("%d", &gold[i]);
        }
        for (int i=1; i<N; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            a--; b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        memset(vis, false, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        dfs(0);
        printf("Case #%d: %d\n", tt, dp[0][1]);
    }
    return 0;
}