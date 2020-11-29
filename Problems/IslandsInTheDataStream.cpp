#include <iostream>
int P;
int arr[20];
using namespace std;
int main() {
    scanf("%d", &P);
    for (int k=0; k<P; k++) {
        int q;
        scanf("%d", &q);
        for (int i = 1; i <= 12; i++) {
            scanf("%d", &arr[i]);
        }
        int small;
        int tot = 0;
        for (int i = 1; i <= 12; i++) {
            small = INT_MAX;
            for (int j = i; j <= 12; j++) {
                small = min(small, arr[j]);
                if (arr[i - 1] < small && arr[j + 1] < small) tot++;
            }
        }
        printf("%d %d\n", k+1, tot);
    }
    return 0;
}