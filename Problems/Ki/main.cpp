//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int N, Q;
vector <int> edge[200005];
ll inc[200005];

void dfs(int v, int p){
    for (int e: edge[v]){
        if (e != p){
            inc[e] += inc[v];
            dfs(e, v);
        }
    }
}

int main() {
    cin >> N >> Q;
    int a, b;
    for (int i=1; i<=N-1; i++){
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i=0; i<Q; i++){
        scanf("%d %d", &a, &b);
        inc[a] += b;
    }
    dfs(1, -1);
    for (int i=1; i<=N; i++){
        printf("%lld ", inc[i]);
    } cout << endl;
    return 0;
}