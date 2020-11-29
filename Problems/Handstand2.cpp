#include <iostream>
using namespace std;
long long num[10][10];
int main() {
    int N;
    cin >> N;
    for (int i=1; i<=N; i++){
        int first = i;
        for ( ; first > 9; first /= 10);
        num[first][i%10]++;
    }
    long long ans = 0;
    for (int i=1; i<=9; i++){
        for (int j=0; j<=9; j++){
            ans += num[i][j] * num[j][i];
        }
    }
    cout << ans << endl;
    return 0;
}
