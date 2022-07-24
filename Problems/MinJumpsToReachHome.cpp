#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int a, b, x;
int forbidden_place[22005];
int dist[22005];
vector <int> forbidden;
vector <int> edges[22005];
int vis[22005];
int INF = 0x3f3f3f3f;

int dijkstra(){
    memset(dist, INF, sizeof(dist));
    priority_queue <pii, vector<pii>, greater<pii>> q;
    q.push({0,0});
    dist[0] = 0;
    while (!q.empty()){
        pii v = q.top();
        q.pop();
        for (int w: edges[v.second]){
            if (dist[v.second] + 1 < dist[w]){
                dist[w] = dist[v.second]+1;
                q.push({dist[w], w});
            }
        }
    }
    int ans = min(dist[x], dist[x+11000]);
    if (ans == INF) ans = -1;
    return ans;
}

int BFS(){
    memset(dist, INF, sizeof(dist));
    queue <int> q;
    q.push(0);
    dist[0] = 0;
    vis[0] = true;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int w: edges[v]){
            if (!vis[w]) {
                vis[w] = true;
                dist[w] = dist[v]+1;
                q.push(w);
            }
        }
    }

    int ans = min(dist[x], dist[x+11000]);
    if (ans == INF) ans = -1;
    return ans;
}

int solve(){
    for (int i: forbidden){
        forbidden_place[i] = 1;
    }
    for (int i=0; i<=8000; i++){
        if (forbidden_place[i]) continue;
        if (!forbidden_place[i+a]) {
            edges[i].push_back(i+a);
            edges[i+11000].push_back(i+a);
        }
        if (i-b >= 0 && !forbidden_place[i-b]) {
            edges[i].push_back(i-b+11000);
        }
    }
    return BFS();
}

int main(){
    cin >> a >> b >> x;
    int num_forbidden;
    cin >> num_forbidden;
    for (int i=0; i<num_forbidden; i++){
        int temp;
        cin >> temp;
        forbidden.push_back(temp);
    }
    cout << solve() << endl;
    return 0;
}