#include <iostream>
using namespace std;
vector <int> edges[300];
bool vis[300];

//Time Complexity: O(E+V)
void dfs(int a){
    vis[a]=true;
    for (int e: edges[a]){
        if (!vis[e]){
            dfs(e);
        }
    }
}