//#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
typedef pair <int,int> pii;
int T, N, K;
int mat[55][55];
set <int> row[55];
set <int> col[55];
set <pii> loc;

bool findd(int &a, int &b){
    if (loc.empty()) return false;
    auto it = loc.begin();
    a = it->first;
    b = it->second;
    return true;
}

bool works(int a, int b, int val, int numDiag, int sumDiag){
    if (!row[a].count(val) || !col[b].count(val)) return false;
    if (a == b){
        if (N*(N-numDiag) < K-sumDiag || 1*(N-numDiag) > K-sumDiag) return false;
    }
    return true;
}

bool solve(int numDiag, int sumDiag){
    int a, b;
    if (!findd(a,b)) return true;
    for (int i=1; i<=N; i++){
        if (works(a,b,i,numDiag+1,sumDiag+i)){
            mat[a][b] = i;
            loc.erase({a,b});
            row[a].erase(i);
            col[b].erase(i);
            if (a == b && solve(numDiag+1, sumDiag+i)) return true;
            else if (a != b && solve(numDiag, sumDiag)) return true;
            row[a].insert(i);
            col[b].insert(i);
            mat[a][b] = -1;
            loc.insert({a,b});
        }
    }
    return false;
}


int main() {
    cin >> T;
    for (int q = 0; q < T; q++){
        printf("Case #%d: ", q+1);
        cin >> N >> K;
        loc.clear();
        for (int i=1; i<=N; i++) {
            row[i].clear();
            col[i].clear();
            for (int j=1; j<=N; j++){
                row[i].insert(j);
                col[i].insert(j);
            }
        }
        for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                loc.insert({i,j});
            }
        }
        memset(mat, -1, sizeof(mat));
        if (solve(0, 0)){
            printf("POSSIBLE\n");
            for (int i=1; i<=N; i++){
                for (int j=1; j<=N; j++){
                    printf("%d ", mat[i][j]);
                }
                printf("\n");
            }
        }
        else {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
