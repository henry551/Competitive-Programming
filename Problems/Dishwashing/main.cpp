#include <bits/stdc++.h>
using namespace std;
int N;
int dish[100005];
deque <int> d[100005];
int cop[100005];

bool wash(int k){
    for (int i=0; i<=k; i++) d[i].clear();
    for (int q=0; q<k; q++) cop[q] = dish[q];
    sort(cop, cop+k);
    int cur = 0, i = 0;
    int curL = 0, curR = 0;
    while (i < k){
        bool state = false;
        if (dish[i] == cop[cur]) {
            cur++;
            state = true;
        }
        while (!d[curL].empty() && d[curL].front() == cop[cur]){
            cur++;
            d[curL].pop_front();
            if (d[curL].empty()) curL++;
            if (curL > curR) curR = curL;
        }
        if (!state) {
            int l = curL, r = curR + 1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (d[m].front() <= dish[i]) l = m;
                else r = m;
            }
            if (d[l].empty()) d[l].push_front(dish[i]);
            else if (d[l].front() > dish[i]) d[l].push_front(dish[i]);
            else {
                l++;
                d[l].push_front(dish[i]);
                if (l > curR) curR = l;
            }
        }
        i++;
    }
    bool works = true;
    for (int j=curL; j<=curR; j++){
        if (!d[j].empty()) works = false;
    }
    return works;
}

int main() {
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &dish[i]);
    int l = 0, r = N+1;
    while (r - l > 1){
        int m = (r+l)/2;
        if (wash(m)) l = m;
        else r = m;
    }
    printf("%d\n", l);
    return 0;
}