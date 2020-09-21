#include <vector>
using namespace std;

vector<int> p;

void vectors() {
    //Time Complexity: O(n)
    //retains only one copy of each element
    //unique returns iterator to last element not removed
    //vector must be sorted
    p.resize(unique(p.begin(), p.end()) - p.begin());
}