#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;

bool works(vector <pii> nums, int tot){
    for (pii e: nums){
        if (tot >= e.first + e.second){
            tot -= e.second;
        } else {
            return false;
        }
    }
    return true;
}

int minEnergy(vector <pii> nums){
    int l = 1, r = 1e9;
    int m;
    while (l < r){
        m = (l+r)/2;
        if (works(nums, m)){
            r = m;
        } else {
            l = m+1;
        }
    }
    return l;
}

int main(){
    int n;
    cin >> n;
    vector <pii> nums;
    for (int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        nums.push_back({b-a, a});
    }
    sort(nums.begin(), nums.end(), greater<pii>());
    cout << minEnergy(nums) << endl;
    return 0;
}