#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    string a;
    cin >> a;
    int cont = 0;
    char prev = ' ';
    for (int i=0; i<N; i++){
        if (a[i] == prev) continue;
        cont++;
        prev = a[i];
    }
    printf("%d\n", cont);
    return 0;
}