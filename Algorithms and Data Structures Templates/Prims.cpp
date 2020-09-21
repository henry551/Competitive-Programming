#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair <int,int> pii;

int n; //number of vertices
vector <pii> edges[200]; //first->destination, second->weight
bool vis[200];
int dist[200];

//Time Complexity: O(ElogV)
void prims(int a){
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[a]=0;
    q.push({0,a});
    while(!q.empty()){
        pii cur = q.top();
        vis[cur.second]=true;
        q.pop();
        for (pii e: edges[cur.second]){
            if (!vis[e.first] && dist[e.first] > e.second) {
                dist[e.first] = e.second;
                q.push({dist[e.first], e.first});
            }
        }
    }
}

void driver(){
    prims(0);
    int sum = 0;
    for (int i=0; i<n; i++){
        sum+=dist[i];
    }
}
