#include <bits/stdc++.h>
using namespace std;
int N;
int arr[55];
int main() {
    for (int i=0; i<5; i++){
        scanf("%d", &N);
        int sum = 0;
        for (int j=0; j<N; j++){
            scanf("%d", &arr[j]);
            sum += arr[j];
        }
        sum /= N;
        int ans = 0;
        for (int j=0; j<N; j++){
            ans += abs(sum - arr[j]);
        }
        cout << ans/2 << endl;
    }
    return 0;
}