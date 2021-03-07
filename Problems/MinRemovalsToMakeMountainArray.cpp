#include <bits/stdc++.h>
using namespace std;

int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    int INF = 0x3f3f3f3f;
    vector <int> dp(n+5, INF);
    vector <int> bestl(n, 0);
    dp[0] = -INF;
    for (int i=0; i<n; i++){
        int idx = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (dp[idx-1] < nums[i]){
            dp[idx] = nums[i];
            bestl[i] = idx;
        } else {
            bestl[i] = idx-1;
        }
    }

    vector <int> bestr(n, 0);
    fill(dp.begin(), dp.end(), INF);
    dp[0] = -INF;
    for (int i=n-1; i>=0; i--){
        int idx = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (dp[idx-1] < nums[i]){
            dp[idx] = nums[i];
            bestr[i] = idx;
        } else {
            bestr[i] = idx-1;
        }
    }

    int ans = INF;
    for (int i=0; i<n; i++){
        // cout << bestl[i] << " " << bestr[i] << endl;
        if (bestl[i] >= 2 && bestr[i] >= 2){
            ans = min(ans, n - (bestl[i] + bestr[i] - 1));
        }
    }

    if (ans == INF) return -1;
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector <int> nums(n, 0);
    for (int i=0; i<n; i++){
        scanf("%d", &nums[i]);
    }
    printf("%d\n", minimumMountainRemovals(nums));
    return 0;
}