#include <bits/stdc++.h>
using namespace std;
long long N;
int main() {
    cin >> N;
    long long ans = 0x3f3f3f3f3f3f3f3f;
    long long lim = (long long) (sqrt(N)+1);
    for (long long i=1; i<=lim; i++){
        if (N % i == 0) {
            long long g = N / i;
            ans = min(ans, i+g-2);
        }
    }
    cout << ans << endl;
    return 0;
}