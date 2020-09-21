//#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
using namespace std;
typedef long long ll;
int N;
ll arr[100005];
unordered_set <int> irrelevant;
int main(){
    cin >> N;
    for (int i=0; i<N; i++) scanf("%lld", &arr[i]);
    int cont = 0;
    for (int i=0; i<64; i++){
        cont = 0;
        for (int j=0; j<N; j++) {
            if ((arr[j] & (1LL << i))) cont++;
        }
        if (cont % 2 == 1){
            irrelevant.insert(i);
            for (int j=0; j<N; j++){
                arr[j] &= (~(1LL<<i));
            }
        }
    }
    int idx = 0;
    for (int i=62; i>=0; i--){
        int maxInd = idx;
        ll maxEle = INT_MIN;
        for (int j=idx; j<N; j++){
            if ((arr[j] & (1LL << i)) && maxEle < arr[j]) {
                maxEle = arr[j];
                maxInd = j;
            }
        }
        if (maxEle == INT_MIN) continue;
        swap(arr[idx], arr[maxInd]);
        for (int j=0; j<N; j++){
            if (j != idx && (arr[j] & (1LL << i))) arr[j] ^= maxEle;
        }
        idx++;
    }
    ll ans = 0;
    for (int i=0; i<N; i++){
        ans ^= arr[i];
    }
    ans *= 2;
    for (auto it: irrelevant){
        ans += (1LL<<(it));
    }
    cout << ans << endl;
    return 0;
}