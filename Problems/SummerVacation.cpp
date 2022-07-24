#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
typedef pair <int,int> pii;
int N, M;
pii jobs[100005]; //val, time
set <int> times;
set <int>::iterator it;
typedef long long ll;
ll ans = 0;

bool cmp(pii a, pii b){
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        scanf("%d %d", &jobs[i].second, &jobs[i].first);
    }
    sort(jobs+1, jobs+1+N, cmp);
    for (int i=0; i<M; i++) times.insert(i);
    for (int i=1; i<=N; i++){
        it = times.upper_bound(M-jobs[i].second);
        if (it != times.begin()){
            it--;
            ans += jobs[i].first;
            times.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}