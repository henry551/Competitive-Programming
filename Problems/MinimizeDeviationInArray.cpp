#include <bits/stdc++.h>
using namespace std;

int minimumDeviation(vector<int>& nums) {
    int n = nums.size();
    int cur_min = INT_MAX;
    priority_queue <int> q;
    for (int i=0; i<n; i++){
        if (nums[i] % 2 == 1) {
            nums[i] *= 2;
        }
        cur_min = min(cur_min, nums[i]);
        q.push(nums[i]);
    }
    int ans = q.top() - cur_min;
    while (!q.empty() && q.top() % 2 == 0){
        int t = q.top();
        q.pop();
        t /= 2;
        cur_min = min(cur_min, t);
        q.push(t);
        ans = min(ans, q.top() - cur_min);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector <int> nums;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << minimumDeviation(nums) << endl;
    return 0;
}