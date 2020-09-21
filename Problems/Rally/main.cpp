//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int N;
int loc[105];
int main() {
    cin >> N;
    for (int i=0; i<N; i++) scanf("%d", &loc[i]);
    int ans = INT_MAX;
    for (int i = -100; i<= 100; i++){
        int temp = 0;
        for (int j=0; j<N; j++) temp += (loc[j]-i)*(loc[j]-i);
        ans = min(temp, ans);
    }
    cout << ans << endl;
    return 0;
}
