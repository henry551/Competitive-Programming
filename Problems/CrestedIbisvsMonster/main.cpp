#include <iostream>
#define A first
#define B second
using namespace std;
typedef pair <int,int> pii;
int H, N;
pii spells[1005];
int dp[20005];
int main() {
    cin >> H >> N;
    for (int i=0; i<N; i++){
        scanf("%d %d", &spells[i].A, &spells[i].B);
    }
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int i=0; i<=10000; i++) dp[i] = 0;
    for (int i=0; i<N; i++){
        for (int j=10000; j <= 10000+H; j++){
            dp[j] = min(dp[j], dp[j-spells[i].A] + spells[i].B);
        }
    }
    cout << dp[10000+H] << endl;
    return 0;
}
