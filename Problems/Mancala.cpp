#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int P, K;
int N = 2000;
int counters[2005][2005];
int maxi[2005];

void build(){
    counters[1][0] = 0;
    counters[1][1] = 1;
    int prevMax = 1;
    maxi[1] = 1;
    for (int i=2; i<=N; i++){
        counters[i][0] = 0;
        int end = 0;
        for (int j=1; j<=prevMax+1; j++){
            if (counters[i-1][j] == 0){
                for (int k=1; k<j; k++){
                    counters[i][k] = counters[i-1][k]-1;
                }
                counters[i][j] = j;
                prevMax = max(prevMax, j);
                maxi[i] = prevMax;
                end = j;
                break;
            }
        }
        for (int j=end+1; j<=prevMax; j++){
            counters[i][j] = counters[i-1][j];
        }
    }
}

int main() {
    build();
    scanf("%d", &P);
    for (int i=0; i<P; i++){
        scanf("%d %d", &K, &N);
        printf("%d %d\n", K, maxi[N]);
        for (int j=1; j<=maxi[N]; j++){
            printf("%d ", counters[N][j]);
            if (j != maxi[N] && j % 10 == 0) printf("\n");
        }
        printf("\n");
    }
    return 0;
}