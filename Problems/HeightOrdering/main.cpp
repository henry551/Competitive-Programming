#include <iostream>
//#include <bits/stdc++.h>
int arr[50];
int P;
int main() {
    scanf("%d", &P);
    for (int w = 0; w < P; w++) {
        int s;
        scanf("%d", &s);
        memset(arr, 0, sizeof(arr));
        int l = 0, r = 0;
        int tot = 0;
        for (int i = 0; i < 20; i++) {
            int h;
            scanf("%d", &h);
            if (i == 0) arr[l] = h;
            else {
                bool works = true;
                for (int j = l; j <= r; j++) {
                    if (h < arr[j]) {
                        int c = h, b;
                        for (int k = j; k <= r + 1; k++) {
                            b = arr[k];
                            arr[k] = c;
                            c = b;
                        }
                        tot += (r + 1 - j);
                        r = r + 1;
                        works = false;
                        break;
                    }
                }
                if (works) {
                    arr[++r] = h;
                }
            }
        }
        printf("%d %d\n", w+1, tot);
    }
    return 0;
}