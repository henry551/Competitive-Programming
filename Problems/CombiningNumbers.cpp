#include <bits/stdc++.h>
using namespace std;
int N;
int arr[300005];
int nxt[60][600005]; //val, index
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);
    memset(nxt, -1, sizeof(nxt));
    int large = 0;
    for (int i=0; i<N; i++) {
        nxt[arr[i]][i] = i+1;
        large = max(large, arr[i]);
    }
    for (int val = 2; val <= 60; val++){
        for (int i=0; i<N; i++){
            int p = nxt[val-1][i];
            if (p != -1 && nxt[val-1][p] != -1) {
                nxt[val][i]=nxt[val-1][p];
                large = max(large, val);
            }
        }
    }
    printf("%d\n", large);
    return 0;
}