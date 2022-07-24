#include <bits/stdc++.h>
using namespace std;
int T, N;
int main(){
    cin >> T;
    for (int tt=0; tt<T; tt++){
        cin >> N;
        vector <int> arr;
        for (int i=0; i<N; i++){
            int a;
            cin >> a;
            arr.push_back(a);
        }
        int tot = 0;
        for (int i=0; i<N-1; i++){
            int loc = i;
            for (int j=i; j<N; j++){
                if (arr[j] == i+1) loc = j;
            }
            tot += loc-i+1;
            reverse(arr.begin()+i, arr.begin()+loc+1);
        }
        printf("Case #%d: %d\n", tt+1, tot);
    }
    return 0;
}