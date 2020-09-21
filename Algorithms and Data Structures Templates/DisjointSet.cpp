#include <iostream>
using namespace std;

int arr[200];
int ranking[200];

//n is the number of elements
//Time Complexity: O(n)
void initialize(int n){
    for (int i=0; i<n; i++){
        arr[i]=i;
        ranking[i]=1;
    }
}

//Time Complexity: O(1) approximately
int findParent(int i){
    return arr[i]==i ? i : arr[i]=findParent(arr[i]);
}

//Time Complexity: O(1) approximately
void unionJoin(int a, int b){
    int x = findParent(a);
    int y = findParent(b);
    if (ranking[x]<ranking[y]) arr[x]=y;
    else if (ranking[x]>ranking[y]) arr[y]=x;
    else{
        arr[x]=y;
        ranking[y]++;
    }
}