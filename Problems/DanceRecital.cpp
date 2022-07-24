#include <iostream>
#include <bitset>
using namespace std;
int perm[10] = {0,1,2,3,4,5,6,7,8,9};
int routine[10];
int main() {
    int N;
    cin >> N;
    string s;
    for (int i=0; i<N; i++){
        cin >> s;
        for (int j=0; j<s.length(); j++){
            routine[i] |= (1 << (s[j] - 'A'));
        }
    }
    int best = INT_MAX;
    do {
        int tot = 0;
        for (int i=0; i<N-1; i++){
            tot += __builtin_popcount(routine[perm[i]] & routine[perm[i+1]]);
        }
        best = min(best, tot);
    } while (next_permutation(perm, perm+N));
    cout << best << endl;
    return 0;
}
