#include <bits/stdc++.h>
using namespace std;

vector <int> loc;

//Time Complexity: O(m)
void findlps(char* pat, int m, int* lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

//Time Complexity: O(m+n)
void kmp(char* pat, char* txt) {
    int m = strlen(pat);
    int n = strlen(txt);
    int lps[m];

    findlps(pat, m, lps);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == m) {
            loc.push_back(i-j);
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i = i + 1;
        }
    }
}

void driver(){
    string text = "ABABDABACDABABCABAB", pattern = "ABABCABAB";
    int n = text.length(), m = pattern.length();
    char txt[n+1], pat[m+1];
    strcpy(txt, text.c_str());
    strcpy(pat, pattern.c_str());
    kmp(pat, txt);
}
