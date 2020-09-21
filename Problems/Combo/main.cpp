#include <bits/stdc++.h>
using namespace std;

string guess_sequence(int N){
    string a, b, c;
    string ans;
    int v = press("AB");
    if (v >= 1){
        v = press("A");
        if (v == 1) ans += "A";
        else ans += "B";
    } else {
        v = press("X");
        if (v == 1) ans += "X";
        else ans += "Y";
    }
    if (N == 1) return ans;
    a = "A"; b = "B"; c = "X";
    if (ans == "A") a = "Y";
    else if (ans == "B") b = "Y";
    else if (ans == "X") c = "Y";
    for (int i=2; i<N; i++){
        v = press(ans+a+ans+b+a+ans+b+b+ans+b+c);
        if (v == ans.length()) ans += c;
        else if (v == ans.length()+1) ans += a;
        else ans += b;
    }
    v = press(ans+a);
    if (v == ans.length()+1) ans += a;
    else {
        v = press(ans+b);
        if (v == ans.length()+1) ans += b;
        else ans += c;
    }
    return ans;
}