//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string S;
int N;
int nearestR[100005];
int nearestL[100005];
int num[100005];
int main() {
    cin >> S;
    N = S.length();
    int last = 0;
    for (int i=0; i<N; i++){
        if (S[i] == 'R') last = i;
        nearestR[i] = last;
    }
    last = N-1;
    for (int i=N-1; i>=0; i--){
        if (S[i] == 'L') last = i;
        nearestL[i] = last;
    }
    for (int i=0; i<N; i++){
        if (S[i] == 'R'){
            (nearestL[i]-i)%2 == 0 ? num[nearestL[i]]++ : num[nearestL[i]-1]++;
        } else {
            (i-nearestR[i])%2 == 0 ? num[nearestR[i]]++ : num[nearestR[i]+1]++;
        }
    }
    for (int i=0; i<N; i++){
        printf("%d ", num[i]);
    } cout << endl;
    return 0;
}