#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
typedef pair <ll,ll> pii;
int N;
pii loc[50005];
ll minf[50005], minb[50005], maxf[50005], maxb[50005];

bool comp(pii a, pii b){
    if (a.y != b.y) return a.y < b.y;
    else return a.x < b.y;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%lld %lld", &loc[i].x, &loc[i].y);
    }
    sort(loc, loc+N);
    minf[0]=maxf[0]=loc[0].y;
    minb[N-1]=maxb[N-1]=loc[N-1].y;
    for (int i=1; i<N; i++){
        minf[i]=min(minf[i-1], loc[i].y);
        maxf[i]=max(maxf[i-1], loc[i].y);
    }
    for (int i=N-2; i>=0; i--){
        minb[i]=min(minb[i+1], loc[i].y);
        maxb[i]=max(maxb[i+1], loc[i].y);
    }
    ll one = 0, two = 0x3f3f3f3f3f3f3f3f;
    for (int i=0; i<N-1; i++){
        int k = i;
        while (k+1 < N && loc[k].x == loc[k+1].x) k++;
        if (k==N-1) break;
        two = min(two, (loc[k].x-loc[0].x)*(maxf[k]-minf[k]) + (loc[N-1].x-loc[k+1].x)*(maxb[k+1]-minb[k+1]));
        i = k;
    }

    sort(loc, loc+N, comp);
    minf[0]=maxf[0]=loc[0].x;
    minb[N-1]=maxb[N-1]=loc[N-1].x;
    for (int i=1; i<N; i++){
        minf[i]=min(minf[i-1], loc[i].x);
        maxf[i]=max(maxf[i-1], loc[i].x);
    }
    for (int i=N-2; i>=0; i--){
        minb[i]=min(minb[i+1], loc[i].x);
        maxb[i]=max(maxb[i+1], loc[i].x);
    }
    for (int i=0; i<N-1; i++){
        int k = i;
        while (k+1 < N && loc[k].y == loc[k+1].y) k++;
        if (k==N-1) break;
        two = min(two, (loc[k].y-loc[0].y)*(maxf[k]-minf[k]) + (loc[N-1].y-loc[k+1].y)*(maxb[k+1]-minb[k+1]));
        i = k;
    }

    if (two == 0x3f3f3f3f3f3f3f3f) printf("0\n");
    else {
        one = (loc[N - 1].y - loc[0].y) * (maxf[N - 1] - minf[N - 1]);
        printf("%lld\n", one - two);
    }
    return 0;
}