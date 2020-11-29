#include <bits/stdc++.h>
using namespace std;
int N;
typedef pair <int,int> pii;
pii arr[300005];
vector <pii> operationsCards;
int psa[300005];
int maxCards[300005];

int binarySearch(int idx){
    int l = 1, r = N+1, m;
    while (r-l > 1){
        m = (l+r)/2;
        if (maxCards[m] >= idx) l = m;
        else r = m;
    }
    if (maxCards[l] < idx) return l-1;
    return l;
}

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) arr[i].second = i;
    for (int i=1; i<=N; i++){
        int a;
        scanf("%d", &a);
        arr[a].first++;
    }
    sort(arr+1, arr+1+N);
    for (int i=1; i<=N; i++){
        operationsCards.push_back({arr[i].first, arr[i].second});
    }
    for (int i=1; i<=N; i++){
        psa[i] = psa[i-1]+operationsCards[i-1].first;
    }
    for (int operation = 1; operation <= N; operation++){
        int k = lower_bound(operationsCards.begin(), operationsCards.end(), make_pair(operation, 0)) - operationsCards.begin();
        maxCards[operation] = N-k;
        if (k != 0) maxCards[operation] += psa[k]/operation;
    }
    for (int i=1; i<=N; i++){
        printf("%d\n", binarySearch(i));
    }
    return 0;
}