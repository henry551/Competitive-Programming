#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
struct quad{
    int x, y, vx, vy, t;
    quad (int a, int b, int c, int d){
        x = a;
        y = b;
        vx = c;
        vy = d;
    }
};
pii change[5] = {{0,0},{-1,0},{1,0},{0,-1},{0,1}};
int X, Y, N, xs, ys, xe, ye;
bool wind[105][105];
int tim[105][105][22][22];
int INF = 0x3f3f3f3f;

bool check(int orgx, int orgy, int x, int y, int vx, int vy){
    if (!(x >= 0 && x <= X && y >= 0 && y <= Y && vx >= 0 && vx <= 20 && vy >= 0 && vy <= 20)) return false;
    if (orgx == x && orgy == y) return true;
    int dx = x-orgx;
    int dy = y-orgy;
    int g = abs(__gcd(dx, dy));
    for (int i=1; i<=g; i++){
        if (wind[orgx+i*dx/g][orgy+i*dy/g]) return false;
    }
    return true;
}

void bfs() {
    queue <quad> q;
    q.push(quad(xs, ys, 10, 10));
    memset(tim, INF, sizeof(tim));
    tim[xs][ys][10][10]=0;
    while (!q.empty()){
        quad temp = q.front();
        q.pop();
        int x2, y2, vx2, vy2;
        for (int i=0; i<5; i++){
            vx2 = temp.vx+change[i].first;
            vy2 = temp.vy+change[i].second;
            x2 = temp.x-10+vx2;
            y2 = temp.y-10+vy2;
            if (check(temp.x, temp.y, x2, y2, vx2, vy2) && tim[x2][y2][vx2][vy2]>tim[temp.x][temp.y][temp.vx][temp.vy]+1){
                tim[x2][y2][vx2][vy2] = tim[temp.x][temp.y][temp.vx][temp.vy]+1;
                q.push(quad(x2, y2, vx2, vy2));
            }
        }
    }
}

int main() {

    scanf("%d %d %d", &X, &Y, &N);
    scanf("%d %d %d %d", &xs, &ys, &xe, &ye);
    for (int i=0; i<N; i++){
        int xi, yi;
        scanf("%d %d", &xi, &yi);
        wind[xi][yi]=true;
    }

    bfs();
    if (tim[xe][ye][10][10]!=INF) printf("%d\n", tim[xe][ye][10][10]);
    else printf("-1\n");
    return 0;
}