#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int T, N, C;

int main(){
    cin >> T;
    for (int tt=0; tt<T; tt++){
        cin >> N >> C;
        if (C < N-1 || C >= N*(N+1)/2) {
            printf("Case #%d: IMPOSSIBLE\n", tt+1);
            continue;
        }
        int tot = 0;
        vector <int> arr;
        arr.push_back(N);
        for (int i=N-2; i>=0; i--){
            int k;
            if (N + tot <= C) {
                k = N-i-1;
                tot += N-i;
            } else {
                k = C-tot-i-1;
                tot += C-tot-i;
            }
            if (k > 0) {
                reverse(arr.begin(), arr.begin()+k);
            }
            arr.insert(arr.begin() + k, i+1);
        }
        printf("Case #%d: ", tt+1);
        for (int it: arr){
            printf("%d ", it);
        }
        printf("\n");
    }
    return 0;
}