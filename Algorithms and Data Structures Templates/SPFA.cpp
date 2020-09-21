#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef pair<int, int> pii; //first->loc, second->weight
int n, m; //vertices, edges
vector<pii> edge[105];
bool inc[105];
int dist[105];
int vis[105]; //if vis[i]=V (for any i), then there is a negative edge
deque<int> d;

//Average Time Complexity: O(E)
//Worst Time Complexity: O(VE)
void spfa(int v) {
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[v] = 0;
    inc[v] = true;
    d.push_back(v);
    while (!d.empty()) {
        int temp = d.front();
        inc[temp] = false;
        vis[temp]++;
        d.pop_front();
        if (vis[temp] < n) {
            for (pii e: edge[temp]) {
                if (dist[temp] + e.second < dist[e.first]) {
                    dist[e.first] = e.second + dist[temp];
                    if (!inc[e.first]) {
                        inc[e.first] = true;
                        (!d.empty() && dist[e.first] < dist[d.front()]) ? d.push_front(e.first) : d.push_back(e.first);
                    }
                }
            }
        }
    }
}