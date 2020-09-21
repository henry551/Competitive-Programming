#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct quad{
    ll x, y, t; bool st; //0 = start, 1 = end;
    quad (ll a, ll b, ll c, bool d){
        x = a; y = b; t = c; st = d;
    }
};
int N, T;
vector <quad> glass;
set <ll> val;
vector <ll> conv;
vector <ll> tint;

bool comp(quad a, quad b){
    if (a.x!=b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    scanf("%d %d", &N, &T);
    for (int i=0, a, b, c, d, t; i<N; i++){
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &t);
        glass.push_back(quad(a,b,t,0));
        glass.push_back(quad(c,b,-t,0));
        glass.push_back(quad(a,d,t,1));
        glass.push_back(quad(c,d,-t,1));
        val.insert(b); val.insert(d);
    }
    sort(glass.begin(), glass.end(), comp);
    for (auto it = val.begin(); it != val.end(); it++) conv.push_back(*it);
    tint.assign(conv.size(), 0);
    ll last = -1;
    int cont = 0;
    ll sum = 0, tot = 0;
    while (cont < glass.size() && last < glass[glass.size()-1].x){
        if (glass[cont].x <= last) continue;
        last = glass[cont].x;
        sum = 0;
        for (int j=0; j<tint.size(); j++){
            while (glass[cont].x == last && glass[cont].y==conv[j]){
                if (!glass[cont].st) {
                    sum += glass[cont].t;
                } else {
                    sum -= glass[cont].t;
                }
                cont++;
            }
            tint[j]+=sum;
        }
        for (int j=0; j<tint.size()-1; j++){
            if (tint[j] >= T) {
                tot += (glass[cont].x - glass[cont - 1].x)*(conv[j+1]-conv[j]);
            }
        }
    }
    printf("%lld\n", tot);
    return 0;
}