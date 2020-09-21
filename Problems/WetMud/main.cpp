#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int N, M, J;
pii tim[100005];
set <int> dry;
set <int>::iterator it;

bool cmp(pii a, pii b){
    return a.second < b.second;
}

int main() {
    scanf("%d %d %d", &N, &M, &J);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &tim[i].first, &tim[i].second);
    }
    sort(tim, tim+M, cmp);
    int loc = 0, time = 0;
    dry.insert(0); dry.insert(N+1);
    if (N+1 <= J) {
        printf("0\n");
        return 0;
    }
    for (int i=0; i<M; i++){
        time = tim[i].second;
        while (true) {
            dry.insert(tim[i].first);
            it = dry.upper_bound(loc + J);
            it--;
            if (*it > loc) loc = *it;
            else break;
        }
        if (loc == N+1) break;
    }
    if (loc == N+1) printf("%d\n", time);
    else printf("-1\n");
    return 0;
}