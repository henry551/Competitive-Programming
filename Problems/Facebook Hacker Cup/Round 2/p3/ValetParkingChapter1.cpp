#include <bits/stdc++.h>
using namespace std;

int T, R, C, K;
vector <vector<char>> grid;
vector <int> num;
int main(){
    cin >> T;
    for (int tt = 1; tt <= T; tt++){
        scanf("%d %d %d", &R, &C, &K);
        K--;
        grid.clear();
        num.clear();
        grid = vector<vector<char>> (R, vector<char> (C, ' '));
        num = vector<int> (C, 0);
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                scanf(" %c", &grid[i][j]);
            }
        }

        int ans = INT_MAX;
        for (int i=0; i<K; i++){
            for (int j=0; j<C; j++){
                if (grid[i][j] == 'X') num[j]++;
            }
        }
        
        for (int i=K; i<=R; i++){
            int cont = 0;
            for (int j=0; j<C; j++){
                if (i != R && grid[i][j] == 'X') num[j]++;
                if ((i != R && grid[i][j] == 'X') || num[j] > K) cont++;
            }
            ans = min(ans, i-K+cont);
            // cout << ans << ": ";
            // for (int j=0; j<C; j++) {
            //     cout << num[j] << " ";
            // } cout << endl;
        }

        for (int i=0; i<C; i++) num[i] = 0;
        for (int i=R-1; i>K; i--){
            for (int j=0; j<C; j++){
                if (grid[i][j] == 'X') num[j]++;
            }
        }

        for (int i=K; i>=-1; i--){
            int cont = 0;
            for (int j=0; j<C; j++){
                if (i != -1 && grid[i][j] == 'X') num[j]++;
                if ((i != -1 && grid[i][j] == 'X') || num[j] >= R-K) cont++;
            }
            ans = min(ans, K-i+cont);

            // cout << ans << ": ";
            // for (int j=0; j<C; j++) {
            //     cout << num[j] << " ";
            // } cout << endl;
        }

        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}