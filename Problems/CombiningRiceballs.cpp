#include <bits/stdc++.h>
using namespace std;
int N;
int rice[405], psa[405];
int works[405][405];
int large = 0;

int dp(int l, int r){
    if (r < l) return 0;
    if (l==r) { large = max(large, rice[l]); return works[l][r]=1; }
    if (works[l][r]!=-1) {
        if (works[l][r]==1) large = max(large, psa[r]-psa[l-1]);
        return works[l][r];
    }
    for (int i=l; i<r; i++){
        if (psa[i]-psa[l-1] == psa[r]-psa[i] && dp(l,i)==1 && dp(i+1,r)==1){
            works[l][r]=1;
            break;
        }
    }
    if (works[l][r]==1) {
        large = max(large, psa[r]-psa[l-1]);
        return 1;
    }
    int i = l, j = r;
    while (j-i>=2){
        if (psa[i]-psa[l-1] < psa[r]-psa[j-1]) i++;
        else if (psa[i]-psa[l-1] > psa[r]-psa[j-1]) j--;
        else {
            if (dp(l,i)==1 && dp(i+1,j-1)==1 && dp(j,r)==1){
                works[l][r]=1;
                break;
            } else {
                i++; j--;
            }
        }
    }
    if (works[l][r]==1) { large = max(large, psa[r]-psa[l-1]); return 1; }
    else return works[l][r]=0;
}

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%d", &rice[i]);
        psa[i]=psa[i-1]+rice[i];
    }
    memset(works, -1, sizeof(works));
    for (int i=1; i<=N; i++){
        for (int j=N; j>=i; j--){
            if (works[i][j]==-1) dp(i,j);
        }
    }
    printf("%d\n", large);
    return 0;
}