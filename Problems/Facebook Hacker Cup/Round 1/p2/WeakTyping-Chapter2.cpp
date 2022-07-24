#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
int T, N;
string s;
int main(){
    cin >> T;
    for (int tt=1; tt<=T; tt++){
        cin >> N >> s;
        char prev = ' ';
        ll F = 0; ll numBefore = 0; ll sumBefore = 0; ll ans = 0;
        for (int i=0; i<s.length(); i++){
            if (s[i] == 'F') {
                F = (F+1)%mod;
            } else if ((s[i] == 'X' && prev == 'O') || (s[i] == 'O' && prev == 'X')) {
                sumBefore = (sumBefore+numBefore)%mod;
                numBefore = (numBefore+F+1)%mod;
                F = 0;
                prev = s[i];
            } else {
                numBefore = (numBefore+F+1)%mod;
                F = 0;
                prev = s[i];
            }
            ans = (ans+sumBefore)%mod;
            // cout << i << " " << F << " " << numBefore << " " << sumBefore << " " << ans << endl;
        }
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}