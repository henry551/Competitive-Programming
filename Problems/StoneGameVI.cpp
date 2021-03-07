#include <bits/stdc++.h>
using namespace std;

struct pf{
    int first, second, third, fourth;
};

struct compare1{
    bool operator()(const pf& lhs, const pf& rhs){
        {
            if (lhs.first != rhs.first) return lhs.first < rhs.first;
            if (lhs.second != rhs.second) return lhs.second < rhs.second;
            if (lhs.third != rhs.third) return lhs.third > rhs.third;
            return lhs.fourth > rhs.fourth;
        }
    }
};

struct compare2{
    bool operator()(const pf& lhs, const pf& rhs){
        {
            if (lhs.first != rhs.first) return lhs.first < rhs.first;
            if (lhs.third != rhs.third) return lhs.third < rhs.third;
            if (lhs.second != rhs.second) return lhs.second > rhs.second;
            return lhs.fourth > rhs.fourth;
        }
    }
};

int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    priority_queue <pf, vector<pf>, compare1> a;
    priority_queue <pf, vector<pf>, compare2> b;
    int n = aliceValues.size();
    vector <bool> vis(n, false);
    for (int i=0; i<n; i++){
        pf val;
        val.first = aliceValues[i]+bobValues[i];
        val.second = aliceValues[i];
        val.third = bobValues[i];
        val.fourth = i;
        a.push(val);

        pf val2;
        val2.first = aliceValues[i]+bobValues[i];
        val2.second = aliceValues[i];
        val2.third = bobValues[i];
        val2.fourth = i;
        b.push(val2);
    }

    int tot = 0;
    for (int i=0; i<n; i++){
        if (i%2==0){
            while (!a.empty() && vis[a.top().fourth]){
                // cout << "wut" << endl;
                a.pop();
            }
            pf t = a.top();
            a.pop();
            // cout << t.first << " a " << t.second << " " << t.third << " " << t.fourth << endl;
            vis[t.fourth] = true;
            tot += t.second;
        } else {
            while (!b.empty() && vis[b.top().fourth]){
                // cout << "tf" << endl;
                b.pop();
            }
            pf t = b.top();
            b.pop();
            // cout << t.first << " b " << t.second << " " << t.third << " " << t.fourth << endl;
            vis[t.fourth] = true;
            tot -= t.third;
        }
    }
    if (tot > 0) return 1;
    if (tot == 0) return 0;
    else return -1;
}

int main(){
    int n;
    cin >> n;
    vector <int> a;
    vector <int> b;
    for (int i=0; i<n; i++){
        int p, q;
        cin >> p >> q;
        a.push_back(p);
        b.push_back(q);
    }

    cout << stoneGameVI(a, b) << endl;
    return 0;
}