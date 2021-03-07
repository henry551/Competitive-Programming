#include <bits/stdc++.h>
using namespace std;

int minimumIncompatibility(vector<int>& nums, int k) {
    int INF = 0x3f3f3f3f;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int sz = n/k;
    vector <int> diff(1<<n, INF);

    for (int mask=1; mask<(1<<n); mask++){
        if (__builtin_popcount(mask) % sz != 0) continue;
        bool dup = false;
        int smallest = INF, biggest = -1;
        for (int i=0; i<n; i++){
            if (mask & (1<<i)){
                smallest = min(smallest, nums[i]);
                if (nums[i] == biggest) {
                    dup = true;
                    break;
                }
                biggest = max(biggest, nums[i]);
            }
        }
        if (!dup) diff[mask] = biggest - smallest;
    }

    vector <int> dp(1<<n, INF);
    dp[0] = 0;
    for (int mask=1; mask<(1<<n); mask++){
        if (__builtin_popcount(mask) % sz != 0) continue;
        for (int sub=mask; sub; sub = (sub-1)&mask){
            if (__builtin_popcount(sub) % sz != 0) continue;
            dp[mask] = min(dp[mask], diff[sub] + dp[sub ^ mask]);
        }
    }
    return dp[(1<<n)-1] != INF ? dp[(1<<n)-1] : -1;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> nums;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << minimumIncompatibility(nums, k) << endl;
    return 0;
}