#include <iostream>
using namespace std;
int res[6];
int main() {
    int a;
    for (int i=1; i<=5; i++){
        for (int j=1; j<=4; j++){
            scanf("%d", &a);
            res[i]+=a;
        }
    }
    int best = -1;
    int num;
    for (int i=1; i<=5; i++){
        if (best < res[i]){
            best = res[i];
            num = i;
        }
    }
    printf("%d %d\n", num, best);
    return 0;
}