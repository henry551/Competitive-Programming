#include <bits/stdc++.h>
using namespace std;
int T;

void print_card (int R, int C){
    for (int i=0; i<2*R; i++){
        for (int j=0; j<2*C+1; j++){
            if (i <= 1 && j <= 1){
                printf(".");
                continue;
            }
            if (i % 2 == 0){
                if (j % 2 == 0) printf("+");
                else printf("-");
            } else {
                if (j % 2 == 0) printf("|");
                else printf(".");
            }
        }
        printf("\n");
    }
    for (int j=0; j<2*C+1; j++){
        if (j % 2 == 0) printf("+");
        else printf("-");
    }
    printf("\n");
}

int main(){
    int R, C;
    scanf("%d", &T);
    for (int i=1; i<=T; i++){
        scanf("%d %d", &R, &C);
        printf("Case #%d:\n", i);
        print_card(R, C);
    }
    return 0;
}