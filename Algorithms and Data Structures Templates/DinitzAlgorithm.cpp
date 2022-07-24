#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

vector<int> graph[305];
struct Edge {
    int u, v, cap;
    int flow;
};
vector<Edge> E;

int N, M;
int s, t;
int dist[305];
int upTo[305];

int idd = 0;

//Time Complexity: O(V^2 * E)

bool BFS() {
    for (int i=1;i<=N;i++) dist[i] = -1;
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int xt = q.front();
        q.pop();
        for (int i=0;i<graph[xt].size();i++)
        {
            int currID = graph[xt][i];
            int xt1 = E[currID].v;
            if (dist[xt1] == -1 && E[currID].flow < E[currID].cap)
            {
                q.push(xt1);
                dist[xt1] = dist[xt] + 1;
            }
        }
    }
    return (dist[t] != -1);
}

int DFS(int xt, int minCap) {
    if (minCap == 0) return 0;
    if (xt == t) return minCap;
    while (upTo[xt] < graph[xt].size())
    {
        int currID = graph[xt][upTo[xt]];
        int xt1 = E[currID].v;
        if (dist[xt1] != dist[xt] + 1)
        {
            upTo[xt]++;
            continue;
        }
        int aug = DFS(xt1, min(minCap, E[currID].cap - E[currID].flow));
        if (aug > 0)
        {
            E[currID].flow += aug;
            if (currID&1) currID--; else currID++;
            E[currID].flow -= aug;
            return aug;
        }
        upTo[xt]++;
    }
    return 0;
}

int Dinic() {
    int flow = 0;
    while (true)
    {
        if (!BFS()) break;
        for (int i=1;i<=N;i++) upTo[i] = 0;
        while (true) {
            int currFlow = DFS(s, INF);
            if (currFlow == 0) break;
            flow += currFlow;
        }
    }
    return flow;
}

void addEdge(int u, int v, int cap = 1) {
    Edge E1, E2;
    
    E1.u = u, E1.v = v, E1.cap = cap, E1.flow = 0;
    E2.u = v, E2.v = u, E2.cap = 0, E2.flow = 0;
    
    graph[u].push_back(idd++);
    E.push_back(E1);
    graph[v].push_back(idd++);
    E.push_back(E2);
}