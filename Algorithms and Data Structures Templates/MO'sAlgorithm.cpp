#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;

int block;
int n, m; //n stores number of elements, m stores number of queries
int arr[205];
pii query[205]; //first -> left bound, second -> right bound
int ans[205];

//O(mlogm)
bool compare(pii a, pii b) {
    if (a.first/block != b.first/block) return a.first/block < b.first/block;
    return a.second < b.second;
}

//O((m+n)sqrt(n)+mlogm)
void queryResults() {
    block = (int)sqrt(n);
    sort(query, query + m, compare);

    int currL = 0, currR = -1;
    int currSum = 0;

    for (int i=0; i<m; i++) {
        int L = query[i].first, R = query[i].second;
        while (currL < L) { currSum -= arr[currL]; currL++; }
        while (currL > L) { currL--; currSum += arr[currL]; }
        while (currR < R) { currR++; currSum += arr[currR]; }
        while (currR > R) { currSum -= arr[currR]; currR--; }
        ans[i]=currSum;
    }
}