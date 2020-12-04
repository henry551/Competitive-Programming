#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;

int minimumMountainRemovals(vector<int> arr) {
    int res = INT_MAX, n = arr.size();
    vector<int> l, r, dp(n);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(begin(l), end(l), arr[i]);
        if (it == l.end())
            l.push_back(arr[i]);
        else 
            *it = arr[i];
        dp[i] = l.size();
    }
    for (int i = arr.size() - 1; i > 0; --i) {
        auto it = lower_bound(begin(r), end(r), arr[i]);
        if (it == r.end())
            r.push_back(arr[i]);
        else 
            *it = arr[i];
        if (dp[i] > 1)
            res = min(res, n - dp[i] - (int)r.size() + 1);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    stack <pii> seq;
    vector <int> arr(n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << minimumMountainRemovals(arr) << endl;
    return 0;
}