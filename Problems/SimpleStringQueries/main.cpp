//#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
using namespace std;
int N, Q;
string S;
int character[500005];
int tree[2000005];

void build(int node, int s, int e){
    if (s == e) tree[node] = (1<<character[s]);
    else {
        int m = (s+e)/2;
        build(2*node, s, m);
        build(2*node+1, m+1, e);
        tree[node] = tree[2*node] | tree[2*node+1];
    }
}

void update(int node, int s, int e, int idx, int val){
    if (s == e) {
        tree[node] = (1<<val);
    }
    else {
        int m = (s+e)/2;
        if (s <= idx && idx <= m) update(2*node, s, m, idx, val);
        else update(2*node+1, m+1, e, idx, val);
        tree[node] = tree[2*node] | tree[2*node+1];
    }
}

int query(int node, int s, int e, int l, int r){
    if (s > r || e < l) return 0;
    if (l <= s && e <= r) return tree[node];
    else {
        int m = (s+e)/2;
        return query(2*node, s, m, l, r) | query(2*node+1, m+1, e, l, r);
    }
}

int main() {
    cin >> N >> S >> Q;
    for (int i=1; i<=N; i++){
        character[i] = S[i-1]-'a';
    }
    build(1, 1, N);
    int a, b;
    for (int i=1; i<=Q; i++){
        scanf("%d %d", &a, &b);
        if (a == 1){
            char c;
            scanf(" %c", &c);
            update(1, 1, N, b, c-'a');
        }
        else {
            int c;
            scanf("%d", &c);
            int ans = query(1, 1, N, b, c);
            printf("%d\n", __builtin_popcount(ans));
        }
    }
    return 0;
}
