#include <bits/stdc++.h>
using namespace std;
string a[5], b[5];
bool works = false;
bool same = false;

bool comp(){
    if (a[1] == b[1] && a[2] == b[2] && a[3] == b[3] && a[4] == b[4]) return true;
    return false;
}

bool reflect(){
    if (a[1] == b[1] && a[3] == b[3] && a[2] == b[4] && a[4] == b[2]) return true;
    return false;
}

void rot1(string x[5]){
    string t = x[1];
    x[1] = x[2];
    x[2] = x[3];
    x[3] = t;
}

void rot2(string x[5]){
    string t = x[2];
    x[2] = x[3];
    x[3] = x[4];
    x[4] = t;
}

void rot3(string x[5]){
    string t = x[1];
    x[1] = x[4];
    x[4] = t;
    t = x[3];
    x[3] = x[2];
    x[2] = t;
}

void check(){
    for (int j=0; j<3; j++){
        rot2(b);
        works = works | reflect();
        same = same | comp();
    }
    rot1(b);
    for (int j=0; j<3; j++){
        rot2(b);
        works = works | reflect();
        same = same | comp();
    }
    rot1(b);
    for (int j=0; j<3; j++){
        rot2(b);
        works = works | reflect();
        same = same | comp();
    }
    rot3(b);
    for (int j=0; j<3; j++){
        rot2(b);
        works = works | reflect();
        same = same | comp();
    }
}

int main() {
    for (int i=1; i<=4; i++){
        cin >> a[i];
    }
    for (int i=1; i<=4; i++){
        cin >> b[i];
    }

    for (int j=0; j<3; j++){
        rot2(a);
        check();
    }
    rot1(a);
    for (int j=0; j<3; j++){
        rot2(a);
        check();
    }
    rot1(a);
    for (int j=0; j<3; j++){
        rot2(a);
        check();
    }
    rot3(a);
    for (int j=0; j<3; j++){
        rot2(a);
        check();
    }
    if (!same && works) printf("YES\n");
    else printf("NO\n");
    return 0;
}