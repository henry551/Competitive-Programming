#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int T, n;
int permute[1005];
pii leftMinimum[1005];
pii rightMinimum[1005];

int main() {
    cin >> T;
    for (int i=0; i<T; i++){
        scanf("%d", &n);
        for (int j=0; j<n; j++){
            scanf("%d", &permute[j]);
        }
        if (n <= 2){
            printf("NO\n");
            continue;
        }
        leftMinimum[0] = {permute[0],0};
        for (int j=1; j<n; j++){
            if (permute[j] < leftMinimum[j-1].first){
                leftMinimum[j] = {permute[j], j};
            }
            else {
                leftMinimum[j] = leftMinimum[j-1];
            }
        }
        rightMinimum[n-1] = {permute[n-1], n-1};
        for (int j=n-2; j>=0; j--){
            if (permute[j] < rightMinimum[j+1].first){
                rightMinimum[j] = {permute[j], j};
            }
            else {
                rightMinimum[j] = rightMinimum[j+1];
            }
        }
        bool works = false;
        for (int j=1; j<n-1; j++){
            if (leftMinimum[j].first < permute[j] && permute[j] > rightMinimum[j].first){
                works = true;
                printf("YES\n");
                printf("%d %d %d\n", leftMinimum[j].second+1, j+1, rightMinimum[j].second+1);
                break;
            }
        }
        if (!works) printf("NO\n");
    }
    return 0;
}
