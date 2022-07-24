//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int p;
int fact[3005];
int factInv[3005];
int res[3005];
int coef[3005];

int power(int base, int e){
    int res = 1;
    while (e > 0){
        if (e % 2) res = res * base % p;
        base = base * base % p;
        e /= 2;
    }
    return res;
}

void generate(){
    fact[0]=1;
    for (int i=1; i<=p-1; i++) fact[i] = fact[i-1] * i % p;
    for (int i=0; i<=p-1; i++) factInv[i] = power(fact[i], p-2);
}

int comb(int a, int b){
    return (fact[a]*factInv[a-b])%p*factInv[b]%p;
}

int main() {
    cin >> p;
    generate();
    for (int i=0; i<p; i++){
        scanf("%d", &res[i]);
    }
    for (int i=0; i<p; i++){
        if (res[i]) {
            for (int j=0; j<p; j++){
                coef[p-1-j] += p-(comb(p-1, j) * power(-i, j) % p);
                coef[p-1-j] %= p;
            }
            coef[0] += 1;
            coef[0] %= p;
        }
    }
    for (int i=0; i<p; i++) {
        printf("%d ", coef[i]);
    }
    cout << endl;
//    for (int i=0; i<p; i++) cout << fact[i] << " ";
//    cout << endl;
//    for (int i=0; i<p; i++) cout << factInv[i] << " ";
//    cout << endl;
    return 0;
}