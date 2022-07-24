#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
    cin >> T;
    string s;
    vector <char> ans;
    for (int tt=1; tt<=T; tt++){
        cin >> s;
        s += char('A' - 1);
        int n = s.length();
        int prev = -1;
        int cont = 0;
        ans.clear();
        for (int i=0; i<n; i++){
            if (s[i] - 'A' == prev) {
                cont++;
            }
            else if (s[i] - 'A' < prev){
                for (int j=0; j<cont; j++){
                    ans.push_back(char(prev + 'A'));
                }
                prev = s[i] - 'A';
                cont = 1;
            } else {
                if (i != 0) {
                    for (int j=0; j<2*cont; j++){
                        ans.push_back(char(prev + 'A'));
                    }
                }
                prev = s[i] - 'A';
                cont = 1;
            }
        }
        printf("Case #%d: ", tt);
        for (char c: ans){
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}