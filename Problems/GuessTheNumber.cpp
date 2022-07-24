//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int N, M;
int num[4];
int main() {
    cin >> N >> M;
    memset(num, -1, sizeof(num));
    for (int i=0; i<M; i++){
        int s, c;
        cin >> s >> c;
        if (num[s] != -1 && num[s] != c){
            cout << -1 << endl;
            return 0;
        }
        num[s] = c;
    }
    if (num[1] == 0 && N != 1){
        cout << -1 << endl;
        return 0;
    }
    if (N == 1 && num[1] == -1) cout << 0;
    else cout << (num[1] != -1 ? num[1] : 1);
    for (int i=2; i<=N; i++){
        cout << (num[i] != -1 ? num[i] : 0);
    }
    cout << endl;
    return 0;
}
