#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair <int,int> pii;
vector <int> edges[300];
int vis[300];
int dist[300];
int weight = 1;

//Time Complexity: O(E+V)
void bfs(int a){
    queue <pii> q;
    q.push({a,0});
    dist[a]=0;
    vis[a]=true;
    while(!q.empty()){
        pii v = q.front();
        q.pop();
        for (int e: edges[v.first]){
            if (!vis[e]){
                vis[e]=true;
                dist[e]=v.second+weight;
                q.push({e, dist[e]});
            }
        }
    }
}