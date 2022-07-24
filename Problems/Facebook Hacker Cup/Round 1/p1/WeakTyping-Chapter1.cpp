#include <bits/stdc++.h>
using namespace std;

int T, N;
string s;
int main(){
    cin >> T;
    for (int tt=1; tt<=T; tt++){
        cin >> N >> s;
        char prev = ' ';
        int ans = 0;
        for (int i=0; i<s.length(); i++){
            if (s[i] == 'F') continue;
            if (s[i] == 'X') {
                if (prev == 'O') ans++;
                prev = 'X';
            } else if (s[i] == 'O') {
                if (prev == 'X') ans++;
                prev = 'O';
            }
        }
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}