//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int N, X;
int items[100005];
int main() {
    cin >> N >> X;
    for (int i=0; i<N; i++){
        scanf("%d", &items[i]);
    }
    sort(items, items+N);
    int ans = 1;
    for (int i=1; i<N; i++){
        if (items[i] + items[i-1] <= X) ans = i+1;
        else break;
    }
    cout << ans << endl;
    return 0;
}
