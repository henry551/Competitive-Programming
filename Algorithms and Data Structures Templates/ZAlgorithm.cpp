#include <iostream>
#include <vector>
using namespace std;

int z[100]; //must have length of text + pattern + 1 other character
vector <int> loc;

//Time Complexity: O(m+n), where m is the length of the pattern and n is the length of the text
void getz(string str) {
    int n = str.length();
    int l, r, k;

    l = r = 0;
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r<n && str[r-l] == str[r])
                r++;
            z[i] = r-l;
            r--;
        }
        else {
            k = i-l;
            if (z[k] < r-i+1)
                z[i] = z[k];
            else {
                l = i;
                while (r<n && str[r-l] == str[r])
                    r++;
                z[i] = r-l;
                r--;
            }
        }
    }
}

//Time Complexity: O(m+n)
void srch(const string &text, const string &pattern) {
    string concat = pattern + "$" + text;
    int l = concat.length();
    getz(concat);

    for (int i = 0; i < l; ++i) {
        if (z[i] == pattern.length()) loc.push_back(i-pattern.length()-1);
    }
}

// Driver program
void driver(){
    string text = "AAB AUCAB";
    string pattern = "AB";
    srch(text, pattern);
    for (int e: loc) cout << e << endl;
}