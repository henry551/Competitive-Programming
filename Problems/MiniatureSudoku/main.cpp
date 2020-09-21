#include <bits/stdc++.h>
using namespace std;
int Q;
int grid[5][5];
bool row[5][5];
bool col[5][5];
bool sq[5][5];

bool solve(int cont){
    if (cont == 0) return true;
    int r = 0, c = 0;
    for (int i=1; i<=4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (grid[i][j] == 0) {
                r = i;
                c = j;
                break;
            }
        }
    }
    for (int i=1; i<=4; i++){
        if (!row[r][i] && !col[c][i] && !sq[(r-1)/2*2+(c-1)/2][i]){
            row[r][i] = true; col[c][i] = true; sq[(r-1)/2*2+(c-1)/2][i] = true;
            grid[r][c] = i;
            if (solve(cont-1)) return true;
            row[r][i] = false; col[c][i] = false; sq[(r-1)/2*2+(c-1)/2][i] = false;
            grid[r][c] = 0;
        }
    }
    return false;
}

int main(){
    scanf("%d", &Q);
    char a;
    for (int i=0; i<Q; i++){
        memset(grid, 0, sizeof(grid));
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(sq, false, sizeof(sq));
        int cont = 16;
        for (int j=1; j<=4; j++){
            for (int k=1; k<=4; k++){
                scanf(" %c", &a);
                grid[j][k] = (a == 'X') ? 0 : a - '0';
                if (grid[j][k] != 0) {
                    cont--;
                    row[j][grid[j][k]] = true; col[k][grid[j][k]] = true;
                    sq[(j-1)/2*2+(k-1)/2][grid[j][k]] = true;
                }
            }
        }
        solve(cont);
        for (int j=1; j<=4; j++){
            for (int k=1; k<=4; k++){
                printf("%d", grid[j][k]);
            }
            printf("\n");
        }
    }
    return 0;
}