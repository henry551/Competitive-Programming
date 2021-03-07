#include <bits/stdc++.h>
using namespace std;

typedef pair <int,bool> pii;

int par[100005];
int height[100005];

bool comp(vector <int> a, vector <int> b){
    return a[2] < b[2];
}

void initialize(int n){
    for (int i=0; i<n; i++){
        par[i] = i;
        height[i] = 1;
    }
}

int findPar(int a){
    if (a == par[a]) return a;
    else return par[a] = findPar(par[a]);
}

void unionJoin(int a, int b){
    int x = findPar(a), y = findPar(b);
    if (x == y) return;
    if (height[x] > height[y]){
        par[y] = x;
    } else if (height[x] < height[y]){
        par[x] = y;
    } else {
        par[x] = y;
        height[y]++;
    }
}

vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    int m = edgeList.size();
    int q = queries.size();
    for (int i=0; i<q; i++){
        queries[i].push_back(i);
    }
    sort(begin(queries), end(queries), [&](auto &a, auto &b) { return a[2] < b[2]; });
    sort(begin(edgeList), end(edgeList), [&](auto &a, auto &b) { return a[2] < b[2]; });

    initialize(n);
    int idx = 0;
    vector <pii> sol;
    for (int i=0; i<q; i++){
        while (idx < m && edgeList[idx][2] < queries[i][2]){
            unionJoin(edgeList[idx][0], edgeList[idx][1]);
            idx++;
        }
        sol.push_back({queries[i][3], findPar(queries[i][0]) == findPar(queries[i][1])});
    }
    sort(sol.begin(), sol.end());
    vector <bool> ans;
    for (int i=0; i<q; i++){
        ans.push_back(sol[i].second);
    }
    return ans;
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> edgeList(m, vector<int>(3, 0));
    vector<vector<int>> queries(q, vector<int>(3, 0));
    for (int i=0; i<m; i++){
        for (int j=0; j<3; j++){
            cin >> edgeList[i][j];
        }
    }
    for (int i=0; i<q; i++){
        for (int j=0; j<3; j++){
            cin >> queries[i][j];
        }
    }
    distanceLimitedPathsExist(n, edgeList, queries);
    return 0;
}