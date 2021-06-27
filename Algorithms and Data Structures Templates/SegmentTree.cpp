#include <bits/stdc++.h>
using namespace std;

int arr[105]; //stored from 0 to 100
int tree[405]; //stored from 1 to 404 (at worst)

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
void update(int node, int s, int e, int idx, int val){
    if (s==e){
        arr[idx]+=val;
        tree[node]+=val;
    }
    else{
        int m = (s+e)/2;
        if (s<=idx && idx<=m) update(2*node, s, m, idx, val);
        else update(2*node+1, m+1, e, idx, val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

//Time Complexity: O(logn)
int query(int node, int s, int e, int l, int r){
    if (s > r || e < l) return 0;
    else if (l<=s && e<=r) return tree[node];
    else{
        int m = (s+e)/2;
        return query(2*node, s, m, l, r)+query(2*node+1, m+1, e, l, r);
    }
}