#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int grid[9][9];
bool works = true;
set <int> col[9];
set <int> row[9];
set <int> group[9];
set <int>::iterator it;
stack <pii> store;
int main() {
    char a;
    for (int i=1; i<=9; i++){
        for (int j=0; j<9; j++) {
            col[j].insert(i);
            row[j].insert(i);
            group[j].insert(i);
        }
    }
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            scanf(" %c", &a);
            grid[i][j] = (a == '.') ? 0 : a-'0';
        }
    }
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (grid[i][j] != 0){
                col[j].erase(grid[i][j]);
                row[i].erase(grid[i][j]);
                group[i/3*3+j/3].erase(grid[i][j]);

                for (int k=0; k<9; k++){
                    if (k != j && grid[i][j] == grid[i][k]){
                        works = false;
                    }
                    if (k != i && grid[i][j] == grid[k][j]){
                        works = false;
                    }
                }
                for (int k=i/3*3; k<i/3*3+3; k++){
                    for (int l=j/3*3; l<j/3*3+3; l++){
                        if (i != k && j != l && grid[i][j] == grid[k][l]){
                            works = false;
                        }
                    }
                }
            }
        }
    }
    if (!works) {
        printf("ERROR\n");
        return 0;
    }

    for (int w=0; w<100; w++) {
        //group
        for (int k = 0; k < 9; k++) {
            for (it = group[k].begin(); it != group[k].end(); it++) {
                int cont = 0;
                for (int i = k / 3 * 3; i < k / 3 * 3 + 3; i++) {
                    for (int j = k % 3 * 3; j < k % 3 * 3 + 3; j++) {
                        if (grid[i][j] == 0 && row[i].count(*it) && col[j].count(*it)) {
                            cont++;
                        }
                    }
                }
                if (cont == 0) {
                    works = false;
                } else if (cont == 1) {
                    for (int i = k / 3 * 3; i < k / 3 * 3 + 3; i++) {
                        for (int j = k % 3 * 3; j < k % 3 * 3 + 3; j++) {
                            if (grid[i][j] == 0 && row[i].count(*it) && col[j].count(*it)) {
                                grid[i][j] = *it;
                                row[i].erase(grid[i][j]);
                                col[j].erase(grid[i][j]);
                                store.push({i / 3 * 3 + j / 3, grid[i][j]});
                            }
                        }
                    }
                }
            }
        }
        while (!store.empty()) {
            pii b = store.top();
            group[b.first].erase(b.second);
            store.pop();
        }
    }

    if (!works) {
        printf("ERROR\n");
        return 0;
    }

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            printf("%c", (grid[i][j] != 0) ? grid[i][j]+'0' : '.');
        }
        printf("\n");
    }
    return 0;
}