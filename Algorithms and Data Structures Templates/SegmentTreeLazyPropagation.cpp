#include <bits/stdc++.h>
using namespace std;
int arr[105]; //stored from 0 to 100
int tree[405]; //stored from 1 to 404 (at worst)
int lazy[405]; //stored from 1 to 404 (at worst)

//Time Complexity: O(n)
void build(int node, int s, int e){
    if (s==e) tree[node]=arr[s];
    else{
        int m = (s+e)/2;
        build(2*node, s, m);
        build(2*node+1, m+1, e);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

//Time Complexity: O(logn)
void updateRange(int node, int s, int e, int l, int r, int val)
{
    if (lazy[node] != 0) {
        tree[node] += (e-s+1) * lazy[node];
        if (s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (s > e || s > r || e < l) return;
    if (s >= l && e <= r) {
        tree[node] += (e-s+1) * val;
        if (s != e) {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int m = (s + e) / 2;
    updateRange(node*2, s, m, l, r, val);
    updateRange(node*2+1, m+1, e, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

//Time Complexity: O(logn)
int queryRange(int node, int s, int e, int l, int r)
{
    if (s > e || s > r || e < l)
        return 0;
    if (lazy[node] != 0) {
        tree[node] += (e-s+1)*lazy[node];
        if (s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (s >= l && e <= r) return tree[node];
    int m = (s + e) / 2;
    int p1 = queryRange(node*2, s, m, l, r);
    int p2 = queryRange(node*2+1, m+1, e, l, r);
    return (p1 + p2);
}