//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
typedef pair <int,int> pii;
int N, M;
string S;
int dp[100005];
int nxt[100005];
pii tree[400005];
int INF = 0x3f3f3f3f;

void update(int node, int s, int e, int idx, int val){
    if (s == e){
        tree[node].first = val;
        tree[node].second = idx;
    } else {
        int m = (s+e)/2;
        if (s <= idx && idx <= m) update(node<<1, s, m, idx, val);
        else update(node<<1|1, m+1, e, idx, val);
        if (tree[node<<1].first <= tree[node<<1|1].first){
            tree[node] = tree[node<<1];
        } else {
            tree[node] = tree[node<<1|1];
        }
    }
}

pii query(int node, int s, int e, int l, int r){
    if (r < s || l > e) return {INF,INF};
    else if (l <= s && e <= r) return tree[node];
    else {
        int m = (s+e)/2;
        pii p = query(node<<1, s, m, l, r);
        pii q = query(node<<1|1, m+1, e, l, r);
        if (p.first <= q.first){
            return p;
        } else {
            return q;
        }
    }
}

int main() {
    cin >> N >> M >> S;
    bool works = true;
    int cont = 0;
    for (int i=0; i<=N; i++){
        if (S[i] == '1'){
            cont++;
        } else {
            cont = 0;
        }
        if (cont >= M) works = false;
    }
    if (S[0] == '1' || S[N] == '1') works = false;
    if (!works) {
        cout << "-1\n" << endl;
        return 0;
    }
    memset(dp, INF, sizeof(dp));
    memset(nxt, INF, sizeof(nxt));
    fill(tree, tree+4*N, make_pair(INF,INF));
    dp[N] = 0;
    update(1, 0, N, N, dp[N]);
    for (int i=N-1; i>=0; i--){
        if (S[i] == '0') {
            pii result = query(1, 0, N, i+1, min(i+M, N));
            dp[i] = 1+result.first;
            nxt[i] = result.second;
            update(1, 0, N, i, dp[i]);
        }
    }
    int idx = 0;
    while (idx != N){
        if (nxt[idx] <= idx) {
            cout << "FALSE" << endl;
            return 0;
        }
        printf("%d ", nxt[idx]-idx);
        idx = nxt[idx];
    } cout << endl;
    return 0;
}