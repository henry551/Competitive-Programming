#include <bits/stdc++.h>
using namespace std;

// O(mn)
// pat has ? and * wildcard characters
bool isMatch(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();
    if (m == 0) return (n == 0);    

    int i = 0, j = 0, index_txt = -1, index_pat = -1;
 
    while (i < n) {
        if (j < m && (txt[i] == pat[j] || pat[j] == '?')) {
            i++;
            j++;
        }
        else if (j < m && pat[j] == '*') {
            index_txt = i;
            index_pat = j;
            j++;
        }
        else if (index_pat != -1) {
            j = index_pat + 1;
            i = index_txt + 1;
            index_txt++;
        }
        else return false;
    }
 
    while (j < m && pat[j] == '*') j++;
    if (j == m) return true;
    return false;
}