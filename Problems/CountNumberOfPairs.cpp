#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair <ll, int> pii;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll N, M;
pii arr[100005];
ordered_set num;

bool cmp (ll a, pii b){
    return a < b.first;
}

int main() {
    scanf("%lld %lld", &N, &M);
    for (int i=1; i<=N; i++) {
        scanf("%lld", &arr[i].first);
        arr[i].second = i;
    }
    sort(arr+1, arr+N+1);
    int past = 0; ll tot = 0;
    for (int i=N; i>0; i--){
        int k = upper_bound(arr+1, arr+N+1, M-arr[i].first, cmp) - arr - 1;
        for (int j = past+1; j<=k; j++) num.insert(arr[j].second);
        past = k;
        tot += num.order_of_key(arr[i].second);
    }
    printf("%lld", tot);
    return 0;
}