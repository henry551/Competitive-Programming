#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[3] = {0, 0, 0};
    a[1] = 2;
    a[2] = 1;
    for (int i=1; i<=min(n, 2); i++){
        cout << a[i] << " ";
    }
    if (n > 2) {
        for (int i=3; i<=n; i++){
            long long c = a[1] + a[2];
            a[1] = a[2];
            a[2] = c;
            cout << a[2] << " ";
            if (i%7 == 0) cout << "\n";
        }
        if (n % 7 != 0) cout << endl;
    } else {
        cout << endl;
    }
    return 0;
}