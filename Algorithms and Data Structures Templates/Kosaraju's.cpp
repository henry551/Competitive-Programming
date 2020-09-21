#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N, M;
vector <int> edge[105];
vector <int> back[105];
bool vis[105];
stack <int> order;

void dfs(int v){
    vis[v] = true;
    for (int e: edge[v]){
        if (!vis[e]) dfs(e);
    }
    order.push(v);
}

void dfsComponents(int v){
    vis[v] = true;
    cout << v << " ";
    for (int e: back[v]){
        if (!vis[e]) dfsComponents(e);
    }
}

//Time Complexity: O(E+V)
void kosaraju(){
    for (int i=0; i<N; i++){
        if (!vis[i]) dfs(i);
    }
    memset(vis, false, sizeof(vis));
    while (!order.empty()){
        int v = order.top();
        order.pop();
        if (!vis[v]) {
            dfsComponents(v);
            cout << endl;
        }
    }
}