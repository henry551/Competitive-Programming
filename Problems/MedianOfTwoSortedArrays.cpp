#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector <int> nums1;
vector <int> nums2;
int arr2[1005];
int cur = 0;
int INF = 0x3f3f3f3f;

int numLess(int k){
    while (arr2[cur] <= k && cur < m && arr2[cur+1] <= k) cur++;
    while (arr2[cur] > k && cur > 0 && arr2[cur] >= k) cur--;
    return cur;
}

int getNums1(int k){
    if (k == -1) return -INF;
    else return nums1[k];
}

int solve(int k){
    cur = 0;
    int l = -1, r = n;
    int mid;
    while (r - l > 1){
        mid = l + (r-l)/2;
        int a = numLess(getNums1(mid)-1);
        mid + 1 + a <= k ? l = mid : r = mid;
    }
    if (n == 0) return arr2[k];
    return max(getNums1(l), arr2[k - l - 1]);
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        nums1.push_back(a);
    }
    for (int j=0; j<m; j++){
        int a;
        cin >> a;
        nums2.push_back(a);
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    for (int i=0; i<m; i++){
        arr2[i+1] = nums2[i];
    }
    arr2[0] = -INF;
    arr2[m+1] = INF;

    if ((n+m)%2 == 1){
        cout << solve((n+m+1)/2) << endl;
    } else {
        cout << (solve((n+m)/2) + solve((n+m)/2 + 1))/2.0 << endl;
    }
    return 0;
}
