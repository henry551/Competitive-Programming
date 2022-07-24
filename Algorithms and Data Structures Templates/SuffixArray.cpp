#include <bits/stdc++.h>
using namespace std;

int n;
const int alphabet = 256;
vector<int> p, c, cnt;
vector<vector<int>> completeCnt;
vector <int> lcp;
vector <int> suf;

vector<int> sort_cyclic_shifts(string const& s) {
    n = s.size();
    p = vector<int>(n);
    c = vector<int>(n);
    cnt = vector<int> (max(alphabet, n), 0);

    completeCnt = vector<vector<int>> (int(log2(n))+1, vector<int>());

    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;

    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]]) classes++;
        c[p[i]] = classes - 1;
    }

    completeCnt[0].assign(c.begin(), c.end());

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << (h+1)) <= n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev) ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
        completeCnt[h+1].assign(c.begin(), c.end());
    }
    return p;
}

// Time Complexity: O(nlogn)
vector<int> suffix_array(string s) {
    s += "$";
    cout << s << endl;
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    // sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int calc_lcp(int i, int j) {
    int ans = 0;
    for (int k = int(log2(n)); k >= 0; k--) {
        if (completeCnt[k][i] == completeCnt[k][j]) {
            ans += 1 << k;
            i += 1 << k;
            j += 1 << k;
        }
    }
    return ans;
}

// Time Complexity: O(nlogn)
void make_lcps(){
    lcp.push_back(0); // initial lcp doesn't matter
    for (int i=0; i<n-1; i++){
        lcp.push_back(calc_lcp(suf[i],suf[i+1]));
    }
}

int main(){
    suf = suffix_array("anaaaa");
    for (auto it: suf){
        cout << it << " ";
    } cout << endl << endl;

    suf = suffix_array("anaaaaa");
    for (auto it: suf){
        cout << it << " ";
    } cout << endl << endl;

    // suf = suffix_array("anaaaaaaa");
    // for (auto it: suf){
    //     cout << it << " ";
    // } cout << endl << endl;

    for (auto i: completeCnt){
        for (auto j: i) {
            cout << j << " ";
        } cout << endl;
    } cout << endl;

    make_lcps();
    for (auto it: lcp){
        cout << it << " ";
    } cout << endl;
    return 0;
}