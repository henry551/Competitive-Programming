#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
struct tri {
    int first, second, third;
};
#define l first
#define r second
int block, N, Q;
int arr[100005];
int amount[100005];
tri que[100005];
pii ans[100005];

bool comp(tri a, tri b){
    if (a.first/block != b.first/block) return a.first/block < b.first/block;
    return a.second < b.second;
}

int main() {
    scanf("%d", &N);
    block = (int) sqrt(N);
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);
    scanf("%d", &Q);
    for (int i=0; i<Q; i++) {
        scanf("%d %d", &que[i].l, &que[i].r);
        que[i].l--; que[i].r--;
        que[i].third = i;
    }
    sort(que, que+Q, comp);

    int L = 0, R = -1, tot = 0;
    for (int i=0; i<Q; i++){
        while (L < que[i].l) {
            amount[arr[L]]--;
            if (amount[arr[L]]%2==1 && amount[arr[L]]>0) tot--;
            else if (amount[arr[L]]%2==0 && amount[arr[L]]>0) tot++;
            L++;
        }
        while (L > que[i].l){
            L--;
            amount[arr[L]]++;
            if (amount[arr[L]]%2==1 && amount[arr[L]]>1) tot--;
            else if (amount[arr[L]]%2==0 && amount[arr[L]]>0) tot++;
        }
        while (R < que[i].r) {
            R++;
            amount[arr[R]]++;
            if (amount[arr[R]]%2==1 && amount[arr[R]]>1) tot--;
            else if (amount[arr[R]]%2==0 && amount[arr[R]]>0) tot++;
        }
        while (R > que[i].r){
            amount[arr[R]]--;
            if (amount[arr[R]]%2==1 && amount[arr[R]]>0) tot--;
            else if (amount[arr[R]]%2==0 && amount[arr[R]]>0) tot++;
            R--;
        }
        ans[i].first = que[i].third;
        ans[i].second = tot;
    }

    sort(ans, ans+Q);
    for (int i=0; i<Q; i++) printf("%d\n", ans[i].second);

    return 0;
}