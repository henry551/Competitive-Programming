#include <bits/stdc++.h>
using namespace std;
int n;
int w;
int weight[300];
int val[300];
int best[300];

void dp(){
    for (int i=1; i<=n; i++){
        for (int j=weight[i]; j<=w; j++){
            best[j]=max(best[j], best[j-weight[i]]+val[i]);
        }
    }
}