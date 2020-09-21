//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, K;
int arr[505];
int rem[505];
int psa[505];
vector <int> factors;

void findFactors(int tot){
    int p = (int) sqrt(tot)+1;
    for (int i=1; i<=p; i++) {
        if (tot % i == 0) {
            factors.push_back(i);
            factors.push_back(tot/i);
        }
    }
    sort(factors.begin(), factors.end(), greater<>());
}

int main() {
    cin >> N >> K;
    int tot = 0;
    for (int i=1; i<=N; i++){
        scanf("%d", &arr[i]);
        tot += arr[i];
    }
    findFactors(tot);
    int ans;
    for (int f: factors){
        for (int i=1; i<=N; i++){
            rem[i] = arr[i] % f;
        }
        memset(psa, 0, sizeof(psa));
        sort(rem+1, rem+N+1);
        for (int i=1; i<=N; i++) psa[i] = psa[i-1]+rem[i];
        int best = INT_MAX;
        for (int i=1; i<=N; i++){
            if (psa[i]-psa[0] == (N-i)*f-(psa[N]-psa[i])) best = psa[i]-psa[0];
        }
        if (best <= K) {
            ans = f;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
