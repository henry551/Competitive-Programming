//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int T;
string num;
int main() {
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> num;
        int l = num.length();
        printf("Case #%d: ", i+1);
        int first = INT_MAX;
        for (int j=0; j<l; j++){
            if (num[j]-'0' != 4) printf("%d", num[j]-'0');
            else {
                first = min(first, j);
                printf("2");
            }
        }
        printf(" ");
        for (int j = first; j<l; j++){
            if (num[j]-'0' == 4) printf("2");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}
