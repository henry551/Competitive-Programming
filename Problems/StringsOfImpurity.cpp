//#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
string s, t;
set <int> loc[26];
set <int>::iterator it;

int main() {
    cin >> s >> t;
    for (int i=0; i<s.length(); i++){
        loc[s[i]-'a'].insert(i);
    }
    for (char i : t){
        if (loc[i-'a'].empty()){
            cout << "-1\n";
            return 0;
        }
    }
    ll repeat = 0, idx = -1;
    for (char i : t){
        it = loc[i-'a'].upper_bound(idx);
        if (it == loc[i-'a'].end()){
            repeat++;
            it = loc[i-'a'].begin();
            idx = *it;
        } else {
            idx = *it;
        }
    }
    cout << repeat*s.size()+idx+1LL << endl;
    return 0;
}