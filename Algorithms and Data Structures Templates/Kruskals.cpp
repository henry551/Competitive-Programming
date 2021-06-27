#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(ElogV)

struct Edge{
    int weight, first, second;
};

bool compare(Edge a, Edge b){
    return a.weight < b.weight;
}

int n; //number of vertices (0 to n-1)
vector <Edge> edges;
int arr[200];
int ranking[200];

void initialize(int n){
    for (int i=0; i<n; i++){
        arr[i]=i;
        ranking[i]=1;
    }
}

int findParent(int i){
    if(arr[i]==i) return arr[i];
    return arr[i]=findParent(arr[i]);
}

void unionJoin(int a, int b){
    int x = findParent(a);
    int y = findParent(b);
    if (ranking[x]<ranking[y]) arr[x]=y;
    else if (ranking[x]>ranking[y]) arr[y]=x;
    else{
        arr[x]=y;
        ranking[y]++;
    }
}

void Kruskals(){
    sort(edges.begin(), edges.end(), compare);
    initialize(n);
    int sum = 0;
    for (Edge e: edges){
        if (findParent(e.first)!=findParent(e.second)) {
            unionJoin(e.first,e.second);
            sum+=e.weight;
        }
    }
}
