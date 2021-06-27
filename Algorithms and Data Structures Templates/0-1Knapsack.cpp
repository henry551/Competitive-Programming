#include <bits/stdc++.h>
using namespace std;
//0-1 Knapsack
int n;
int w;
int weight[300];
int val[300];
int best1[300][300];
int best2[300];

//Time Complexity: O(nw)
//Space Complexity: O(nw)
void dp1(){
    for (int i=1; i<=n; i++){
        for (int j=weight[i]; j<=w; j++){
            best1[i][j]=max(best1[i-1][j], best1[i-1][j-weight[i]]+val[i]);
        }
    }
}

//Time Complexity: O(nw)
//Space Complexity: O(w)
void dp2(){
    for (int i=1; i<=n; i++){
        for (int j=w; j>=weight[i]; j++){
            best2[j]=max(best2[j], best2[j-weight[i]]+val[i]);
        }
    }
}