#include <bits/stdc++.h>
using namespace std;
int N, M; //nodes, edges
vector <int> edge[105]; //edges
int indegree[105];
int cont = 0;
bool vis[105];
stack <int> order; //used in runDFS
queue <int> zero; //indegree of 0 in Kahn's

//Time Complexity: O(E+V)
void dfs(int v){
    vis[v] = true;
    for (int e: edge[v]){
        if (!vis[e]) dfs(e);
    }
    order.push(v);
}

void runDFS(){
    for (int i=0; i<N; i++){
        while (!vis[i]) dfs(i);
    }
    while (!order.empty()){
        cout << order.top() << endl;
        order.pop();
    }
}

//Time Complexity: O(E+V)
void kahn(){
    for (int i=0; i<N; i++){
        if (indegree[i] == 0) zero.push(i);
    }
    while (!zero.empty()){
        cont++;
        int q = zero.front();
        cout << q << endl;
        zero.pop();
        for (int e: edge[q]){
            indegree[e]--;
            if (indegree[e] == 0) zero.push(e);
        }
    }
    if (cont != N) {
        cout << "Topological Sort is Not Possible" << endl;
    }
}