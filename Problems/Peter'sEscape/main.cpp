#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
struct tri{
    int first, second, third;
};
bool operator<(const tri &a, const tri &b){
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int N, M, O, E;
int sx, sy;

set <tri> xord; set <tri> yord;
set <tri>::iterator it;
map <pii, bool> vis;

int bfs(int vx, int vy){
    queue <tri> q;
    q.push({vx, vy, 0});
    int best = -1;
    while (!q.empty()){
        tri v = q.front();
        q.pop();
        //cout << v.first << " " << v.second << " " << v.third << endl;
        it = xord.upper_bound({v.second, v.first, 0});
        if (it != xord.end() && it->first == v.second && !vis[{it->second, it->first}]){
            //cout << it->second << " a " << it->first << endl;
            vis[{it->second, it->first}] = true;
            if (it->third == 1) {
                best = v.third;
                break;
            }
            q.push({it->second, it->first, v.third+1});
        }
        it = xord.lower_bound({v.second, v.first, 0});
        if (it != xord.begin()){
            it--;
            if (it->first == v.second && !vis[{it->second, it->first}]){
                //cout << it->second << " b " << it->first << endl;
                vis[{it->second, it->first}] = true;
                if (it->third == 1){
                    best = v.third;
                    break;
                }
                q.push({it->second, it->first, v.third+1});
            }
        }
        it = yord.upper_bound({v.first, v.second, 0});
        if (it != yord.end() && it->first == v.first && !vis[{it->first, it->second}]){
            //cout << it->first << " c " << it->second << endl;
            vis[{it->first, it->second}] = true;
            if (it->third == 1) {
                best = v.third;
                break;
            }
            q.push({it->first, it->second, v.third+1});
        }
        it = yord.lower_bound({v.first, v.second, 0});
        if (it != yord.begin()){
            it--;
            if (it->first == v.first && !vis[{it->first, it->second}]){
                //cout << it->first << " d " << it->second << endl;
                vis[{it->first, it->second}] = true;
                if (it->third == 1){
                    best = v.third;
                    break;
                }
                q.push({it->first, it->second, v.third+1});
            }
        }
    }
    return best;
}

int main() {
    scanf("%d %d", &N, &M);
    scanf("%d %d", &sx, &sy);
    scanf("%d", &O);
    for (int i=0, a, b; i<O; i++){
        scanf("%d %d", &a, &b);
        yord.insert({a, b, 0});
        xord.insert({b, a, 0});
        vis[{a,b}]=false;
    }
    scanf("%d", &E);
    for (int i=0, a, b; i<E; i++){
        scanf("%d %d", &a, &b);
        yord.insert({a, b, 1});
        xord.insert({b, a, 1});
        vis[{a,b}]=false;
    }
    printf("%d\n", bfs(sx, sy));
    return 0;
}