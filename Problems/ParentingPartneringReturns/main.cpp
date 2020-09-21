//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef pair <int,int> pii;
int T, N;
pii task[1005];
vector <pii> seq;
bool C, J;
int ans[1005];

int main() {
    cin >> T;
    for (int i=1; i<=T; i++){
        scanf("%d", &N);
        printf("Case #%d: ", i);
        seq.clear();
        for (int j=1; j<=N; j++){
            scanf("%d %d", &task[j].first, &task[j].second);
            seq.push_back({task[j].first, j});
            seq.push_back({task[j].second, -j});
        }
        sort(seq.begin(), seq.end());
        C = J = false;
        int works = true;
        memset(ans, -1, sizeof(ans));
        for (int j=0; j<seq.size(); j++){
            if (seq[j].second > 0) {
                if (!C) {
                    C = true;
                    ans[seq[j].second] = 0;
                }
                else if (!J){
                    J = true;
                    ans[seq[j].second] = 1;
                }
                else {
                    works = false;
                    break;
                }
            }
            else {
                if (ans[-seq[j].second] == 0) {
                    C = false;
                }
                else {
                    J = false;
                }
            }
        }
        if (!works) printf("IMPOSSIBLE\n");
        else {
            for (int j=1; j<=N; j++){
                printf("%c", ans[j] == 0 ? 'C' : 'J');
            }
            printf("\n");
        }
    }
    return 0;
}
