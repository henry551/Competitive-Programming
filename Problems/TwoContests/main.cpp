#include <iostream>
using namespace std;
#define l first
#define r second
typedef pair <int,int> pii;
int N;
pii problem[100005];
int leftRegion[100005];
int rightRegion[100005];
int main() {
    scanf("%d", &N);
    int largeL = INT_MIN, smallR = INT_MAX;
    int idxSmall = 0, idxLarge = 0;
    for (int i=0; i<N; i++){
        scanf("%d %d", &problem[i].l, &problem[i].r);
        problem[i].r++;
        if (problem[i].l > largeL){
            largeL = problem[i].l;
            idxLarge = i;
        }
        if (problem[i].r < smallR) {
            smallR = problem[i].r;
            idxSmall = i;
        }
    }
    int ans = 0;
    for (int i=0; i<N; i++){
        if (i != idxLarge && i != idxSmall)
            ans = max(ans, max(0, smallR-largeL) + problem[i].r - problem[i].l);
    }
    int l1 = problem[idxSmall].l, r1 = problem[idxSmall].r;
    int l2 = problem[idxLarge].l, r2 = problem[idxLarge].r;
    sort(problem, problem+N);
    for (int i=0; i<N; i++){
        l1 = max(l1, problem[i].l);
        r1 = min(r1, problem[i].r);
        leftRegion[i] = max(0, r1-l1);
    }
    for (int i=N-1; i>=0; i--){
        l2 = max(l2, problem[i].l);
        r2 = min(r2, problem[i].r);
        rightRegion[i] = max(0, r2-l2);
    }
    for (int i=0; i<N-1; i++){
        ans = max(ans, leftRegion[i]+rightRegion[i+1]);
    }
    cout << ans << endl;
    return 0;
}