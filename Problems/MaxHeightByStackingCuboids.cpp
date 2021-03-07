#include <bits/stdc++.h>
using namespace std;

bool comp(vector <int> a, vector <int> b){
    if (a[0] != b[0]) return a[0] < b[0];
    else if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

int maxHeight(vector<vector<int>>& cuboids) {
    int n = cuboids.size();
    for (int i=0; i<n; i++){
        sort(cuboids[i].begin(), cuboids[i].end());
    }
    sort(cuboids.begin(), cuboids.end(), comp);
    vector <int> height(n, 0);
    for (int i=0; i<n; i++){
        height[i] = cuboids[i][2];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]){
                height[i] = max(height[i], height[j] + cuboids[i][2]);
            }
        }
    }
    int ans = -1;
    for (int i=0; i<n; i++){
        ans = max(ans, height[i]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> cube(n, vector<int> (3));
    for (int i=0; i<n; i++){
        cin >> cube[i][0] >> cube[i][1] >> cube[i][2];
    }
    cout << maxHeight(cube) << endl;
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<3; j++){
    //         cout << cube[i][j] << " ";
    //     } cout << endl;
    // }
    return 0;
}