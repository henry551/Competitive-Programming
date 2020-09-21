#include <bits/stdc++.h>
using namespace std;
int arr[3];

int main() {
    for (int i=1; i<=3; i++){
        scanf("%d", &arr[i]);
    }
    for (int j=0; j<5; j++) {
        for (int i = 1; i<=3; i++) {
            if (arr[i] == 0) arr[i] = -1;
            if (arr[i] != -1 && arr[i] <= 3 && arr[arr[i]] == -1) arr[i] = -1;
        }
    }
    bool works = true;
    for (int i=1; i<=3; i++) if (arr[i]!=-1) works = false;
    if (works) printf("YES\n");
    else printf("NO\n");
    return 0;
}