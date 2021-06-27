#include <bits/stdc++.h>
using namespace std;

//Initialize: O(nlogn)
//Insert: O(logn)
//Delete: O(logn)
//Find Rank: O(logn)
//Find xth Smallest: O(logn)
//Output elements in order: O(n)
//Min on top

struct node {
    int v, p, sz;
    node* c[2];
    node(int x) {
        v = x;
        p = rand();
        sz = 1;
        c[0] = c[1] = 0;
    }
} *rt;

struct Treap {
    int sz(node* n) { return n ? n->sz : 0; }
    void updsz(node* n) { if (n) n->sz = sz(n->c[0]) + 1 + sz(n->c[1]); }
    void rot(node*& n, bool d) {  //d=0: right rotate   d=1: left rotate
        node* tmp = n->c[d];
        n->c[d] = tmp->c[!d];
        tmp->c[!d] = n;
        updsz(n);
        updsz(tmp);
        n = tmp;
    }
    void ins(node*& n, node* i) {
        if (!n) n = i;
        else {
            bool d = n->v < i->v;
            ins(n->c[d], i);
            if (n->c[d]->p < n->p) rot(n, d);
        }
        updsz(n);
    }
    void del(node*& n, int v) {
        if (!n) return;
        if (n->v == v) {
            if (!n->c[0] || !n->c[1]) n = n->c[0] ? n->c[0] : n->c[1];
            else {
                bool d = n->c[0]->p > n->c[1]->p;
                rot(n, d);
                del(n->c[!d], v);
            }
        } else del(n->c[n->v < v], v);
        updsz(n);
    }
    int rank(node* n, int v, int ind = 0) {
        if (!n) return -1;
        if (n->v == v) {
            int t = rank(n->c[0], v, ind);
            return t == -1 ? ind + sz(n->c[0]) + 1 : t;
        }
        else if (n->v < v) return rank(n->c[1], v, ind + sz(n->c[0]) + 1);
        else return rank(n->c[0], v, ind);
    }
    int sml(node* n, int s) {
        if (!n) return -1;
        int ls = sz(n->c[0]) + 1;
        return ls == s ? n->v : (ls < s) ? sml(n->c[1], s - ls) : sml(n->c[0], s);
    }
    void print(node* n) {
        if (!n) return;
        print(n->c[0]);
        printf("%d ", n->v);
        print(n->c[1]);
    }
} t;

int n, x; //number of elements, any specified value
int arr[500];

void BinarySearchTree() {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        t.ins(rt, new node(arr[i]));
    }
    t.del(rt, x);
    t.sml(rt, x);
    t.rank(rt, x);
    t.print(rt);
}