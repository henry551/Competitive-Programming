#include <iostream>
using namespace std;
typedef pair <int,int> pii;
typedef long long ll;
int T, A, B;
string s;
bool works = false;
pii c = make_pair((1e8),23);
ll radius = (1e9)/2;

string sit(int x, int y){
    if (x == c.first && y == c.second) return "CENTER";
    ll dx = x-c.first;
    ll dy = y-c.second;
    if (dx*dx+dy*dy <= radius*radius) return "HIT";
    return "MISS";
}

pii rad(int x){
    int l = (1e9)/4, r = 1e9, m;
    while (l < r){
        m = (l+r)/2;
        //s = sit(x, m);
        cout << x << " " << m << endl;
        cin >> s;
        if (s == "HIT") l = m+1;
        else r = m;
    }
    int top = l-1;

    l = -1e9, r = (-1e9)/4, m;
    while (l < r){
        m = (l+r-1)/2;
        cout << x << " " << m << endl;
        cin >> s;
        //s = sit(x, m);
        if (s == "MISS") l = m+1;
        else r = m;
    }
    int bottom = l;
    pii a = make_pair(top, bottom);
    return a;
}

pii rad2(int y){
    int l = (1e9)/4, r = 1e9, m;
    while (l < r){
        m = (l+r)/2;
        //s = sit(m, y);
        cout << m << " " << y << endl;
        cin >> s;
        if (s == "HIT") l = m+1;
        else r = m;
    }
    int top = l-1;

    l = -1e9, r = (-1e9)/4, m;
    while (l < r){
        m = (l+r-1)/2;
        cout << m << " " << y << endl;
        cin >> s;
        //s = sit(m, y);
        if (s == "MISS") l = m+1;
        else r = m;
    }
    int bottom = l;
    pii a = make_pair(top, bottom);
    return a;
}

//int rad(int x){
//    cout << "value: " << x << " " << endl;
//    cin >> x;
//    return x;
//}

int main() {
    cin >> T >> A >> B;
    if (A == 1e9-5 && B == 1e9-5) {
        for (int qq = 0; qq < T; qq++) {
            works = false;
            for (int i = -5; i <= 5; i++) {
                for (int j = -5; j <= 5; j++) {
                    cout << i << " " << j << endl;
                    cin >> s;
                    if (s == "CENTER") {
                        works = true;
                        break;
                    }
                }
                if (works) break;
            }
        }
    }
    else {
        for (int qq = 0; qq < T; qq++){
            int l = -50, r = 50, m;
            pii loc = rad(0);
            int x = (loc.first+loc.second)/2;
            loc = rad2(0);
            int y = (loc.first+loc.second)/2;
//            while (l < r){
//                cont++;
//                if (cont > 20) break;
//                m = (l+r-1)/2;
//                int a, b;
//                pii loc = rad(m);
//                a = (loc.first-loc.second)/2;
//                cout << l << " " << m << " " << r << " " << (loc.first+loc.second)/2 << endl;
//                loc = rad(m+1);
//                b = (loc.first-loc.second)/2;
//                cout << l << " " << m << " " << r << " " << a << " " << b << endl;
////                a = rad(m);
////                b = rad(m+1);
//                if (a <= b) l = m+1;
//                else r = m;
//            }
            //pii loc = rad(l);
            //cout << l << " " << (loc.first+loc.second)/2 << endl;
            cout << y << " " << x << endl;
            //cout << l << " " << rad(l) << endl;
            cin >> s;
        }
    }
    return 0;
}
