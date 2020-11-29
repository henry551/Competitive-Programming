//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    int a, b, h;
    cin >> a >> b >> h;
    int dist = 0, cont = 0;
    while (dist < h){
        dist += a;
        cont++;
        if (dist >= h) {
            cout << cont << endl;
            break;
        }
        dist -= b;
    }
//    h -= a;
//    if (h < 0) cout << 1 << endl;
//    else {
//        int div = (h + (a-b-1)) / (a-b);
//        cout << div + 1 << endl;
//    }
    return 0;
}
