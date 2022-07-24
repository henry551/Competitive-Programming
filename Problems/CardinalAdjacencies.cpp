#include <bits/stdc++.h>
using namespace std;

int n, m;
int sq[1005][1005];
int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            scanf("%d", &sq[i][j]);
        }
    }
    int tot1 = 0;
    int tot2 = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (sq[i][j] && sq[i-1][j]) tot1++;
            if (sq[i][j] && sq[i][j-1]) tot1++;
            if (sq[i][j]) {
                if (sq[i-1][j-1]) tot2++;
                if (sq[i-1][j+1]) tot2++;
                if (sq[i+1][j-1]) tot2++;
                if (sq[i+1][j+1]) tot2++;
            }
        }
    }
    tot2/=2;
    cout << tot1 << " " << tot1+tot2 << endl;
    return 0;
}