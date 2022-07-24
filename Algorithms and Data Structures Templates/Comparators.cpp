#include <bits/stdc++.h>
using namespace std;

struct pii {
    int movie, shop;
    pii(){}
    pii (int movie, int shop) {
        this->movie = movie;
        this->shop = shop;
    }
};

struct cmp1 {
    bool operator() (const pii &a, const pii &b) const {
        if (a.movie != b.movie) return a.movie < b.movie;
        return a.shop < b.shop;
    }
};

set <pii, cmp1> shops; // Sorted from smallest to largest
priority_queue<pii, vector<pii>, cmp1> pq; // Note in C++ this is a max queue
priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq3; // min-heap 

void runMap() {
    shops.insert(pii(1,2));
    shops.insert(pii(3,-1));
}

void runPriorityQueue() {
    pq.push(pii(1,2));
    pq.push(pii(3,-1));
    pq.push(pii(2,8));
    pq.push(pii(2,5));
}

int main(){
    runMap();
    runPriorityQueue();
    for (auto it: shops){
        cout << it.movie << " " << it.shop << endl;
    }
    cout << endl;

    while (!pq.empty()) {
        pii a = pq.top();
        cout << a.movie << " " << a.shop << endl;
        pq.pop();
    }

    // inline comparators
    int v[] = { 9, 4, 7, 2, 5, 10, 11, 12, 1, 3, 6 };
    int* i1;
    i1 = min_element(v + 2, v + 9, [](int a, int b) {return a < b;});
    cout << *i1 << "\n";

    auto compare = [](pii a, pii b) { return a.movie < b.movie; };
    priority_queue<pii, std::vector<pii>, decltype(compare)> openSet(compare);
}