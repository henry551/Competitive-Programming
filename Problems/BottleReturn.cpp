#include <bits/stdc++.h>
using namespace std;

int main(){
    int tot = 0;
    int k;
    for (int i=0; i<6; i++){
        cin >> k;
        tot += k;
    }
    cout << tot*5 << endl;
    return 0;
}