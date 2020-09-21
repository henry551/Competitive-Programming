#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pii;
int N, M, K;
vector <pii> edge[50005];
ll yum[50005];
ll dist1[50005];
ll dist2[50005];
ll got[50005];
ll INF = 0x3f3f3f3f3f3f3f3f;

void spfa1(int a){
    deque <int> d;
    memset(dist1, INF, sizeof(dist1));
    dist1[a] = 0;
    d.push_back(a);
    while (!d.empty()){
        int v = d.front();
        d.pop_front();
        for (pii e: edge[v]){
            if (dist1[e.first] > dist1[v]+e.second){
                dist1[e.first] = dist1[v]+e.second;
                (!d.empty() && dist1[e.first] < dist1[d.front()]) ? d.push_front(e.first) : d.push_back(e.first);
            }
        }
    }
}

void spfa2(int a){
    deque <pii> d;
    memset(dist2, INF, sizeof(dist2));
    dist2[a] = 0;
    d.push_back({a, 0});
    while (!d.empty()){
        pii v = d.front();
        d.pop_front();
        for (pii e: edge[v.first]){
            if (yum[e.first] == yum[v.second] && dist2[e.first] > dist2[v.first] + e.second){
                dist2[e.first] = dist2[v.first] + e.second;
                d.push_back({e.first, v.second});
                got[e.first] = yum[v.second];
            }
            else if (yum[e.first] < yum[v.second] && dist2[e.first] >= dist2[v.first] + e.second){
                dist2[e.first] = dist2[v.first] + e.second;
                d.push_back({e.first, v.second});
                got[e.first] = yum[v.second];
            }
            else if (yum[e.first] > yum[v.second] && dist2[e.first] >= dist2[v.first] + e.second - yum[e.first] + yum[v.second]) {
                dist2[e.first] = dist2[v.first] + e.second - yum[e.first] + yum[v.second];
                d.push_back({e.first, e.first});
                got[e.first] = yum[e.first];
            }
        }
    }
}

int main() {
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);

    scanf("%d %d %d", &N, &M, &K);
    for (int i=0, a, b, t; i<M; i++){
        scanf("%d %d %d", &a, &b, &t);
        edge[a].push_back({b,t});
        edge[b].push_back({a,t});
    }
    memset(yum, 0, sizeof(yum));
    for (int i=0, a, b; i<K; i++){
        scanf("%d %d", &a, &b);
        yum[a] = b;
    }
    spfa1(N);
    spfa2(N);
    for (int i=1; i<N; i++){
        if (got[i] != 0 && got[i] >= dist2[i] - dist1[i]) printf("1\n");
        else printf("0\n");
    }
//    for (int i=1; i<=N; i++){
//        cout << dist1[i] << " " << dist2[i] << " " << got[i] << endl;
//    }
    return 0;
}