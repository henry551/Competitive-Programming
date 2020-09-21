#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pii;
int N; ll K;
pii arr1[22], arr2[22];
vector <ll> l[22];
vector <ll> r[22];
ll tot = 0;
int main() {
    scanf("%d %lld", &N, &K);
    for (int i=0; i<N/2; i++){
        scanf("%lld %lld", &arr1[i].first, &arr1[i].second);
    }
    for (int i=N/2; i<N; i++){
        scanf("%lld %lld", &arr2[i-N/2].first, &arr2[i-N/2].second);
    }
    for (int i=0; i<N/2; i++){
        l[i].push_back(arr1[i].second);
        if (arr1[i].second >= K) tot++;
        for (int j=0; j<i; j++){
            if (arr1[j].first <= arr1[i].first){
                for (ll e: l[j]){
                    l[i].push_back(e+arr1[i].second);
                    if (e+arr1[i].second >= K) tot++;
                }
            }
        }
    }
    for (int i=N-N/2-1; i>=0; i--){
        r[i].push_back(arr2[i].second);
        if (arr2[i].second >= K) tot++;
        for (int j=N-N/2-1; j>i; j--){
            if (arr2[i].first <= arr2[j].first){
                for (ll e: r[j]){
                    r[i].push_back(e+arr2[i].second);
                    if (e+arr2[i].second >= K) tot++;
                }
            }
        }
    }

    for (int i=0; i<=N/2; i++){
        sort(l[i].begin(), l[i].end());
        sort(r[i].begin(), r[i].end());
    }
    for (int i=0; i<N/2; i++){
        for (int j=0; j<N-N/2; j++){
            if (arr1[i].first <= arr2[j].first){
                for (ll e: l[i]){
                    tot += r[j].size() - (lower_bound(r[j].begin(), r[j].end(), K-e) - r[j].begin());
                }
            }
        }
    }
    printf("%lld\n", tot);
    return 0;
}