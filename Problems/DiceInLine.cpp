//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
int N, K;
ll p[200005];
double psa[200005];
int main(){
    cin >> N >> K;
    for (int i=1; i<=N; i++){
        scanf("%lld", &p[i]);
        psa[i] = psa[i-1]+(p[i]+1)/2.0;
    }
    double sum = 0;
    for (int i=K; i<=N; i++){
        sum = max(sum, psa[i]-psa[i-K]);
    }
    printf("%.8lf\n", sum);
    return 0;
}

