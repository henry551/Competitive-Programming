//#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
using namespace std;
int T, W;
int main() {
    cin >> T >> W;
    for (int qq = 1; qq <= T; qq++){
        long long a, b, c, d, e, f;
        a = b = c = d = e = f = 0;
        cout << 224 << endl;
        long long num;
        cin >> num;

        d = (num>>56) % 101;
        num -= (d<<56);
        e = (num>>44) % 101;
        num -= (e<<44);
        f = (num>>37) % 101;

        cout << 54 << endl;
        cin >> num;
        num -= (d<<13) + (e<<10) + (f<<9);
        a = (num>>54) % 101;
        num -= (a<<54);
        b = (num>>27) % 101;
        num -= (b<<27);
        c = (num>>18) % 101;

        printf("%lld %lld %lld %lld %lld %lld", a, b, c, d, e, f);
        cout << endl;
        cin >> num;
    }
    return 0;
}
