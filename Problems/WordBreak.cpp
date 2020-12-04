#include <bits/stdc++.h>
using namespace std;

vector <int> seq;
vector <string> ans;

void output(vector <int>* from, string s, int idx){
    if (idx == 0) {
        string res = "";
        for (int i = seq.size()-2; i>=0; i--){
            res += s.substr(seq[i+1], seq[i]-seq[i+1]) + " ";
        }
        res = res.substr(0, res.length()-1);
        ans.push_back(res);
        return;
    }
    if (from[idx].size() == 0) return;
    for (auto e: from[idx]){
        seq.push_back(e);
        output(from, s, e);
        seq.pop_back();
    }
}

bool solve(string s, vector <string> wordDict){
    bool dp[s.size()+5];
    vector <int> from[s.size()+5];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i=0; i<s.length(); i++){
        // cout << i << endl;
        for (string word: wordDict){
            int len = word.length();
            if (i+1-len >= 0 && dp[i+1-len] && s.substr(i-len+1, len) == word){
                dp[i+1] = true;
                from[i+1].push_back(i+1-len);
            }
        }
    }

    seq.push_back(s.length());
    output(from, s, s.length());
    return dp[s.length()];
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector <string> wordDict;
    for (int i=0; i<n; i++){
        string a;
        cin >> a;
        wordDict.push_back(a);
    }
    cout << solve(s, wordDict) << endl;
    for (string e: ans){
        cout << e << endl;
    }
    return 0;
}