#include <iostream>
using namespace std;

string names[22];
int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> names[i];
    }
    bool inc = true, dec = true;
    for (int i=0; i<N-1; i++){
        if (names[i].compare(names[i+1]) < 0) dec = false;
        else inc = false;
    }
    if (inc) cout << "INCREASING" << endl;
    else if (dec) cout << "DECREASING" << endl;
    else cout << "NEITHER" << endl;
    return 0;
}
