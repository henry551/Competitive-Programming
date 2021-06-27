#include <bits/stdc++.h>
using namespace std;
int arr[11]; //values are stored from index 1 to 9
int diff[11];
int n;

//O(1)
void update(int l, int r, int val){
    diff[l]+=val;
    diff[r+1]-=val;
}

//O(n)
void reconstruct(){
    for (int i=1; i<=n; i++){
        arr[i]=arr[i-1]+diff[i];
    }
}

//O(n)
void differenceArray()
{
    for (int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    for (int i=1; i<=n; i++){
        diff[i]=arr[i]-arr[i-1];
    }
}
