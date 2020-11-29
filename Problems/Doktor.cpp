#include <bits/stdc++.h>
using namespace std;
int N;
int cards[500005];
int psa[500005];
vector <int> cent[1000005];
int tot = 0;
int best, l = 1, r = 1;
int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &cards[i]);
    for (int i=1; i<=N; i++){
        psa[i] += psa[i-1];
        if (cards[i] == i) {
            tot++;
            psa[i]--;
        }
    }
    for (int i=1; i<=N; i++){
        cent[cards[i]+i].push_back(abs(i-cards[i]));
    }
    best = tot;
    for (int i=1; i<=2*N; i++){
        if (cent[i].empty()) continue;
        sort(cent[i].begin(), cent[i].end());
        for (int j=0; j<cent[i].size(); j++){
            if (tot + j+1 + psa[(i+cent[i][j])/2]-psa[(i-cent[i][j])/2-1] > best){
                best = tot + j+1 + psa[(i+cent[i][j])/2]-psa[(i-cent[i][j])/2-1];
                l = cards[(i-cent[i][j])/2], r = cards[(i+cent[i][j])/2];
            }
        }
    }
    printf("%d %d\n", l, r);
    return 0;
}