#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pii;
struct tri{
    ll sx, sy, num;
    tri (ll a, ll b, ll c){
        sx = a; sy = b; num = c;
    };
};
#define x first
#define y second
ll N;
pii points[3005];
vector <tri> slopes[3005];
ll sub = 0;
set <pii> start[3005];

bool cmp1(pii a, pii b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; }
bool cmp2(pii a, tri b) { if (a.x != b.sx) return a.x < b.sx; return a.y < b.sy; }
bool cmp3(tri a, tri b) { if (a.sx != b.sx) return a.sx < b.sx; return a.sy < b.sy; }

ll choose(ll a){
    if (a < 3) return 0;
    return a*(a-1)*(a-2)/6;
}

ll binary(ll dx, ll dy, ll idx){
    if (slopes[idx].empty()) {
        if (start[idx].count({dx,dy})==0) {
            start[idx].insert({dx,dy});
            return 2;
        }
        else return -1;
    }
    ll l = 0, r = slopes[idx].size(), m;
    while (r-l > 1){
        m = (l+r)/2;
        if (!cmp2({dx,dy}, slopes[idx][m])) l = m;
        else r = m;
    }
    if (slopes[idx][l].sx != dx || slopes[idx][l].sy != dy) {
        if (start[idx].count({dx,dy})==0) {
            start[idx].insert({dx,dy});
            return 2;
        }
        else return -1;
    }
    if (slopes[idx][l].num == -1) return -1;
    ll k = slopes[idx][l].num;
    slopes[idx][l].num = -1; //renders it invalid from now on
    sub -= choose(k);
    return k+1;
}

int main() {
    scanf("%lld", &N);
    for (int i=0; i<N; i++) scanf("%lld %lld", &points[i].x, &points[i].y);
    sort (points, points+N, cmp1);

    ll dx, dy, div;
    for (ll i=1; i<N; i++){
        for (ll j=0; j<i; j++){
            dx = points[i].x - points[j].x;
            dy = points[i].y - points[j].y;
            div = __gcd(dx, dy);
            dx/=div; dy/=div;
            if (dx < 0) {dx*=-1; dy*=-1;}
            ll q = binary(dx, dy, j);
            if (q <= -1) continue;
            sub += choose(q);
            slopes[i].push_back(tri(dx, dy, q));
        }
        sort(slopes[i].begin(), slopes[i].end(), cmp3);
    }

    printf("%lld\n", choose(N)-sub);
    return 0;
}