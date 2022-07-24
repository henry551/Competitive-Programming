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
        char prev = 'F';
        char first = 'F';
        ll startF = 0; ll sumAfter = 0;
        ll F = 0; ll numBefore = 0; ll sumBefore = 0; ll ans = 0;
        ll numBeforeCopy = 0; ll sumBeforeCopy = 0;
        ll flips = 0;

        for (int i=0; i<s.length(); i++){
            if (s[i] == '.'){
                if (first == 'F') {
                    F = (F * 2) % mod;
                    startF = (startF * 2) % mod;
                }
                else if (first == prev) {
                    // cout << "RUN1" << endl;
                    numBeforeCopy = numBefore; sumBeforeCopy = sumBefore;

                    sumBefore = (sumBefore + numBefore) % mod;
                    numBefore = (numBefore + F) % mod;

                    // note here numBefore is equal to length
                    ans = ans * 2 % mod;
                    ans = (ans + sumBeforeCopy * numBefore % mod + numBefore * sumAfter % mod) % mod;

                    sumBefore = (sumBeforeCopy * 2 % mod + numBefore * flips % mod) % mod;
                    sumAfter = (sumAfter * 2 % mod + numBefore * flips % mod) % mod;
                    numBefore = (numBefore + numBeforeCopy) % mod;
                    flips = flips * 2 % mod;
                }
                else {
                    // cout << "RUN2" << endl;
                    numBeforeCopy = numBefore; sumBeforeCopy = sumBefore;

                    sumBefore = (sumBefore + numBefore) % mod;
                    numBefore = (numBefore + F) % mod;

                    // note here numBefore is equal to length
                    ans = ans * 2 % mod;
                    ans = (ans + sumBeforeCopy * startF % mod + sumBefore * (numBefore - startF + mod) % mod + numBefore * sumAfter % mod) % mod;

                    sumBefore = (sumBeforeCopy * 2 % mod + F * flips % mod + (flips + 1) % mod * (numBefore - F + mod) % mod) % mod;
                    sumAfter = (sumAfter * 2 % mod + startF * flips % mod + (numBefore - startF + mod) % mod * (flips + 1) % mod) % mod;
                    numBefore = (numBefore + numBeforeCopy) % mod;
                    flips = (flips * 2 + 1) % mod;
                }
            }
            else {
                if (s[i] == 'F') {
                    F = (F + 1) % mod;
                } else if ((s[i] == 'X' && prev == 'O') || (s[i] == 'O' && prev == 'X')) {
                    sumBefore = (sumBefore + numBefore) % mod;
                    numBefore = (numBefore + F + 1) % mod;
                    F = 0;
                    prev = s[i];
                    flips = (flips + 1) % mod;
                } else {
                    numBefore = (numBefore + F + 1) % mod;
                    F = 0;
                    prev = s[i];
                }
                if (first == 'F') first = s[i];
                if (first == 'F') startF = (startF + 1) % mod;
                sumAfter = (sumAfter + flips) % mod;
                ans = (ans + sumBefore) % mod;
            }

            // cout << i << " " << F << " " << numBefore << " " << sumBefore << " " << startF << " " << sumAfter << " " << ans << endl;
        }

        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}