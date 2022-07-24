#include <bits/stdc++.h>
using namespace std;

int T;
int N;
char grid[55][55];
int numRow[55];
int numCol[55];
bool oRow[55];
bool oCol[55];

int main(){
    cin >> T;
    for (int tt=1; tt<=T; tt++){
        cin >> N;
        memset(numRow, 0, sizeof(numRow));
        memset(numCol, 0, sizeof(numCol));
        memset(oRow, false, sizeof(oRow));
        memset(oCol, false, sizeof(oCol));
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                scanf(" %c", &grid[i][j]);
                if (grid[i][j] == 'X') {
                    numRow[i]++;
                    numCol[j]++;
                }
                else if (grid[i][j] == 'O'){
                    oRow[i] = true;
                    oCol[j] = true;
                }
            }
        }
        int ans = INT_MAX;
        int num = 0;
        for (int i=0; i<N; i++){
            if (!oRow[i]) {
                if (N-numRow[i] < ans) {
                    ans = N-numRow[i];
                    num = 1;
                } else if (N - numRow[i] == ans) {
                    num++;
                }
            }
            if (!oCol[i]) {
                if (N-numCol[i] < ans) {
                    ans = N-numCol[i];
                    num = 1;
                } else if (N - numCol[i] == ans) {
                    num++;
                }
            }
        }

        if (ans == INT_MAX) {
            printf("Case #%d: Impossible\n", tt);
        } else if (ans != 1) {
            printf("Case #%d: %d %d\n", tt, ans, num);
        } else {
            // account for overcounting when ans = 1
            for (int i=0; i<N; i++){
                for (int j=0; j<N; j++){
                    if (!oRow[i] && !oCol[j] && numRow[i] == N-1 && numCol[j] == N-1 && grid[i][j] == '.') num--;
                }
            }
            printf("Case #%d: %d %d\n", tt, ans, num);
        }
    }
    return 0;
}