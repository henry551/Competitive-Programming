#include <iostream>
using namespace std;
int r, c;
int arr[30][30]; //values are stored from (1,1) to (r,c)
int psa[30][30];

//O(1)
int query(int r1, int c1, int r2, int c2){
    return psa[r2][c2]-psa[r2][c1-1]-psa[r1-1][c2]+psa[r1-1][c1-1];
}

//O(rc)
void prefixSumArray(){
    scanf("%d%d", &r, &c);
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            psa[i][j]=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1]+arr[i][j];
        }
    }
}
