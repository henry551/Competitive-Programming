#include <bits/stdc++.h>
using namespace std;
int N;
vector <int> length;
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        int a;
        scanf("%d", &a);
        length.push_back(a);
    }
    sort(length.begin(), length.end());
    long long tot = 0;
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            int k = lower_bound(length.begin(), length.end(), length[i]+length[j]) - 1 - length.begin();
            tot += k-j;
        }
    }
    cout << tot << endl;
    return 0;
}