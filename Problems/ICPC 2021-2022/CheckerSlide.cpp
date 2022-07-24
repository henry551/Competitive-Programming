#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
#define R first
#define C second
pii st[4];
pii en[4];
int startPos;
int finalPos;
int dist[1700000];
int trans[1700000][4];
int pre[1700000];
set <int> rows[6];
set <int> cols[6];
int INF = 0x3f3f3f3f;

int encode(int r1, int c1, int r2, int c2, int r3, int c3, int r4, int c4){
    int res = r1;
    res *= 6;
    res += c1;
    res *= 6;
    res += r2;
    res *= 6;
    res += c2;
    res *= 6;
    res += r3;
    res *= 6;
    res += c3;
    res *= 6;
    res += r4;
    res *= 6;
    res += c4;
    return res;
}

int encode(vector <pii> d){
    return encode(d[0].R, d[0].C, d[1].R, d[1].C, d[2].R, d[2].C, d[3].R, d[3].C);
}

vector<pii> decode(int num){
    vector <pii> d;
    for (int i=0; i<8; i+=2){
        d.push_back({num/6 % 6, num % 6});
        num /= 36;
    }
    reverse(d.begin(), d.end());
    return d;
}

int bfs(int loc){
    queue <int> q;
    q.push(loc);

    while (!q.empty()){
        int v = q.front();
        q.pop();
        if (v == finalPos) return dist[v];
        vector <pii> data = decode(v);

        for (int i=0; i<6; i++){
            rows[i].clear();
            cols[i].clear();
            rows[i].insert(-1);
            rows[i].insert(6);
            cols[i].insert(-1);
            cols[i].insert(6);
        }
        for (int i=0; i<4; i++){
            rows[data[i].R].insert(data[i].C);
            cols[data[i].C].insert(data[i].R);
        }

        // for (int i=0; i<6; i++){
        //     for (auto it: rows[i]) cout << it << " ";
        //     cout << endl;
        // }

        // for (int i=0; i<6; i++){
        //     for (auto it: cols[i]) cout << it << " ";
        //     cout << endl;
        // }

        for (int i=0; i<4; i++){
            // cout << endl;
            int r = data[i].R;
            int c = data[i].C;
            vector <pii> tempdata = data;
            
            auto it = cols[c].lower_bound(r);
            it--;
            int nw = *it + 1;
            // cout << nw << endl;
            tempdata[i].R = nw;
            tempdata[i].C = c;
            sort(tempdata.begin(), tempdata.end());
            int e = encode(tempdata);
            if (dist[e] == INF){
                dist[e] = dist[v] + 1;
                pre[e] = v;
                trans[e][0] = r; trans[e][1] = c; trans[e][2] = nw; trans[e][3] = c; 
                q.push(e);
                // for (int i=0; i<4; i++){
                //     cout << data[i].R << " " << data[i].C << " ";
                // }
                // cout << "-> ";
                // for (int i=0; i<4; i++){
                //     cout << data[i].R << " " << tempdata[i].C << " ";
                // }
                // cout << endl;
            }

            tempdata = data;
            it = cols[c].upper_bound(r);
            nw = *it - 1;
            tempdata[i].R = nw;
            tempdata[i].C = c;
            sort(tempdata.begin(), tempdata.end());
            e = encode(tempdata);
            if (dist[e] == INF){
                dist[e] = dist[v] + 1;
                pre[e] = v;
                trans[e][0] = r; trans[e][1] = c; trans[e][2] = nw; trans[e][3] = c; 
                q.push(e);
                // for (int i=0; i<4; i++){
                //     cout << data[i].R << " " << data[i].C << " ";
                // }
                // cout << "-> ";
                // for (int i=0; i<4; i++){
                //     cout << data[i].R << " " << tempdata[i].C << " ";
                // }
                // cout << endl;
            }
            
            tempdata = data;
            it = rows[r].lower_bound(c);
            it--;
            nw = *it + 1;
            tempdata[i].R = r;
            tempdata[i].C = nw;
            sort(tempdata.begin(), tempdata.end());
            e = encode(tempdata);
            if (dist[e] == INF){
                dist[e] = dist[v] + 1;
                pre[e] = v;
                trans[e][0] = r; trans[e][1] = c; trans[e][2] = r; trans[e][3] = nw;
                q.push(e);
                // for (int i=0; i<4; i++){
                //     cout << data[i].R << " " << data[i].C << " ";
                // }
                // cout << "-> ";
                // for (int i=0; i<4; i++){
                //     cout << data[i].R << " " << tempdata[i].C << " ";
                // }
                // cout << endl;
            }

            tempdata = data;
            it = rows[r].upper_bound(c);
            nw = *it - 1;
            tempdata[i].R = r;
            tempdata[i].C = nw;
            sort(tempdata.begin(), tempdata.end());
            e = encode(tempdata);
            if (dist[e] == INF){
                dist[e] = dist[v] + 1;
                pre[e] = v;
                trans[e][0] = r; trans[e][1] = c; trans[e][2] = r; trans[e][3] = nw;
                q.push(e);
                // for (int i=0; i<4; i++){
                //     cout << data[i].R << " " << data[i].C << " ";
                // }
                // cout << "-> ";
                // for (int i=0; i<4; i++){
                //     cout << data[i].R << " " << tempdata[i].C << " ";
                // }
                // cout << endl;
            }
        }
    }

    return -1;
}


int main(){
    for (int i=0; i<8; i++){
        if (i % 2 == 0) cin >> st[i/2].R;
        else cin >> st[i/2].C;
    }
    for (int i=0; i<8; i++){
        if (i % 2 == 0) cin >> en[i/2].R;
        else cin >> en[i/2].C;
    }
    sort(st, st+4);
    sort(en, en+4);
    memset(dist, INF, sizeof(dist));
    startPos = encode(st[0].R, st[0].C, st[1].R, st[1].C, st[2].R, st[2].C, st[3].R, st[3].C);
    dist[startPos] = 0;
    pre[startPos] = -1;
    finalPos = encode(en[0].R, en[0].C, en[1].R, en[1].C, en[2].R, en[2].C, en[3].R, en[3].C);
    cout << bfs(startPos) << endl;
    int curPos = finalPos;
    int prevPos;
    vector <vector<int>> v;
    while (curPos != startPos) {
        // prevPos = pre[curPos];
        // vector <pii> p = decode(prevPos);
        // vector <pii> c = decode(curPos);
        // for (int i=0; i<4; i++){
        //     cout << p[i].R << " " << p[i].C << " ";
        // }
        // cout << "-> ";
        // for (int i=0; i<4; i++){
        //     cout << c[i].R << " " << c[i].C << " ";
        // }
        // cout << endl;
        v.push_back({trans[curPos][0], trans[curPos][1], trans[curPos][2], trans[curPos][3]});
        curPos = pre[curPos];
    }
    reverse(v.begin(), v.end());
    for (vector <int> a: v){
        printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
    }
    return 0;
}