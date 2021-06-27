#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
int n, m; //vertices, edges
vector<pii> edge[205]; //first->destination, second->weight
int dist[205][205];
int ans[205][205]; //final distances between points
//ans[i][j]==INF -> no path
//ans[i][j]==-1 -> negative cycle in path

//Time Complexity: O(n^3)
void FloydWarshall() {
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int i = 0; i < n; i++)
        for (pii v: edge[i])
            dist[i][v.first] = v.second;
    for (int k = 0; k < n; k++) { //choose intermediate vertex between i and j
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j] && dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool negPath = false;
            for (int k = 0; k < n; k++) {
                //if dist[k][k] < 0 -> k is part of a negative cycle
                if (dist[k][k] < 0 && dist[i][k] < INF && dist[k][j] < INF) negPath = true;
            }
            negPath ? ans[i][j]=-1 : ans[i][j] = dist[i][j];
        }
    }
}