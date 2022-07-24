//#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
typedef pair <int,int> pii;
typedef long long ll;
ll T, N, K;
ll c[100005];
ll d[100005];
ll tc[400005];
ll td[400005];

void initializec(int node, int s, int e){
    if (s == e) {
        tc[node] = c[s];
    }
    else {
        int m = (s + e) / 2;
        initializec(2 * node, s, m); initializec(2 * node + 1, m + 1, e);
        tc[node] = max(tc[2*node], tc[2*node+1]);
    }
}

int queryc(int node, int s, int e, int l, int r){
    if (l > e || r < s) return -1;
    if (l <= s && e <= r) return tc[node];
    int m = (s+e)/2;
    return max(queryc(2*node, s, m, l, r), queryc(2*node+1, m+1, e, l, r));
}

void initialized(int node, int s, int e){
    if (s == e) {
        td[node] = d[s];
    }
    else {
        int m = (s + e) / 2;
        initialized(2 * node, s, m); initialized(2 * node + 1, m + 1, e);
        td[node] = max(td[2*node], td[2*node+1]);
    }
}

int queryd(int node, int s, int e, int l, int r){
    if (l > e || r < s) return -1;
    if (l <= s && e <= r) return td[node];
    int m = (s+e)/2;
    return max(queryd(2*node, s, m, l, r), queryd(2*node+1, m+1, e, l, r));
}

void binary1(int key, int idx, ll &left, ll &right){
    int l = 1, r = idx+1, m;
    while (l < r){
        m = (l+r)/2;
        if (queryc(1, 1, N, m, idx-1) >= key || queryd(1, 1, N, m, idx) > key+K) l = m+1;
        else r = m;
    }
    left = l;

    l = idx, r = N+1;
    while (l < r){
        m = (l+r)/2;
        if (queryc(1, 1, N, idx, m) == key && queryd(1, 1, N, idx, m) <= key+K) l = m+1;
        else r = m;
    }
    right = l-1;
}

void binary2(int key, int idx, ll &left, ll &right){
    int l = 1, r = idx+1, m;
    while (l < r){
        m = (l+r)/2;
        if (queryc(1, 1, N, m, idx-1) >= key || queryd(1, 1, N, m, idx) >= key-K) l = m+1;
        else r = m;
    }
    left = l;

    l = idx, r = N+1;
    while (l < r){
        m = (l+r)/2;
        if (queryc(1, 1, N, idx, m) == key && queryd(1, 1, N, idx, m) < key-K) l = m+1;
        else r = m;
    }
    right = l-1;
}

int main() {
    cin >> T;
    for (int qq = 1; qq <= T; qq++){
        cin >> N >> K;
        for (int i=1; i<=N; i++) {
            scanf("%lld", &c[i]);
        }
        for (int i=1; i<=N; i++){
            scanf("%lld", &d[i]);
        }
        initializec(1, 1, N);
        initialized(1, 1, N);

        ll tot = 0;
        for (ll i=1; i<=N; i++){
            ll left1 = 0, right1 = 0, left2 = 0, right2 = 0;
            binary1(c[i], i, left1, right1);
            binary2(c[i], i, left2, right2);
            //cout << left1 << " " << right1 << " " << left2 << " " << right2 << endl;
            if (left1 <= right1){
                tot += (i-left1+1LL)*(right1-i+1LL) - max(0LL,(i-left2+1LL)*(right2-i+1LL));
            }
            //cout << tot << endl;
        }
        printf("Case #%d: %lld\n", qq, tot);
    }
    return 0;
}
