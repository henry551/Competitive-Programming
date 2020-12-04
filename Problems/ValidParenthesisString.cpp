#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    stack <int> h;
    deque <int> stars;
    int n = s.length();
    bool works = true;
    for (int i=0; i<n; i++){
        if (s[i] == '*') stars.push_back(i);
        else if (s[i] == '(') h.push(i);
        else {
            if (!h.empty()) {
                h.pop();
            } else if (!stars.empty()){
                stars.pop_front();
            } else {
                works = false;
                break;
            }
        }
    }
    while (!h.empty()){
        if (stars.empty()) {
            works = false;
            break;
        }
        int locBracket = h.top();
        h.pop();
        int locStar = stars.back();
        stars.pop_back();
        if (locBracket > locStar) {
            works = false;
            break;
        }
    }
    return works;
}

int main(){
    string s;
    cin >> s;
    cout << checkValidString(s) << endl;
    return 0;
}