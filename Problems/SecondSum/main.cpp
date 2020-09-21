//#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
typedef pair <long long,long long> pii;
int N;
pii arr[100005];
long long val[100005];
multiset <long long> larger;
multiset <long long>::iterator it;
struct quad{
    long long l, ll, r, rr;
};
quad neighbouring[100005];

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        scanf("%lld", &arr[i].first);
        val[i] = arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1, arr+N+1);
    larger.insert(0);
    larger.insert(0);
    larger.insert(N+1);
    larger.insert(N+1);
    for (int i=N; i>=1; i--){
        it = larger.upper_bound(arr[i].second);
        it--;
        neighbouring[arr[i].second].l = *it;
        it--;
        neighbouring[arr[i].second].ll = *it;
        it = larger.upper_bound(arr[i].second);
        neighbouring[arr[i].second].r = *it;
        it++;
        neighbouring[arr[i].second].rr = *it;
        larger.insert(arr[i].second);
    }
    long long ans = 0;
    for (long long i=1; i<=N; i++){
        ans += (i-neighbouring[i].l)*(neighbouring[i].rr-neighbouring[i].r) * val[i];
        ans += (neighbouring[i].r-i)*(neighbouring[i].l-neighbouring[i].ll) * val[i];
    }
    cout << ans << endl;
    return 0;
}