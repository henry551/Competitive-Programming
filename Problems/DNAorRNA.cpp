#include <bits/stdc++.h>
using namespace std;

bool checkd(char x){
    return x == 'A' || x == 'C' || x == 'T' || x == 'G';
}

bool checkr(char x){
    return x == 'A' || x == 'C' || x == 'U' || x == 'G';
}

int N; string a;
int main() {
    scanf("%d", &N);
    cin >> a;
    bool d = true, r = true;
    for (int i=0; i<N; i++){
        if (!checkd(a[i])) d = false;
        if (!checkr(a[i])) r = false;
    }
    if (r && d) printf("both\n");
    else if (r) printf("RNA\n");
    else if (d) printf("DNA\n");
    else printf("neither\n");
    return 0;
}