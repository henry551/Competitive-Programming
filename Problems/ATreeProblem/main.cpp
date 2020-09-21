#include <bits/stdc++.h>
using namespace std;
struct tri{
    int first, second;
    bool third;
    tri (int a, int b, bool c){
        first = a; second = b; third = c;
    }
};
int N;
vector <tri> edge[50005];
bool works[50005];
unordered_map <int, int> col;
unordered_set <int> ret[50005];

bool dfs(int v, int p, bool state){
    bool back = false; //false means it is good
    bool cond = false;
    for (tri e: edge[v]){
        if (e.first==p){
            if (e.third == true) back = true;
        } else {
            cond = cond | dfs(e.first, v, state | e.third);
        }
    }
    back = back | cond;
    if (back && p!=-1) ret[p].insert(v);
    works[v] = cond | state;
    return back;
}

void dfs2(int v, int p, bool state){
    if (state){
        works[v]=true;
        for (tri e: edge[v]){
            if (e.first!=p) dfs2(e.first, v, state);
        }
        return;
    }
    if (ret[v].empty()){
        return;
    }
    if (ret[v].size()==1){
        int a;
        for (auto it: ret[v]) a = it;
        for (tri e: edge[v]){
            if (e.first!=p) dfs2(e.first, v, e.first != a);
        }
        return;
    }
    for (tri e: edge[v]){
        if (e.first!=p) dfs2(e.first, v, true);
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N-1; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(tri(b,c,false));
        edge[b].push_back(tri(a,c,false));
    }
    memset(works, false, sizeof(works));
    for (int i=0; i<N; i++){
        col.clear();
        for (tri e: edge[i]) col[e.second]++;
        for (int j=0; j<edge[i].size(); j++) {
            if (col[edge[i][j].second] > 1) {
                edge[i][j].third = true;
            }
        }
    }
    dfs(1, -1, false);
    dfs2(1, -1, false);
    int tot = 0;
    for (int i=1; i<=N; i++) if (!works[i]) tot++;
    printf("%d\n", tot);
    for (int i=1; i<=N; i++) if (!works[i]) printf("%d\n", i);
    return 0;
}