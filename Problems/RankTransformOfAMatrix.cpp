#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;
typedef pair <int,pii> piii;

int n, m;
int vis[505][505];
int label[505][505];
vector <int> row[505];
vector <int> col[505];
int visRow[505];
int visCol[505];

void dfs(pii v, int cont){
    vis[v.first][v.second] = 1;
    label[v.first][v.second] = cont;
    if (!visRow[v.first]){
        visRow[v.first] = 1;
        for (int i: row[v.first]){
            if (!vis[v.first][i]){
                dfs({v.first, i}, cont);
            }
        }
    }
    if (!visCol[v.second]){
        visCol[v.second] = 1;
        for (int i: col[v.second]){
            if (!vis[i][v.second]){
                dfs({i, v.second}, cont);
            }
        }
    }
}

vector<vector<pii>> findGroups(vector<pii> loc){
    for (pii v: loc){
        row[v.first].push_back(v.second);
        col[v.second].push_back(v.first);
    }
    
    int cont = 0;
    for (int i=0; i<loc.size(); i++){
        if (!vis[loc[i].first][loc[i].second]) {
            dfs({loc[i].first, loc[i].second}, cont);
            cont++;
        }
    }

    vector <vector<pii>> groups(cont);
    for (pii v: loc){
        groups[label[v.first][v.second]].push_back({v.first, v.second});
    }

    for (pii v: loc){
        vis[v.first][v.second] = 0;
        label[v.first][v.second] = -1;
        row[v.first].clear();
        col[v.second].clear();
        visRow[v.first] = 0;
        visCol[v.second] = 0;
    }
    return groups;
}

vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
    memset(label, -1, sizeof(label));
    n = matrix.size();
    m = matrix[0].size();
    int INF = 0x3f3f3f3f;
    vector <vector <int>> res;
    res.resize(n, vector<int>(m));

    vector <piii> values;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            values.push_back({matrix[i][j], {i,j}});
        }
    }

    sort(values.begin(), values.end());
    values.push_back({INF, {INF, INF}}); //dummy value at end

    int colRank[m];
    int rowRank[n];
    memset(colRank, 0, sizeof(colRank));
    memset(rowRank, 0, sizeof(rowRank));

    int prev = values[0].first;
    int idx = 0;
    vector <pii> loc;
    while (idx < m*n+1){
        if (values[idx].first != prev){
            vector <vector<pii>> group = findGroups(loc);
            for (int i=0; i<group.size(); i++){
                int minRank = 0;
                for (pii v: group[i]){
                    minRank = max(minRank, max(rowRank[v.first], colRank[v.second])+1);
                }
                for (pii v: group[i]){
                    rowRank[v.first] = minRank;
                    colRank[v.second] = minRank;
                    res[v.first][v.second] = minRank;
                }
            }
            // cout << endl;
            // for (int i=0; i<n; i++){
            //     for (int j=0; j<m; j++){
            //         cout << res[i][j] << " ";
            //     } cout << endl;
            // }
            // cout << endl;

            prev = values[idx].first;
            loc.clear();
        }
        loc.push_back(values[idx].second);
        idx++;
    }

    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <vector <int>> matrix;
    matrix.resize(n,vector<int>(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }

    matrixRankTransform(matrix);

    return 0;
}