#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N; ll M;
ll cute[200005];
int len = 0, l = 0, r = 0; ll sum = 0;
int main() {
    scanf("%d %lld", &N, &M);
    for (int i=0; i<N; i++){
        scanf("%lld", &cute[i]);
    }
    while (l < N && r <= N){
        if (l > r) {
            r++; continue;
        }
        if (sum < M) {
            sum += cute[r];
            r++;
            len = max(len, r-l-1);
        }
        else {
            sum -= cute[l];
            l++;
            len = max(len, r-l-1);
        }
        //cout << l << " " << r << " " << len << endl;
    }
    printf("%d\n", len);
    return 0;
}