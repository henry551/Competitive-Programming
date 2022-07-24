#include <bits/stdc++.h>
using namespace std;
int T, N, K;
typedef pair <int,int> pii;
pii pos(int inner, int loc){
    if (loc == 0) return {inner, N/2};
    if (loc == 1) return {N/2, N-1-inner};
    if (loc == 2) return {N-1-inner, N/2};
    else return {N/2, inner};
}

int main(){
    cin >> T;
    for (int tt=1; tt<=T; tt++){
        scanf("%d %d", &N, &K);
        if (K < N-1 || K % 2 == 1) {
            printf("Case #%d: IMPOSSIBLE\n", tt);
            continue;
        }
        vector <int> seq;
        int x = N/2+1;
        int add = N-1;
        int count = 4;
        seq.push_back(x);
        while (x != N*N){
            if (count > 1)
                x += add;
            else
                x += add-1;
            seq.push_back(x);
            count--;
            if (count == 0){
                add -= 2;
                count = 4;
            }
        }
        vector <int> steps;
        for (int i=0; i<seq.size(); i++){
            steps.push_back(seq[i] + (N/2-(i/4)) - 1);
        }

        // for (int s: seq){
        //     cout << s << " ";
        // } cout << endl;

        // for (int s: steps){
        //     cout << s << " ";
        // } cout << endl;

        int k = upper_bound(steps.begin(), steps.end(), K) - steps.begin() - 1;
        
        pii cur[4];
        cur[0] = pos(k/4, k%4);
        cur[3] = {N/2, N/2};
        cur[1] = cur[0];
        cur[2] = cur[3];

        int numSteps = steps[k];
        int nump = seq[k];
        while (numSteps < K){
            if (k%4 == 0){
                cur[1] = {cur[1].first, cur[1].second+1};
                cur[2] = {cur[2].first, cur[2].second+1};
            } else if (k%4 == 1){
                cur[1] = {cur[1].first+1, cur[1].second};
                cur[2] = {cur[2].first+1, cur[2].second};
            } else if (k%4 == 2){
                cur[1] = {cur[1].first, cur[1].second-1};
                cur[2] = {cur[2].first, cur[2].second-1};
            } else {
                cur[1] = {cur[1].first-1, cur[1].second};
                cur[2] = {cur[2].first-1, cur[2].second};
            }
            nump++;
            numSteps += 2;
        }

        // int jump = 0;
        // cout << numSteps << endl;
        // for (int i=0; i<4; i++){
        //     cout << cur[i].first << " " << cur[i].second << endl;
        // }

        // cout << endl;
        vector <pii> ans;
        for (int a = 2; a <= 3; a++) {
            pii p = cur[a-1];
            pii q = {-1,-1};
            int numq = -1;
            while (p != cur[a]){
                // cout << p.first << " " << p.second << endl;
                int change = 0;
                if (p.first == cur[a].first){
                    if (cur[a].second > p.second) change = 1;
                    else change = -1;
                    q = {p.first, p.second + change};
                    if (change == 1){
                        int dist = p.second;
                        if (p.first >= 2+dist && p.first <= N-2-dist){
                            int rad = N-2*dist;
                            int jump = rad * rad - (rad-2)*(rad-2) - 1;
                            numq = nump + jump - 6;
                        } else {
                            numq = nump + 1;
                        }
                    }
                    else {
                        int dist = N-1-p.second;
                        if (p.first >= 1+dist && p.first <= N-2-dist){
                            int rad = N-2*dist;
                            int jump = rad * rad - (rad-2)*(rad-2) - 1;
                            numq = nump + jump - 2;
                        } else {
                            numq = nump + 1;
                        }
                    }
                } else { // p.second == cur[2].second
                    if (cur[a].first > p.first) change = 1;
                    else change = -1;
                    q = {p.first + change, p.second};
                    if (change == 1){
                        int dist = p.first;
                        if (p.second >= dist && p.second <= N-2-dist){
                            int rad = N-2*dist;
                            int jump = rad * rad - (rad-2)*(rad-2) - 1;
                            numq = nump + jump;
                        } else {
                            numq = nump + 1;
                        }
                    }
                    else {
                        int dist = N-1-p.first;
                        if (p.second >= 1+dist && p.second <= N-2-dist){
                            int rad = N-2*dist;
                            int jump = rad * rad - (rad-2)*(rad-2) - 1;
                            numq = nump + jump - 4;
                        } else {
                            numq = nump + 1;
                        }
                    }
                }

                if (numq != nump + 1){
                    ans.push_back({nump, numq});
                }

                nump = numq;
                p = q;
            }
        }

        printf("Case #%d: %d\n", tt, ans.size());
        for (pii a: ans){
            printf("%d %d\n", a.first, a.second);
        }
    }
    return 0;
}