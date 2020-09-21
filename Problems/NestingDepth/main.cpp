//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int T;
string s;
int main() {
    cin >> T;
    for (int i=1; i<=T; i++){
        cin >> s;
        printf("Case #%d: ", i);
        int depth = 0;
        for (int j=0; j<s.length(); j++){
            while (depth < s[j]-'0') {
                printf("(");
                depth++;
            }
            while (depth > s[j]-'0'){
                printf(")");
                depth--;
            }
            printf("%d", s[j]-'0');
        }
        while (depth > 0) {
            printf(")");
            depth--;
        }
        printf("\n");
    }
    return 0;
}
