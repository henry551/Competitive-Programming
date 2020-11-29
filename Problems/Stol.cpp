#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int r, c;
char apart[405][405];
int row[405];
deque <pii> area;
int main() {
    scanf("%d %d", &r, &c);
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            scanf(" %c", &apart[i][j]);
        }
    }
    int best = INT_MIN;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (apart[i][j]=='.') row[j]++;
            else row[j]=0;
        }
        area.clear();
        for (int j=0; j<=c; j++){
            while(!area.empty() && area.back().first > row[j]) {
                int temp = area.back().first;
                area.pop_back();
                if (!area.empty()) best = max(best, 2*(temp+(j-(area.back().second+1))));
                else best = max(best, 2*(temp+j));
            }
            area.push_back({row[j],j});
        }
    }
    printf("%d\n", best-1);
    return 0;
}