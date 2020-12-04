#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector <pii> edges[300]; //edges[i].first is vertex value, edges[i].second is edge weight
int dist[300];
int INF = 0x3f3f3f3f;

//Time Complexity: O(ElogV)
void dijkstra(int a){
    priority_queue <pii, vector<pii>, greater<pii>> q; //min top priority queue
    memset(dist, INF, sizeof(dist));
    dist[a]=0;
    q.push({0,a});
    while(!q.empty()){
        pii v = q.top();
        q.pop();
        for (pii e: edges[v.second]){
            if (dist[e.first]>dist[v.second]+e.second){
                dist[e.first]=dist[v.second]+e.second;
                q.push({dist[e.first],e.first});
            }
        }
    }
}

//Time Complexity: O(V^2)
int inc[300];
int V = 300; //vertices
void dijkstra2(int a){
    memset(dist, INF, sizeof(a));
    dist[a] = 0;
    for (int i=0; i<V; i++){
        int idx, val = INF;
        for (int j=1; j<=V; j++){
            if (!inc[j] && dist[j] < val){
                val = dist[j];
                idx = j;
            }
        }
        inc[idx] = true;
        for (pii e: edges[idx]){
            dist[e.first] = min(dist[e.first], dist[idx]+e.second);
        }
    }
}

