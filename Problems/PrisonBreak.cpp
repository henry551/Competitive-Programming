#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, r, c;
int main() {
    cin >> t;
    for (int i=0; i<t; i++){
        scanf("%d %d %d %d", &n, &m, &r, &c);
        int max_x = max(n-r, r-1);
        int max_y = max(m-c, c-1);
        printf("%d\n", max_x + max_y);
    }
    int a = 3;
    int b = 4;
    vector <int> q;
    for (int i=0; i<10; i++){
        q.push_back(3);
    }
    cout << q.front() << endl;
    return 0;
}
