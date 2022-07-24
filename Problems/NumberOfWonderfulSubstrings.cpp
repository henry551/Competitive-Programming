#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    ll cont[(1<<10)+5];
    long long wonderfulSubstrings(string word) {
        ll ans = 0, mask = 0;
        cont[0] = 1;
        for (char c: word){
            mask ^= (1<<(c-'a'));
            ans += cont[mask];

            // to handle the one odd character that's allowed
            for (int i=0; i<10; i++){
                ans += cont[mask ^ (1<<i)];
            }

            cont[mask]++;
        }
        return ans;
    }
};

int main(){
    Solution sol = Solution();
    string word = "aabb";
    cout << sol.wonderfulSubstrings(word) << endl;
    return 0;
}