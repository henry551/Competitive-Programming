#include <bits/stdc++.h>
using namespace std;

struct q {
    int third;
};

bool operator< (const q &a, const q &b) {
    if (a.third != b.third) return a.third > b.third;
}

bool comp(q a, q b){
    return a.third < b.third;
}

set <q> b;
q arr[5];

int main() {
    b.insert({3});
    b.insert({4});
    b.insert({-1});
    b.insert({-2});
    for (auto it: b){
        cout << it.third << endl;
    }
    sort(arr, arr+5);
    arr[0]={1};
    arr[1]={2};
    arr[3]={-5};
    sort(arr, arr+5, comp);
    for (int i=0; i<5; i++){
        cout << arr[i].third << endl;
    }
    return 0;
}