#include <bits/stdc++.h>
using namespace std;

int T;
string S;
int num[26];

int main(){
    cin >> T;
    for (int t=1; t<=T; t++){
        cin >> S;
        memset(num, 0, sizeof(num));
        int cons = 0;
        int vow = 0;
        for (int i=0; i<S.length(); i++){
            if (S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U'){
                vow++;
            } else {
                cons++;
            }
            num[S[i]-'A']++;
        }
        int ans = INT_MAX;
        for (int i=0; i<26; i++){
            if (i == 0 || i == 'E'-'A' || i == 'I'-'A' || i == 'O'-'A' || i == 'U'-'A') { // vowel
                ans = min(ans, cons + 2*(vow-num[i]));
            } else {
                ans = min(ans, vow + 2*(cons-num[i]));
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;    
}