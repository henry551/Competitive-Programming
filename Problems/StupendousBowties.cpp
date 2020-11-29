#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
typedef long long ll;
#define x first
#define y second
int N;
pii points[100005];
ll amx[100005];
vector <int> amy[100005];

bool comp(pii a, pii b){
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
};

bool comp2(pii a, pii b){ return a.y < b.y; }

int bin(int a, int b){
    int l = 0, r = amy[b].size(), m;
    while (r - l > 1){
        m = (r+l)/2;
        amy[b][m] <= a ? l = m : r = m;
    }
    return l;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d %d", &points[i].x, &points[i].y);
    ll ans = 0;
    sort(points, points+N, comp2);
    int counter = points[0].y, cont = 0;
    for (int i=0; i<N; i++){
        if (points[i].y!=counter) {
            counter = points[i].y;
            points[i].y = ++cont;
        }
        else points[i].y = cont;
    }
    sort(points, points+N, comp);
    counter = points[0].x, cont = 0;
    for (int i=0; i<N; i++){
        if (points[i].x!=counter) {
            counter = points[i].x;
            points[i].x = ++cont;
        }
        else points[i].x = cont;
    }
    for (int i=0; i<N; i++){
        amx[points[i].x]++;
        amy[points[i].y].push_back(points[i].x);
    }

    ll num = 0;
    for (int i=0; i<N; i++){
        if (amx[points[i].x] < 3) {
            num = 0;
            continue;
        }
        num++;
        if (num > 1 && num < amx[points[i].x]){
            ll idx = bin(points[i].x, points[i].y);
            ans += 2*(num-1)*(amx[points[i].x]-num)*idx*(amy[points[i].y].size()-1-idx);

        } else if (num >= amx[points[i].x]){
            num = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}