#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair <ll,ll> pii;
int N;
long double PI = acos(-1);
pii displace[105];

bool upperHalf(pii a){
    if (a.y > 0) return true;
    return a.x > 0 && a.y == 0;
}

bool cmp(pii a, pii b){
    if (upperHalf(a) && !upperHalf(b)) return true;
    else if (!upperHalf(a) && upperHalf(b)) return false;
    ll c = a.x*b.y - a.y*b.x;
    return c > 0;
}

int main() {
    cin >> N;
    int cont = 0;
    while (cont < N){
        scanf("%lld %lld", &displace[cont].first, &displace[cont].second);
        if (displace[cont].first != 0 || displace[cont].second != 0) cont++;
        else N--;
    }
    sort(displace, displace+N, cmp);
    long double ans = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            pii sum = {0,0};
            for (int k=i; k%N != j; k++){
                sum.first += displace[k%N].first;
                sum.second += displace[k%N].second;
            }
            sum.first += displace[j].first;
            sum.second += displace[j].second;
            ans = max(ans, sqrtl(sum.first*sum.first + sum.second*sum.second));
        }
    }
    printf("%.10Lf\n", ans);
    return 0;
}