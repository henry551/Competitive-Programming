//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll A, B, X;

ll digits(ll num){
    ll count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    cin >> A >> B >> X;
    ll l = 0, r = 1000000001, m;
    while (r-l > 1){
        m = (l+r)/2;
        if (A*m+digits(m)*B <= X) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
}