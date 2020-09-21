#include <iostream>
using namespace std;
int N;
int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        int a;
        scanf("%d", &a);
        int p, q;
        scanf("%d/%d", &p, &q);
        if (p < q) {
            q -= p;
            p += q;
        } else if (q == 1) {
            int r = p;
            p = q;
            q = r+1;
        } else {
            int r = p / q;
            p %= q;
            q -= p;
            p += q;
            q += r * p;
        }
        printf("%d %d/%d\n", i, p, q);
    }
    return 0;
}