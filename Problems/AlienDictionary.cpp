#include <bits/stdc++.h>
using namespace std;

int n;
vector <string> seq;
bool found[26];
vector <int> edges[26];
int vis[26];
stack <int> st;

bool dfs(int v){ // returns if cycle detected
    bool cycle = false;
    vis[v] = 0; // still processing
    for (int e: edges[v]){
        if (vis[e] == -1) cycle |= dfs(e);
        else if (vis[e] == 0) return true;
    }
    vis[v] = 1; // finished
    st.push(v);
    return cycle;
}

string alienOrder(){
    for (int i=0; i<n; i++){
        for (char c: seq[i]) found[c-'a'] = true;
    }

    for (int i=0; i<n-1; i++){
        int n = seq[i].length();
        int m = seq[i+1].length();
        for (int j=0; j<min(n, m); j++) {
            int a = seq[i][j] - 'a';
            int b = seq[i+1][j] - 'a';
            if (a != b && count(edges[a].begin(), edges[a].end(), b) == 0) {
                edges[a].push_back(b);
                break;
            }
        }
    }

    memset(vis, -1, sizeof(vis));
    for (int i=0; i<26; i++){
        if (found[i] && vis[i] == -1) {
            if (dfs(i)) return ""; // cycle detected, topological sort not possible
        }
    }
    vector <int> ans;
    while (!st.empty()){
        ans.push_back(st.top()+'a');
        st.pop();
    }
    return string(ans.begin(), ans.end());
}

int main(){
    cin >> n;
    string s;
    for (int i=0; i<n; i++) {
        cin >> s;
        seq.push_back(s);
    }
    string res = alienOrder();
    for (char c: res){
        printf("%c ", c);
    }
    printf("\n");
    return 0;
}