//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair <int,int> pii;
vector <pii> ver;
vector <pii> hor;
int T, P, Q;
int main(){
    cin >> T;
    for (int qq = 1; qq <= T; qq++){
        cin >> P >> Q;
        ver.clear();
        hor.clear();
        ver.push_back({0, 1});
        ver.push_back({Q, -1});
        hor.push_back({0, 1});
        hor.push_back({Q, -1});
        int a, b; char c;
        for (int i=0; i<P; i++){
            scanf("%d %d %c", &a, &b, &c);
            if (c == 'N') ver.push_back({b+1, 1});
            if (c == 'S') ver.push_back({b-1, -1});
            if (c == 'E') hor.push_back({a+1, 1});
            if (c == 'W') hor.push_back({a-1, -1});
        }
        sort(ver.begin(), ver.end());
        sort(hor.begin(), hor.end());

        int tot = 0;
        int best = -1;
        pii loc = {-1, -1};
        for (int i=0; i<hor.size(); i++){
            if (hor[i].second == -1) tot++;
        }
        for (int i=0; i<hor.size(); i++){
            int prev = hor[i].first;
            int sub = 0;
            while (i+1 < hor.size() && hor[i+1].first == prev){
                if (hor[i].second == 1) tot++;
                else sub++;
                i++;
            }
            if (hor[i].second == 1) tot++;
            else sub++;
            if (tot > best) {
                best = tot;
                loc.first = hor[i].first;
            }
            //cout << tot << " a " << hor[i].first << endl;
            tot -= sub;
        }

        tot = 0;
        best = -1;
        for (int i=0; i<ver.size(); i++){
            if (ver[i].second == -1) tot++;
        }
        for (int i=0; i<ver.size(); i++){
            int prev = ver[i].first;
            int sub = 0;
            while (i+1 < ver.size() && ver[i+1].first == prev){
                if (ver[i].second == 1) tot++;
                else sub++;
                i++;
            }
            if (ver[i].second == 1) tot++;
            else sub++;
            if (tot > best) {
                best = tot;
                loc.second = ver[i].first;
            }
            //cout << tot << " b " << ver[i].first << endl;
            tot -= sub;
        }

        printf("Case #%d: %d %d\n", qq, loc.first, loc.second);
    }
    return 0;
}