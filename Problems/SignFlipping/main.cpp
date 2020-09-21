#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
int N, T;
int num[105];
int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &num[i]);
            num[i] = num[i] >= 0 ? num[i] : -num[i];
        }
        int inc = 0;
        int dec = 0;
        for (int i = 0; i < N - 1; i++) {
            if (num[i + 1] >= num[i]) inc++;
            if (num[i + 1] <= num[i]) dec++;
        }

        if (dec < (N - 1) / 2) {
            int change = (N - 1) / 2 - dec;
            int i = 1;
            while (change > 0) {
                if (num[i - 1] >= 0 && num[i] >= 0 && num[i + 1] >= 0 && num[i - 1] < num[i] && num[i] < num[i + 1]) {
                    num[i] *= -1;
                    change--;
                }
                if (i >= N - 1) {
                    printf("PROBLEM\n");
                    break;
                }
                i++;
            }
        }
        if (inc < (N - 1) / 2) {
            int change = (N - 1) / 2 - inc;
            int i = 1;
            while (change > 0) {
                if (num[i - 1] >= 0 && num[i] >= 0 && num[i + 1] >= 0 && num[i - 1] > num[i] && num[i] > num[i + 1]) {
                    num[i] *= -1;
                    change--;
                }
                if (i >= N - 1) {
                    printf("PROBLEM\n");
                    break;
                }
                i++;
            }
        }

        for (int i = 0; i < N; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
    }
    return 0;
}
