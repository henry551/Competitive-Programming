#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool happy[100005];
bool prime[100005];
int N;
int main() {
    happy[1] = true;
    happy[2] = false;
    happy[3] = false;
    happy[4] = false;
    for (int i=5; i<=10000; i++){
        //cout << i << endl;
        ll sum = i;
        int p;
        while (true) {
            //cout << sum << endl;
            p = sum;
            sum = 0;
            while (p != 0) {
                sum += (p % 10) * (p % 10);
                p /= 10;
            }
            if (sum == i) {
                happy[i] = false;
                break;
            }
            else if (sum < i) {
                happy[i] = happy[sum];
                break;
            }
        }
    }
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int i=2; i<=10000; i++){
        if (prime[i] == false) continue;
        else {
            for (int j=2*i; j<=10000; j+=i){
                prime[j] = false;
            }
        }
    }
    scanf("%d", &N);
    int a, b;
    for (int i=1; i<=N; i++){
        scanf("%d %d", &a, &b);
        if (happy[b] && prime[b]) printf("%d %d YES", a, b);
        else printf("%d %d NO", a, b);
        if (i < N) printf("\n");
    }
    return 0;
}