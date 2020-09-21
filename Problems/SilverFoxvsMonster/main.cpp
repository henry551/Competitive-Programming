#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pii;
ll N, D, A;
pii monsters[200005];
ll diff[200005];
ll nxt[200005];
ll INF = 0x3f3f3f3f3f3f3f3f;
queue <ll> radius;
ll tot = 0;
int main() {
    cin >> N >> D >> A;
    for (int i=0; i<N; i++){
        scanf("%lld %lld", &monsters[i].first, &monsters[i].second);
    }
    sort(monsters, monsters+N);
    monsters[N].first = INF;

    radius.push(0);
    for (int i=1; i<=N; i++){
        while (!radius.empty() && monsters[radius.front()].first + 2*D < monsters[i].first){
            int a = radius.front();
            radius.pop();
            nxt[a] = i;
        }
        radius.push(i);
    }
    radius.pop(); //get rid of INF element

    ll bombs = 0;
    for (int i=0; i<N; i++){
        bombs += diff[i];
        ll add = max(0LL, monsters[i].second - bombs);
        ll multiples = (add+A-1)/A;
        tot += multiples;
        bombs += multiples*A;
        diff[nxt[i]] -= multiples*A;
    }
    cout << tot << endl;
    return 0;
}
