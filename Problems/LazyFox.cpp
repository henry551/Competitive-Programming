#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
struct tri{
    int dist, first, second;
    tri (int a, int b, int c){
        dist = a; first = b; second = c;
    }
};
int N;
vector <pii> points;
vector <tri> par;
int best[2005];
double cd[2005];
int previous[2005];

bool comp(tri a, tri b){ return a.dist < b.dist; }

int main(){
    scanf("%d", &N);
    points.push_back({0,0});
    for (int i=0, a, b; i<N; i++){
        scanf("%d %d", &a, &b);
        points.push_back({a,b});
    }
    for (int i=0; i<=N; i++){
        for (int j=i+1; j<=N; j++){
            int dx = points[i].first-points[j].first;
            int dy = points[i].second-points[j].second;
            par.push_back(tri(dx*dx+dy*dy, i, j));
        }
    }
    sort(par.begin(), par.end(), comp);

    for (int i=0; i<par.size(); i++){
        if (par[i].dist > cd[par[i].first]){
            cd[par[i].first]=par[i].dist;
            previous[par[i].first]=best[par[i].first];
        }
        if (par[i].dist > cd[par[i].second]){
            cd[par[i].second]=par[i].dist;
            previous[par[i].second]=best[par[i].second];
        }

        if (par[i].first==0){
            best[0]=max(best[0], previous[par[i].second]+1);
        } else {
            best[par[i].first] = max(best[par[i].first], previous[par[i].second]+1);
            best[par[i].second] = max(best[par[i].second], previous[par[i].first]+1);
        }
    }
    printf("%d\n", best[0]);
    return 0;
}