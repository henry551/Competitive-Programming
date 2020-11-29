#include <bits/stdc++.h>
using namespace std;
#define t first
#define p second
typedef long long ll;
typedef pair <ll,ll> pii;
int N, D;
pii notes[105];
vector <ll> comb;
double dp[105][500];

ll power (int b, int e) { ll res = 1; while (e > 0){ if (e%2==1) res*=b; b *= b; e /= 2; } return res; }

int main() {
    scanf("%d %d", &N, &D);
    for (int i=0; i<N; i++) {
        scanf("%lld %lld", &notes[i].t, &notes[i].p);
        notes[i].p--;
    }
    sort(notes, notes+N);

    //setup
    for (int i=0; i<power(12, D); i++){
        bool works = true;
        int num = i;
        for (int j=D-1; j>0; j--){
            ll a = num/power(12,j);
            num %= power(12,j);
            ll b = num/power(12,j-1);
            if (a >= b) {
                works = false;
                break;
            }
        }
        if (works) comb.push_back(i);
    }

    for (auto &i : dp) {
        for (double &j : i) {
            j =-1.0;
        }
    }

    for (int i=0; i<comb.size(); i++){
        ll num = comb[i];
        for (int j=D-1; j>=0; j--) {
            ll a = num / power(12, j);
            if (a == notes[0].p) {
                dp[0][i]=INT_MAX;
            }
            num %= power(12,j);
        }
    }

    for (int i=1; i<N; i++){
        for (int j=0; j<comb.size(); j++){
            //check if comb[j] is a possible combination at this time
            bool works = false;
            ll num = comb[j];
            for (int k=D-1; k>=0; k--){
                ll a = num / power(12, k);
                if (a == notes[i].p) works = true;
                num %= power(12,k);
            }
            if (!works) continue;

            //compare with previous states
            for (int k=0; k<comb.size(); k++){
                if (dp[i-1][k]==-1.0) continue;
                double temp = dp[i-1][k];
                if (k == j) {
                    dp[i][j] = max(dp[i][j], temp);
                    continue;
                }
                ll num1 = comb[j], num2 = comb[k];
                double cnt = 0.0;
                for (int q = D-1; q>=0; q--){
                    ll a = num1/power(12,q), b = num2/power(12,q);
                    if (a != b) cnt++;
                    num1 %= power(12,q); num2 %= power(12,q);
                }
                temp = min(temp, (notes[i].t-notes[i-1].t)/cnt);
                dp[i][j] = max(dp[i][j], temp);
            }
        }
    }

    double best = 0.0;
    for (int i=0; i<comb.size(); i++){
        best = max(best, dp[N-1][i]);
    }
    if (best == INT_MAX) best = 0.0;
    printf("%.2lf\n", best);

    return 0;
}