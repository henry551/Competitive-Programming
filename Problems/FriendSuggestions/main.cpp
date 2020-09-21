//#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
using namespace std;
int N, M, K;
unordered_set <int> edge[200005];
int par[200005];
int size[200005];
int decrease[200005];

int fnd(int v){
    if (v == par[v]) return v;
    return par[v] = fnd(par[v]);
}

void unite(int a, int b){
    int x = fnd(a), y = fnd(b);
    if (x == y) return;
    if (size[x] >= size[y]){
        par[y] = x;
        size[x] += size[y];
    }
    else if (size[x] < size[y]){
        par[x] = y;
        size[y] += size[x];
    }
}

int main() {
    cin >> N >> M >> K;
    int a, b;
    for (int i=1; i<=N; i++) {
        par[i] = i;
        size[i] = 1;
    }
    for (int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        edge[a].insert(b);
        edge[b].insert(a);
        unite(a,b);
    }
    for (int i=0; i<K; i++){
        scanf("%d %d", &a, &b);
        if (!edge[a].count(b) && fnd(a) == fnd(b)){
            decrease[a]++;
            decrease[b]++;
        }
    }
    for (int i=1; i<=N; i++){
        printf("%d ", size[fnd(i)]-edge[i].size()-decrease[i]-1);
    }
    printf("\n");
    return 0;
}
