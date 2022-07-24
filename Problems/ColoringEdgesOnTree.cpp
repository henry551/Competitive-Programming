//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
typedef pair <int,int> pii;
vector <pii> edges[100005];
int N;
pii ordering[100005];
unordered_set <int> colorIndex[100005];
int color[100005];
unsigned long most = 0;

void dfs(int v, int p){
    int k = 1;
    for (pii e: edges[v]){
        if (e.first != p){
            for (int i=k; i<=most; i++) {
                if (!colorIndex[v].count(i)) {
                    k = i;
                    break;
                }
            }
            colorIndex[v].insert(k);
            colorIndex[e.first].insert(k);
            color[e.second] = k;
            dfs(e.first, v);
        }
    }
}

int main() {
    cin >> N;
    int a, b;
    for (int i=0; i<N-1; i++){
        scanf("%d %d", &a, &b);
        ordering[i].first = a; ordering[i].second = b;
        edges[a].push_back({b,i});
        edges[b].push_back({a,i});
    }
    for (int i=1; i<=N; i++){
        most = max(most, edges[i].size());
    }
    dfs(1, -1);
    cout << most << endl;
    for (int i=0; i<N-1; i++) cout << color[i] << endl;
    return 0;
}