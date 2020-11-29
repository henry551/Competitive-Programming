//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
string S;
int N, M;
int power[100005];
ll dp[100005][13];
ll mod = 1000000007;
int main() {
    cin >> S;
    N = S.length();
    M = 0;
    int num = 0, e = 1;
    for (int i=N-1; i>=0; i--){
        if (S[i] == '?'){
            power[M] = e;
            M++;
        }
        e = (e*10)%13;
    }
    for (int i=0; i<N; i++){
        num = (num*10)%13;
        if (S[i] != '?'){
            num = (num+S[i]-'0')%13;
        }
    }
    dp[0][num] = 1;
    for (int i=1; i<=M; i++){
        for (int j=0; j<13; j++){
            for (int k=0; k<=9; k++){
                dp[i][(j+k*power[i-1])%13] = (dp[i][(j+k*power[i-1])%13]+dp[i-1][j])%mod;
            }
        }
    }
    cout << dp[M][5] << endl;
    return 0;
}