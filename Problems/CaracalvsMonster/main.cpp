#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll H;
unordered_map <ll, ll> mp;
ll hits(ll health){
    if (health == 1LL) return mp[1] = 1;
    if (mp.find(health) != mp.end()) return mp[health];
    return mp[health] = 2*hits(health/2)+1LL;
}

int main() {
    cin >> H;
    cout << hits(H) << endl;
    return 0;
}
