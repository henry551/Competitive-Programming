//#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
int N, K;
int arr[200005];
unordered_map <int, int> numCount;
queue <int> rem;
int fromLeft[200005];
int main() {
    cin >> N >> K;
    for (int i=1; i<=N; i++) scanf("%d", &arr[i]);
    int increment = 0;
    for (int i=1; i<=N; i++){
        increment += arr[i]-1;
        increment %= K;
        int p = (increment-(arr[i]-1)) % K;
        if (p < 0) p += K;
        rem.push(p);
        numCount[p]++;
        if (i >= K) {
            int r = rem.front();
            rem.pop();
            numCount[r]--;
        }
        fromLeft[i] = numCount[increment];
    }
    long long ans = 0;
    for (int i=1; i<=N; i++) ans += fromLeft[i];
    cout << ans << endl;
    return 0;
}