#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> edge[205]; //first->destination, second->weight
int dist[205];
int par[205];
int n, m; //vertices, edges
const int INF = 0x3f3f3f3f;
int good = true; //if good is false, then there is a negative cycle

//Time Complexity: O(EV)
void bellmanFord(int v) {
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[v] = 0; //initial node
    for (int k = 0; k < n - 1; k++) {
        for (int i = 0; i < n; i++) {
            for (pii e: edge[i]) {
                if (dist[i] != INF && dist[e.first] > dist[i] + e.second) {
                    dist[e.first] = dist[i] + e.second;
                    par[e.first] = i;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (pii e: edge[i]) {
            if (dist[e.first] > dist[i] + e.second) {
                good = false;
            }
        }
    }
}