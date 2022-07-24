#include <bits/stdc++.h>
using namespace std;
int T, K;
string S;
vector <int> edge[26];
int num[26];

int bfs(int v){
    int res = 0;
    queue <int> q;
    int dist[26];
    memset(dist, -1, sizeof(dist));
    q.push(v);
    dist[v] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        res += dist[cur] * num[cur];
        for (int e: edge[cur]){
            if (dist[e] == -1) {
                q.push(e);
                dist[e] = dist[cur]+1;
            }
        }
    }
    for (int i=0; i<26; i++){
        if (num[i] > 0 && dist[i] == -1) return INT_MAX;
    }
    return res;
}

int main(){
    cin >> T;
    for (int tt=1; tt<=T; tt++){
        cin >> S;
        for (int i=0; i<26; i++) edge[i].clear();
        memset(num, 0, sizeof(num));        
        cin >> K;
        string pairChar;
        for (int i=0; i<K; i++){
            cin >> pairChar;
            edge[pairChar[1]-'A'].push_back(pairChar[0]-'A');
        }
        for (char c: S){
            num[c-'A']++;
        }
        int ans = INT_MAX;
        for (int i=0; i<26; i++){
            ans = min(ans, bfs(i));
        }
        printf("Case #%d: %d\n", tt, (ans == INT_MAX ? -1 : ans));
    }
    return 0;
}