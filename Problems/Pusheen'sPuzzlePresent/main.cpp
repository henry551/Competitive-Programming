#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1005][1005];
int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int tot = 0;
    bool state = false;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            int num = (i-1)*N + j;
            if (state && j==1){
                break;
            }
            else if (arr[i][j]!=num){
                state = true;
                tot++;
            } else if (arr[i][j]==num && state){
                break;
            }
        }
    }
    printf("%d\n", tot);
    return 0;
}