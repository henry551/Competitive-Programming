#include <bits/stdc++.h>
using namespace std;
int n, threshold;
int num[10005];
int par[10005];
int height[10005];

void initialize(){
    for (int i=1; i<=n; i++){
        par[i] = i;
        height[i] = 1;
    }
}

int findPar(int v){
    if (par[v] == v) return v;
    return par[v] = findPar(par[v]);
}

void unionJoin(int a, int b){
    int x = findPar(a); int y = findPar(b);
    if (x == y) return;
    if (height[x] < height[y]) par[x] = y;
    else if (height[x] > height[y]) par[y] = x;
    else {
        par[x] = y;
        height[y]++;
    }
}

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b%a, a);
}

vector <int> sieve(int n) {
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    vector <int> primes;
    for (int p=2; p*p<=n; p++) { 
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int i=1; i<=n; i++){
        if (prime[i]) primes.push_back(i);
    }
    return primes;
} 

int main(){
    cin >> n >> threshold;
    for (int i=1; i<=n; i++){
        cin >> num[i];
    }
    initialize();
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            if (gcd(num[i], num[j]) > threshold){
                unionJoin(i,j);
            }
        }
    }
    int q;
    cin >> q;
    vector <int> queries;
    for (int i=1; i<=q; i++){
        int a, b;
        cin >> a >> b;
        cout << (findPar(a) == findPar(b)) << endl;
    }
    return 0;
}