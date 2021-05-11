#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int N;
string num[105];

bool cmp(string a, string b){
    if (a.length() < b.length()) {
        return false;
    } else if (a.length() > b.length()) {
        return true;
    } else {
        for (int i=0; i<a.length(); i++){
            if (a[i] > b[i]) return true;
            else if (a[i] < b[i]) return false;
        }
    }
    return false;
}

int main(){
    cin >> T;
    for (int tt=0; tt<T; tt++){
        for (int i=0; i<105; i++){
            num[i] = "";
        }
        cin >> N;
        for (int i=0; i<N; i++){
            cin >> num[i];
        }
        int tot = 0;

        string prev = num[0];
        for (int j=1; j<N; j++){
            if (cmp(num[j], prev)) {
                // cout << num[j] << " " << prev << endl;
                prev = num[j];
            }
            else {
                int state = 1; // 0 -> smaller, 1 -> same, 2 -> bigger
                for (int i=0; i<num[j].length(); i++) {
                    if (num[j][i] == prev[i]) {
                        state = 1;
                    } else if (num[j][i] < prev[i]){
                        state = 0;
                        break;
                    } else {
                        state = 2;
                        break;
                    }
                }
                string cur = num[j];
                if (state == 1) {
                    int lastLoc = -1;
                    for (int i=cur.length(); i<prev.length(); i++){
                        if (prev[i] != '9') {
                            lastLoc = i;
                        }
                    }
                    bool changed = false;
                    for (int i=cur.length(); i<prev.length(); i++){
                        if (lastLoc == -1) {
                            cur += '0';
                        }
                        else {
                            if (i < lastLoc) cur += prev[i];
                            else if (i == lastLoc) cur += prev[i]+1;
                            else cur += '0';
                        }
                        tot++;
                    }
                    if (cur <= prev) {
                        cur += '0';
                        tot++;
                    }
                } else if (state == 0) {
                    while (cur.length() <= prev.length()){
                        cur += '0';
                        tot++;
                    }
                } else {
                    while (cur.length() < prev.length()){
                        cur += '0';
                        tot++;
                    }
                }
                prev = cur;
            }
            // cout << j << " " << prev << endl;
        }
        printf("Case #%d: %d\n", tt+1, tot);
    }
    return 0;
}