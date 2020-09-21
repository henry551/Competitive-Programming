#include <iostream>
#include <vector>
using namespace std;
typedef pair <int,int> pii;
struct piii{
    int first, second, third;
};
int arr[30];
vector <int> group;
pii two[30];
piii three[30];

bool compare(piii l, piii r){
    return l.first < r.first;
}

void testSort(){
    sort(arr, arr+30);
    sort(group.begin(), group.end());
    sort(group.begin(), group.begin()+3);

    sort(arr, arr+30, greater<int>()); //sort in reverse order

    sort(two, two+30); //sorts based on first (not second)

    sort(three, three+30, compare); //sorts based on compare function
}

