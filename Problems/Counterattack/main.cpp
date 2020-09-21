#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int n, m;
vector <pii> edge[5005];
int dist1[5005];
int dist2[5005];
bool inc1[5005];
bool inc2[5005];
int INF = 0x3f3f3f3f;

void spfa(int v){
    memset(dist1, INF, sizeof(dist1));
    memset(dist2, INF, sizeof(dist2));
    dist1[v]=0;
    queue <int> q;
    q.push(v);
    inc1[v]=true;
    inc2[v]=true;
    while (!q.empty()){
        int temp = q.front();
        q.pop();
        for (pii e: edge[temp]){
            if (inc1[temp]) {
                if (dist1[e.first] > dist1[temp] + e.second) {
                    dist2[e.first] = dist1[e.first];
                    dist1[e.first] = dist1[temp] + e.second;
                    if (!inc1[e.first] && !inc2[e.first]) {
                        q.push(e.first);
                    }
                    inc1[e.first] = true;
                    inc2[e.first] = true;
                } else if (dist2[e.first] > dist1[temp] + e.second) {
                    dist2[e.first] = dist1[temp] + e.second;
                    if (!inc1[e.first] && !inc2[e.first]) {
                        q.push(e.first);
                    }
                    inc2[e.first] = true;
                }
            }
            if (inc2[temp]){
                if (dist2[e.first] > dist2[temp] + e.second){
                    dist2[e.first] = dist2[temp] + e.second;
                    if (!inc1[e.first] && !inc2[e.first]) {
                        q.push(e.first);
                    }
                    inc2[e.first] = true;
                }
            }
        }
        inc1[temp]=false;
        inc2[temp]=false;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0, a, b, c; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    spfa(1);
    printf("%d\n", dist2[n]);
    return 0;
}