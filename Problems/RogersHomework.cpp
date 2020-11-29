#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n; pii arr[1000005];
priority_queue <int, vector<int>, greater<int>> inc;

bool compare(pii a, pii b){
    return a.first < b.first;
}

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    sort(arr, arr+n, compare);
    long long ans = 0;
    for (int i=0; i<n; i++){
        if (inc.size() < arr[i].first) inc.push(arr[i].second);
        else {
            if (inc.top() < arr[i].second) {
                inc.pop();
                inc.push(arr[i].second);
            }
        }
    }
    while(!inc.empty()) {
        ans += inc.top();
        inc.pop();
    }
    printf("%lld\n", ans);
    return 0;
}