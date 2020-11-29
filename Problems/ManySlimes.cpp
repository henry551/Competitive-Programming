//#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <stack>
using namespace std;
int N;
multiset <int> contain;
multiset <int> notContain;
multiset <int>::iterator it;
stack <int> newInc;
int main() {
    cin >> N;
    int a;
    for (int i=0; i<(1<<N); i++){
        scanf("%d", &a);
        notContain.insert(a);
    }
    it = notContain.end();
    it--;
    contain.insert(*it);
    notContain.erase(it);
    bool works = true;
    for (int i=0; i<N; i++){
        for (auto is: contain){
            it = notContain.lower_bound(is);
            if (it == notContain.begin()) {
                works = false;
                break;
            }
            it--;
            newInc.push(*it);
            notContain.erase(it);
        }
        if (!works){
            break;
        }
        while (!newInc.empty()){
            contain.insert(newInc.top());
            newInc.pop();
        }
    }
    if (works) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}