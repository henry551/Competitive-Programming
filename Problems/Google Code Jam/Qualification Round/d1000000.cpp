#include <bits/stdc++.h>
using namespace std;

int T, N;
int dice[100005];
int main(){
    cin >> T;
    for (int t=1; t<=T; t++){
        scanf("%d", &N);
        for (int i=0; i<N; i++){
            scanf("%d", &dice[i]);
        }
        sort(dice, dice+N);
        int longest = 0;
        for (int i=0; i<N; i++){
            if (longest < dice[i]){
                longest++;
            }
        }
        printf("Case #%d: %d\n", t, longest);
    }
    return 0;
}