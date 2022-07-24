#include <bits/stdc++.h>
using namespace std;

class lambda {
public:
    vector <int> vect = {0,1};
    vector <int> asdf = {2,0};
    lambda(){}
    
    function<bool(int,int)> cmp = [this](const int &a, const int &b){
        return asdf[a] > asdf[b];
    };
    
    void sortVect() {
        sort(vect.begin(), vect.end(), cmp);
        for_each(vect.begin(), vect.end(), [](int a){
           printf("%d ", a);
        });
        printf("\n");
    }
};

int main()
{
    lambda l = lambda();
    l.sortVect();
    return 0;
}
