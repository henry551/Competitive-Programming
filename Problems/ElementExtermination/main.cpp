#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    cin >> T;
    for (int t = 0; t < T; t++){
        scanf("%d", &N);
        int a, b;
        scanf("%d", &a);
        for (int i=1; i<N; i++){
            scanf("%d", &b);
        }
        if (a < b) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
