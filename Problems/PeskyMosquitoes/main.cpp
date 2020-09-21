//#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <math.h>
using namespace std;
typedef pair <double, double> pii;
int T;
int m;
double d;
set <pii> possible;
pii loc[35];
double err = 0.00000001;
int main() {
    cin >> T;
    for (int qq = 0; qq < T; qq++){
        scanf("%d %lf", &m, &d);
        d /= 2;
        possible.clear();
        for (int i=0; i<m; i++){
            scanf("%lf %lf", &loc[i].first, &loc[i].second);
            possible.insert({loc[i].first, loc[i].second});
        }

        for (int i=0; i<m; i++){
            for (int j=i+1; j<m; j++){
                if (abs(loc[i].first - loc[j].first) < err && abs(loc[i].second - loc[j].second) < err) continue;
                pii mid = {(loc[i].first+loc[j].first)/2, (loc[i].second+loc[j].second)/2};
                pii length = {(loc[i].first - loc[j].first)/2, (loc[i].second - loc[j].second)/2};
                if (d*d + err <= length.first*length.first + length.second*length.second) continue;
                double dist = sqrt(d*d - length.first*length.first - length.second*length.second);
                pii leg = {-(loc[i].second-loc[j].second), loc[i].first-loc[j].first};
                double mag = sqrt(leg.first*leg.first+leg.second*leg.second);
                leg.first /= mag;
                leg.second /= mag;
                leg.first *= dist;
                leg.second *= dist;
                //cout << loc[i].first << " " << loc[i].second << " " << loc[j].first << " " << loc[j].second << "     ";
                //cout << mid.first+leg.first << " " << mid.second+leg.second << " " << mid.first-leg.first << " " << mid.second-leg.second << endl;
                possible.insert({mid.first+leg.first, mid.second+leg.second});
                possible.insert({mid.first-leg.first, mid.second-leg.second});
            }
        }

//        for (auto it: possible){
//            cout << it.first << " " << it.second << endl;
//        }

        int best = 0;
        for (auto it: possible){
            int cont = 0;
            for (int i=0; i<m; i++){
                double dx = loc[i].first - it.first;
                double dy = loc[i].second - it.second;
                if (dx*dx + dy*dy <= d*d + err) cont++;
            }
            best = max(best, cont);
        }
        printf("%d\n", best);
    }
    return 0;
}
