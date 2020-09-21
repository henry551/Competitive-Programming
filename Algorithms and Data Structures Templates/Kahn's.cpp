#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N; //N vertices, M edges
vector <int> edge[105];
int indeg[105];

//Topological sort algorithm
//Time Complexity: O(N+M)
void Kahn(){
    queue <int> q;
    for (int i=0; i<N; i++){
        for (int e: edge[i]){
            indeg[e]++;
        }
    }
    for (int i=0; i<N; i++){
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int e: edge[v]){
            if (--indeg[e] == 0) q.push(e);
        }
    }
}
