#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;
typedef pair <ll,ll> pii;
int T;
pii loc;
stack <char> seq;

bool solve(ll a, ll b){
    //cout << a << " " << b << endl;
    if (a == 0 && b == 0) return true;
    ll x = abs(a), y = abs(b);
    if (x % 2 == y % 2) return false;
    if (x % 2 == 1){
        if (!((a-1)/2 == a && b/2 == b) && solve((a-1)/2, b/2)){
            seq.push('E');
            return true;
        }
        if (!((a+1)/2 == a && b/2 == b) && solve((a+1)/2, b/2)){
            seq.push('W');
            return true;
        }
    }
    else if (y % 2 == 1){
        if (!(a/2 == a && (b-1)/2 == b) && solve(a/2, (b-1)/2)){
            seq.push('N');
            return true;
        }
        if (!(a/2 == a && (b+1)/2 == b) && solve(a/2, (b+1)/2)){
            seq.push('S');
            return true;
        }
    }
    return false;
}

int main() {
    cin >> T;
    for (int qq=0; qq<T; qq++){
        while (!seq.empty()) seq.pop();
        scanf("%lld %lld", &loc.first, &loc.second);
        if (solve(loc.first, loc.second) == false){
            printf("Case #%d: IMPOSSIBLE\n", qq+1);
        }
        else {
            printf("Case #%d: ", qq+1);
            while (!seq.empty()){
                printf("%c", seq.top());
                seq.pop();
            }
            printf("\n");
        }
    }
    return 0;
}
