//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll N, K;
ll num[200005];
ll maximum = 2e18;

ll neg, pos, zero;
ll a, b, c;

ll numLessNeg(ll key){
    ll r = N-1;
    ll tot = 0;
    for (ll i=a-1; i>=0; i--){
        while (num[i]*num[r] <= key && r >= a+b) r--;
        tot += N-1-r;
    }
    return tot;
}

ll numLessPos(ll key){
    ll r = a-1;
    ll tot = 0;
    for (ll i=0; i<a; i++){
        while (num[i]*num[r] <= key && r >= 0) r--;
        tot += a-1-r;
        if (r < i) tot--;
    }

    r = a+b;
    for (ll i=N-1; i>=a+b; i--){
        while (num[i]*num[r] <= key && r < N) r++;
        tot += r-(a+b);
        if (r > i) tot--;
    }
    return tot/2;
}

int main(){
    cin >> N >> K;
    a = b = c = 0;
    for (int i=0; i<N; i++){
        scanf("%lld", &num[i]);
        if (num[i] < 0) a++;
        else if (num[i] == 0) b++;
        else c++;
    }
    sort(num, num+N);
    neg = a*c;
    pos = a*(a-1)/2+c*(c-1)/2;
    zero = b*(b-1)/2+b*(a+c);

    if (K <= neg){
        ll l = -maximum, r = 0, m;
        while (l < r){
            m = l+(r-l)/2;
            if (numLessNeg(m) < K) l = m+1;
            else r = m;
        }
        cout << l << endl;
    }
    else if (K > neg && K <= neg+zero){
        cout << 0 << endl;
    }
    else {
        ll l = 1, r = maximum, m;
        while (l < r){
            m = l+(r-l)/2;
            if (numLessPos(m) < K-neg-zero) l = m+1;
            else r = m;
        }
        cout << l << endl;
    }
    return 0;
}