#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int T, N, K;
int splits[35];
vector <pii> sz;

int singleSize(pii a){
    if (a.second == 1){
        return a.first;
    } else {
        return (a.first+1)/2;
    }
}

bool cmp1(pii a, pii b){
    return singleSize(a) > singleSize(b);
}

bool cmp2(pii a, pii b){
    return a.first > b.first;
}

int main(){
    cin >> T;
    for (int tt = 1; tt <= T; tt++){
        int ans = 0;
        scanf("%d %d", &N, &K);
        memset(splits, 0, sizeof(splits));
        for (int i=0; i<N; i++){
            scanf("%d", &splits[i]);
        }
        sort(splits, splits+N);
        sz.clear();
        if (splits[0] != 1) {
            sz.push_back({splits[0]-1, 1});
        }
        if (splits[N-1] != K) {
            sz.push_back({K-splits[N-1], 1});
        }
        for (int i=1; i<N; i++){
            if (splits[i]-splits[i-1]-1 > 0) {
                sz.push_back({splits[i]-splits[i-1]-1,0});
            }
        }
        if (sz.size() == 1) {
            ans = sz[0].first;
        } else if (sz.size() > 1) {
            sort(sz.begin(), sz.end(), cmp1);
            ans = singleSize(sz[0]) + singleSize(sz[1]);
            sort(sz.begin(), sz.end(), cmp2);
            ans = max(ans, sz[0].first);
        }
        printf("Case #%d: %lf\n", tt, 1.0*ans/K);
    }
    return 0;
}