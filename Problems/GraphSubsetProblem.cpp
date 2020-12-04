#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;

int t;
int n = 0, m, k;
vector <int> edge[100005];
set <pii> num_edge;
int deg[100005];
int id[100005];
bool can_reach[100005];
vector <pii> req[100005];
int vertex_list[100005];
bool ans[100005];
int seq[100005];
vector <int> vertices;

bool cmp(int a, int b){
    return id[a] < id[b];
}

void solve(){
        if (k >= 500){
            printf("-1\n");
            return;
        }
        for (int i=1; i<=n; i++){
            deg[i] = edge[i].size();
            num_edge.insert({deg[i], i});
        }
        int cur = 1;
        while (!num_edge.empty()){
            auto v = *num_edge.begin();
            if (v.first >= k){
                printf("1 %d\n", num_edge.size());
                for (auto it: num_edge){
                    printf("%d ", it.second);
                }
                printf("\n");
                return;
            } else {
                num_edge.erase(v);
                id[v.second] = cur++;
                for (auto e: edge[v.second]){
                    if (!id[e]){
                        num_edge.erase({deg[e], e});
                        num_edge.insert({--deg[e], e});
                    }
                }
                vertices.push_back(v.second);
            }
        }
        for (int i=1; i<=n; i++){
            vertex_list[i] = i;
        }
        sort(vertex_list+1, vertex_list+n+1, cmp);

        for (int it=1; it<=n; it++){
            int i = vertex_list[it];
            int num = 0;
            for (auto e: edge[i]){
                if (id[i] < id[e]){
                    seq[num] = e;
                    num++;
                    can_reach[e] = true;
                }
            }
            for (pii v: req[i]){
                if (!can_reach[v.first]) ans[v.second] = false;
            }
            for (int j=0; j<num; j++) can_reach[seq[j]] = false;
            if (num != k-1) continue;
            ans[i] = true;
            sort(seq, seq+num, cmp);
            for (int a=0; a<num; a++){
                for (int b=a+1; b<num; b++){
                    req[seq[a]].push_back({seq[b], i});
                }
            }
        }
        for (int i=1; i<=n; i++){
            if (ans[i]){
                printf("2\n");
                printf("%d ", i);
                for (auto e: edge[i]){
                    if (id[i] < id[e]){
                        printf("%d ", e);
                    }
                }
                printf("\n");
                return;
            }
        }
        printf("-1\n");
}

int main(){
    cin >> t;
    while (t--){
        for (int i=0; i<=n; i++) {
            edge[i].clear();
            deg[i] = 0;
            id[i] = 0;
            can_reach[i] = false;
            req[i].clear();
            ans[i] = false;
            seq[i] = 0;
            vertex_list[i] = 0;
        }
        vertices.clear();
        num_edge.clear();
        scanf("%d %d %d", &n, &m, &k);
        for (int i=0; i<m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        solve();
    }
    return 0;
}