#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair <ll, ll> pii;
struct quad{
    ll x, b, t, val;
};
ll N, M, K, Q, T;
vector <quad> sect;
vector <quad> sect2;
map <ll, ll> conv;

pii geese[100005];
ll ans[100005];
ll tree[800005];
ll lazy[800005];
ll tot = 0;

void updateRange(ll node, ll s, ll e, ll l, ll r, ll val){
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
    ll m = (s + e) / 2;
    updateRange(node*2, s, m, l, r, val);
    updateRange(node*2+1, m+1, e, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll queryRange(ll node, ll s, ll e, ll l, ll r){
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
    ll m = (s + e) / 2;
    ll p1 = queryRange(node*2, s, m, l, r);
    ll p2 = queryRange(node*2+1, m+1, e, l, r);
    return (p1 + p2);
}

bool comp1(quad a, quad b){
    if (a.x != b.x) return a.x < b.x;
    if (abs(a.val) == 1) return true;
    return false;
}

int main() {
    scanf("%lld %lld %lld %lld %lld", &N, &M, &K, &Q, &T);
    ll a, b, c, d;
    for (int i=0; i<K; i++){
        scanf("%lld %lld", &a, &b);
        geese[i].x = a; geese[i].y = b;
        conv[b] = 0;
        sect.push_back({a, b, i, 0});
    }
    for (int i=0; i<Q; i++){
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        sect.push_back({a-T, b, d, 1});
        sect.push_back({c+T+1, b, d, -1});
        sect2.push_back({b-T, a, c, 1});
        sect2.push_back({d+T+1, a, c, -1});
        conv[b] = 0; conv[d] = 0;
    }
    int cont = 0;
    for (auto it: conv){
        conv[it.first] = cont;
        cont++;
    }
    cont--;
    sort(sect.begin(), sect.end(), comp1);
//    for (int i=0; i<sect.size(); i++){
//        cout << sect[i].x << " " << sect[i].b << " " << sect[i].t << " " << sect[i].val << endl;
//        cout << xval[sect[i].x] << " " << yval[sect[i].b] << " ";
//        if (abs(sect[i].val) == 1) cout << yval[sect[i].t];
//        cout << endl;
//    }
    for (quad e: sect){
        if (abs(e.val)) {
            updateRange(1, 0, cont, conv[e.b], conv[e.t], e.val);
        }
        else {
            ll q = queryRange(1, 0, cont, conv[e.b], conv[e.b]);
            ans[e.t] = q;
        }
    }


    conv.clear();
    for (int i=0; i<sect2.size(); i++){
        conv[sect2[i].b] = 0;
        conv[sect2[i].t] = 0;
    }
    for (int i=0; i<K; i++){
        conv[geese[i].x] = 0;
        sect2.push_back({geese[i].y, geese[i].x, i, 0});
    }
    cont = 0;
    for (auto it: conv){
        conv[it.first] = cont;
        cont++;
    }
    cont--;
    sort(sect2.begin(), sect2.end(), comp1);
    for (quad e: sect2){
        if (abs(e.val)) {
            updateRange(1, 0, cont, conv[e.b], conv[e.t], e.val);
        }
        else {
            ll q = queryRange(1, 0, cont, conv[e.b], conv[e.b]);
            ans[e.t] = max(q, ans[e.t]);
            tot += ans[e.t];
        }
    }
    printf("%lld\n", tot);
    return 0;
}