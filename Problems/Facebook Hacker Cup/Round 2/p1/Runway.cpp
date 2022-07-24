#include <bits/stdc++.h>
using namespace std;
int T, N, M;
typedef pair <int, bool> pii;
multiset <pii> currentt;
multiset <pii> currentNew;
int main(){
    cin >> T;
    for (int tt=1; tt<=T; tt++){
        scanf("%d %d", &N, &M);
        currentt.clear();
        int ans = 0;
        for (int i=0; i<M; i++){
            int x;
            scanf("%d", &x);
            currentt.insert({x, true});
        }
        // for (auto it: total){
        //     printf("(%d, %d) ", it.first, it.second);
        // } cout << endl;

        // for (auto it: current){
        //     printf("(%d, %d) ", it.first, it.second);
        // } cout << endl << endl;

        for (int i=0; i<N; i++){
            currentNew.clear();
            int subtract = 0;
            for (int j=0; j<M; j++){
                int x;
                scanf("%d", &x);
                auto it = currentt.find({x, false});
                if (it != currentt.end()){
                    currentt.erase(it);
                    subtract++;
                    currentNew.insert({x, false});
                } else {
                    it = currentt.find({x, true});
                    if (it!= currentt.end()) {
                        currentt.erase(it);
                        subtract++;
                        currentNew.insert({x, true});
                    } else {
                        currentNew.insert({x, false});
                    }
                }
            }
            ans += (M-subtract);
            currentt = currentNew;

            // for (auto it: total){
            //     printf("(%d, %d) ", it.first, it.second);
            // } cout << endl;

            // for (auto it: current){
            //     printf("(%d, %d) ", it.first, it.second);
            // } cout << endl;
            // cout << ans << " " << subtract << endl << endl;
        }


        int subtract = 0;
        for (auto it: currentt){
            if (it.second == true) subtract++;
        }
        ans -= (M-subtract);
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}