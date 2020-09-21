//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int card[3][3];
bool works[3][3];
int main() {
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin >> card[i][j];
        }
    }
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int a;
        scanf("%d", &a);
        for (int k=0; k<3; k++){
            for (int j=0; j<3; j++){
                if (card[k][j] == a) works[k][j] = true;
            }
        }
    }
    for (int i=0; i<3; i++){
        bool bingo = true;
        for (int j=0; j<3; j++){
            if (works[i][j] == false) bingo = false;
        }
        if (bingo){
            cout << "Yes\n";
            return 0;
        }
    }
    for (int i=0; i<3; i++){
        bool bingo = true;
        for (int j=0; j<3; j++){
            if (works[j][i] == false) bingo = false;
        }
        if (bingo){
            cout << "Yes\n";
            return 0;
        }
    }
    if (works[0][0] && works[1][1] && works[2][2]){
        cout << "Yes\n";
        return 0;
    }
    if (works[0][2] && works[1][1] && works[2][0]){
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}
