#include <iostream>
using namespace std;
int r, c;
int arr[31][31]; //(1,1) to (r,c)
int diff[31][31];

//O(n^2)
void initialize(){
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            diff[i][j] = arr[i][j]-arr[i][j-1];
        }
    }
    for (int i=r; i>0; i--){
        for (int j=1; j<=c; j++){
            diff[i][j]-=diff[i-1][j];
        }
    }
}

//O(1)
void update(int x1, int y1, int x2, int y2, int val){
    diff[x1][y1]+=val;
    diff[x2+1][y2+1]+=val;
    diff[x1][y2+1]-=val;
    diff[x2+1][y1]-=val;
}

//O(n^2)
void reconstruct(){
    memset(arr, 0, sizeof(arr));
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            arr[i][j]+=arr[i-1][j]+diff[i][j];
        }
    }
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            arr[i][j]+=arr[i][j-1];
        }
    }
}