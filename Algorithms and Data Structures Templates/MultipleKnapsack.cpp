#include <iostream>
#include <deque>
using namespace std;
typedef pair <int,int> pii;
int n, w;
int weight[300];
int val[300];
int num[300];
deque <pii> mono;
int best[300][300];

//Multiple knapsack where there are multiple copies of each item
//Time Complexity: O(nw)
//Space Complexity: O(w) if using a flip array -> best[2][300]

void dp(){
    for (int i=1; i<=n; i++){
        for (int b=0; b<weight[i]; b++){
            mono.clear();
            for (int a=0; a*weight[i]+b <= w; a++){
                int j=a*weight[i]+b;
                while(!mono.empty() && mono.front().second < a-num[i]){
                    mono.pop_front();
                }
                int nxt = best[i-1][j];
                while(!mono.empty() && mono.back().first < nxt-val[i]*a){
                    mono.pop_back();
                }
                mono.push_back({nxt-val[i]*a, a});
                best[i][j]=mono.front().first+val[i]*a;
            }
        }
    }
}