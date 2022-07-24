#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int T; string Y;

string cmp(string a, string b){
    if (b == "") return a;
    if (a == "") return b;
    if (a.length() < b.length()) return a;
    if (b.length() < a.length()) return b;
    for (int i=0; i<a.length(); i++){
        if (a[i] < b[i]) return a;
        if (b[i] < a[i]) return b;
    }
    return a;
}

ll power(ll base, ll e){
    ll res = 1;
    for (int i=1; i<=e; i++){
        res *= base;
    }
    return res;
}

bool larger(string a, string b){
    if (a == b) return false;
    if (b == "") return true;
    if (a == "") return false;
    if (a.length() < b.length()) return false;
    if (b.length() < a.length()) return true;
    for (int i=0; i<a.length(); i++){
        if (a[i] < b[i]) return false;
        if (b[i] < a[i]) return true;
    }
    return false;
}

string generate(int v){
    for (int q=v+1; ; q++){
    int start = 1;
    bool suc = false;
    while (start < q){
        string res = "";
        int idx = 0;
        while (res.length() < to_string(q).length()){
            res += to_string(start+idx);
            idx++;
        }
        if (res == to_string(q)){
            return to_string(q);
            suc = true;
            break;
        }
        start++;
    }
    }
}

string solve2(string Y){
        int N = Y.length();
        string best = "";
        for (int s = 1; s < N; s++){
            ll begin = stoll(Y.substr(0, s));
            int digits = to_string(begin).length();
            string res = "";
            int idx = 0;
            while (!larger(res, Y)){
                res += to_string(begin+idx);
                idx++;
            }
            if (res != Y && larger(res, Y)) {
                best = cmp(best, res);
            }
            begin++;
            res = "";
            idx = 0;
            while (!larger(res, Y)){
                res += to_string(begin+idx);
                idx++;
            }
            if (res != Y) {
                best = cmp(best, res);
            }
            // cout << begin << " " << res << endl;
            // best = cmp(best, res);
            // if (digits < to_string(begin+int(ceil(N/s))).length()){
            begin = power(10, digits);
            if (begin < 21) begin = 21;
            begin -= 20;
            // cout << begin << endl;
            for (; to_string(begin).length() == digits; begin++){
                res = "";
                int idx = 0;
                while (!larger(res, Y)){
                    res += to_string(begin+idx);
                    idx++;
                }
                if (larger(res, Y)){
                    best = cmp(best, res);
                }
            }
            // }
        }
        string res = "";
        int factor = 1;
        for (int i=2; i<N+1; i++){
            if ((N+1)%i==0) factor = i;
        }

        ll begin = power(10, factor-1);
        // cout << begin << endl;
        int idx = 0;
        while (res.length() < N+1){
            res += to_string(begin+idx);
            idx++;
        }
        best = cmp(best, res);
        return best;
}

int main(){
    cin >> T;
    for (int tt = 1; tt <= T; tt++){
        cin >> Y;
        printf("Case #%d: ", tt);
        cout << solve2(Y) << endl;
    }
}