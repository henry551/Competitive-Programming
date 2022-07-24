#include <bits/stdc++.h>
using namespace std;

int n;
int arr[105]; //stored from 0 to 100
int tree[405]; //stored from 1 to 404 (at worst)

//Time Complexity: O(n)
void build(int node = 1, int s = 0, int e = n-1){
    if (s==e) tree[node]=arr[s];
    else{
        int m = (s+e)/2;
        build(2*node, s, m);
        build(2*node+1, m+1, e);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

//Time Complexity: O(logn)
void update(int idx, int val, int node = 1, int s = 0, int e = n-1){
    if (s==e){
        arr[idx]+=val;
        tree[node]+=val;
    }
    else{
        int m = (s+e)/2;
        if (s<=idx && idx<=m) update(idx, val, 2*node, s, m);
        else update(idx, val, 2*node+1, m+1, e);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

//Time Complexity: O(logn)
int query(int l, int r, int node = 1, int s = 0, int e = n-1){
    if (s > r || e < l) return 0;
    else if (l<=s && e<=r) return tree[node];
    else{
        int m = (s+e)/2;
        return query(l, r, 2*node, s, m)+query(l, r, 2*node+1, m+1, e);
    }
}