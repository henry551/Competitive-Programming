//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef pair <int,int> pii;
int N, M, P;
vector <pii> edges[2505];
vector <int> edgeBack[2505];
int dist1[2505];
bool toN[2505];
int INF = 0x3f3f3f3f;

void bellmanFord(int v){
    memset(dist1, INF, sizeof(dist1));
    dist1[v] = 0;
    for (int i=0; i<N-1; i++){
        for (int idx=1; idx<=N; idx++){
            for (pii e: edges[idx]){
                if (dist1[idx] != INF && dist1[e.first] > dist1[idx] + e.second){
                    dist1[e.first] = dist1[idx] + e.second;
                }
            }
        }
    }
}

void dfs(int v){
    toN[v] = true;
    for (int e: edgeBack[v]){
        if (!toN[e]) dfs(e);
    }
}

int main() {
    cin >> N >> M >> P;
    int a, b, c;
    for (int i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c);
        edges[a].push_back({b,-c+P});
        edgeBack[b].push_back(a);
    }
    bellmanFord(1);
    dfs(N);
    bool neg = false;
    for (int i=1; i<=N; i++){
        for (pii e: edges[i]){
            if (dist1[i] != INF && dist1[e.first] > dist1[i]+e.second && toN[i]) neg = true;
        }
    }
    if (neg) cout << "-1" << endl;
    else cout << max(0, -dist1[N]) << endl;
    return 0;
}