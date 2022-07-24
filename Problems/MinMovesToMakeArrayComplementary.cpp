#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *larger, int key, int highest){
    int l = 0, r = highest;
    int m;
    while (l < r){
        m = (l+r)/2;
        if (larger[m] >= key){
            r = m;
        } else {
            l = m+1;
        }
    }
    return l;
}

int minMoves(vector<int>& nums, int limit) {
    unordered_map <int,int> sums;
    int n = nums.size();
    int larger[n/2];
    int smaller[n/2];
    for (int i=0; i<n/2; i++){
        larger[i] = max(nums[i], nums[n-1-i]);
        smaller[i] = min(nums[i], nums[n-1-i]);
        sums[nums[i] + nums[n-1-i]]++;
    }
    
    sort(larger, larger+n/2);
    sort(smaller, smaller+n/2);
    int moves = INT_MAX;
    for (auto sum: sums){
        int double_change = binarySearch(larger, sum.first - limit, n/2) + (n/2 - binarySearch(smaller, sum.first, n/2));
        int single_change = n/2 - double_change - sum.second;
        moves = min(single_change + 2*double_change, moves);
    }
    return moves;
}

int main(){
    int n, lim;
    cin >> n >> lim;
    vector <int> nums;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << minMoves(nums, lim) << endl;
}