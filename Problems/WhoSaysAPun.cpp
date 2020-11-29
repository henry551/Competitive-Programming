//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int N;
int Z[5005];
string s;
int main(){
    cin >> N >> s;
    int l, r, k;
    int ans = 0;
    for (int idx = 0; idx < N; idx++) {
        l = r = idx;
        for (int i = idx+1; i < N; i++) {
            if (i > r) {
                l = r = i;
                while (r < N && s[r] == s[r - l + idx]) r++;
                Z[i] = r - l;
                r--;
            } else {
                k = i - l + idx;
                if (Z[k] < r - i + 1) Z[i] = Z[k];
                else {
                    l = i;
                    while (r < N && s[r] == s[r - l + idx]) r++;
                    Z[i] = r - l;
                    r--;
                }
            }
        }
        for (int i=idx+1; i<N; i++) {
            ans = max(ans, min(Z[i], i-idx));
            Z[i] = 0;
        }
    }
    cout << ans << endl;
}