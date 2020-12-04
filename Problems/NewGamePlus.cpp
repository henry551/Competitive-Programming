#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, k;
int points[500005];
int main(){
    cin >> n >> k;
    for (int i=0; i<n; i++){
        scanf("%d", &points[i]);
    }
    sort(points, points+n, greater<int>());
    ll ans = 0;
    ll bonus = 0;
    int idx = 0;
    while (idx < n && bonus + points[idx] >= 0){
        ans += bonus;
        bonus += points[idx];
        idx++;
    }
    if (idx >= n) {
        cout << ans << endl;
        return 0;
    }
    // cout << "hi " << ans << " " << bonus << endl;
    priority_queue <ll> q;
    ans += bonus;
    points[idx] += bonus;
    int cont = 0;
    while (cont <= k && cont + idx < n){
        q.push(points[idx+cont]);
        cont++;
    }
    if (cont + idx >= n) {
        cout << ans << endl;
        return 0;
    }
    // cout << "hi " << ans << endl;
    for (int i=idx+cont; i<n; i++){
        ll highest = q.top();
        q.pop();
        ans += highest;
        q.push(points[i] + highest);
    }
    cout << ans << endl;
    return 0;
}