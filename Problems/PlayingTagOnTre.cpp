#include <iostream>
#include <vector>
using namespace std;

int N, u, v;
vector <int> edges[100005];
int ans = 0;
int distU[100005], distV[100005];
int longestSub[100005];
int length;

void dfsU(int vertex, int p, int dist){
    distU[vertex] = dist;
    for (int e: edges[vertex]){
        if (e != p) {
            dfsU(e, vertex, dist+1);
        }
    }
}

void dfsV(int vertex, int p, int dist){
    distV[vertex] = dist;
    for (int e: edges[vertex]){
        if (e != p) {
            dfsV(e, vertex, dist+1);
        }
    }
}

void dfsSub(int vertex, int p){
    int longest = 0;
    for (int e: edges[vertex]){
        if (e != p && distU[e] + distV[e] != length){
            dfsSub(e, vertex);
            longest = max(longest, longestSub[e]+1);
        }
    }
    longestSub[vertex] = longest;
}


int main() {
    int a, b;
    cin >> N >> u >> v;
    for (int i=0; i<N-1; i++){
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    memset(longestSub, -1, sizeof(longestSub));
    dfsU(u, u, 0);
    dfsV(v, v, 0);
    length = distU[v];
    for (int i=1; i<=N; i++){
        if (distU[i] + distV[i] == length && distU[i] < distV[i]){
            dfsSub(i, i);
            ans = max(ans, distV[i]+longestSub[i]-1);
        }
    }
    cout << ans << endl;
    return 0;
}
