#include <bits/stdc++.h>
using namespace std;
int main(){
    tuple <int,char,float> tup1(20,'g',17.5);
    tup1 = make_tuple(3,'b',4.0);
    cout << get<0>(tup1) << endl;
    return 0;
}