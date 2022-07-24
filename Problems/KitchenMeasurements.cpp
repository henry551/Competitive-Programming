#include <iostream>
#include <queue>
#include <unordered_map>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair <ll,ll> pii;
int N, V;
int c[5];
priority_queue <pii, vector<pii>, greater<pii>> q; //cost, state
unordered_map <ll, ll> dp;
unordered_map <ll, bool> vis;

ll setVolume(ll vol, ll cup, ll state){
    return ((state & (~(0b1111111 << (7*cup)))) | (vol << (7*cup)));
}

ll getVolume(ll cup, ll state){
    return ((state >> (7*cup)) & 0b1111111);
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) cin >> c[i];
    cin >> V;
    q.push({0,setVolume(c[0], 0, 0)});
    dp[setVolume(c[0], 0, 0)] = 0;
    vis[setVolume(c[0], 0, 0)] = true;
    while (!q.empty()){
        pii temp = q.top();
        q.pop();
        if (getVolume(0, temp.second) == V) {
            cout << temp.first << endl;
            return 0;
        }
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (i == j) continue;
                int voli = getVolume(i, temp.second), volj = getVolume(j, temp.second);
                if (voli == c[i] && volj == c[j]) continue;

                //pour from i to j
                int a = min(c[j] - volj, voli);
                ll newState = setVolume(voli-a, i, setVolume(volj+a, j, temp.second));
                if (!vis[newState] || temp.first + a < dp[newState]) {
                    vis[newState] = true;
                    dp[newState] = temp.first + a;
                    q.push({dp[newState], newState});
                }
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}
