#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
int T, N, Q;
map <int,int> order;

void solve(vector <int> arr, int start, int end, bool initial, int outside, int relative){
    if (start > end) return;
    if (start == end) {
        order[start] = arr[0];
        return;
    }
    vector <int> loc[3];
    int a;
    int low, high;
    if (!initial) {
        printf("%d %d %d", arr[0], arr[1], outside);
        cout << endl;
        cin >> a;
        if (a == -1) EXIT_FAILURE;
        if (relative == 1){ //outside is higher
            if (a == arr[0]){
                low = arr[1];
                high = arr[0];
            } else {
                low = arr[0];
                high = arr[1];
            }
        } else { //outside is lower
            if (a == arr[0]){
                high = arr[1];
                low = arr[0];
            } else {
                high = arr[0];
                low = arr[1];
            }
        }
    } else {
        low = arr[0];
        high = arr[1];
    }
    if (end - start == 1){
        order[start] = low;
        order[end] = high;
        return;
    }
    for (int i=2; i<arr.size(); i++){
        printf("%d %d %d", low, high, arr[i]);
        cout << endl;
        cin >> a;
        if (a == -1) EXIT_FAILURE;
        if (a == low) loc[0].push_back(arr[i]);
        else if (a == arr[i]) loc[1].push_back(arr[i]);
        else loc[2].push_back(arr[i]);
    }
    order[start+loc[0].size()] = low;
    order[start+loc[0].size()+1+loc[1].size()] = high;

    solve(loc[0], start, start+loc[0].size()-1, false, low, 1);
    solve(loc[1], start+loc[0].size()+1, start+loc[0].size()+loc[1].size(), false, high, 1);
    solve(loc[2], start+loc[0].size()+loc[1].size()+2, end, false, high, 0);
}

int main(){
    cin >> T >> N >> Q;
    for (int tt=0; tt<T; tt++){
        order.clear();
        vector <int> arr;
        for (int i=1; i<=N; i++){
            arr.push_back(i);
        }
        solve(arr, 1, N, true, 0, 0);
        for (auto it: order){
            printf("%d ", it.second);
        }
        cout << endl;
        int a;
        cin >> a;
        if (a == -1) EXIT_FAILURE;
    }
    return 0;
}