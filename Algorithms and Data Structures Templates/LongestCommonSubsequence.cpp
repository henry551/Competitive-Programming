#include <iostream>
#include <vector>
using namespace std;

vector<int> arr1;
vector<int> arr2;
int sz[205][205];
int length; //length of LCS
int lcs[205]; //array of lcs, stored from 0 to length-1

void LCS() {
    //finds length
    for (int i = 0; i <= arr1.size(); i++) {
        for (int j = 0; j <= arr2.size(); j++) {
            if (i == 0 || j == 0)
                sz[i][j] = 0;
            else if (arr1[i - 1] == arr2[j - 1])
                sz[i][j] = sz[i - 1][j - 1] + 1;
            else
                sz[i][j] = max(sz[i - 1][j], sz[i][j - 1]);
        }
    }

    int length = sz[arr1.size()][arr2.size()]; //length of LCS

    //generates LCS
    int i = arr1.size(), j = arr2.size();
    while (i > 0 && j > 0) {
        if (arr1[i - 1] == arr2[j - 1]) {
            lcs[length - 1] = arr1[i - 1];
            i--;
            j--;
            length--;
        } else if (sz[i - 1][j] > sz[i][j - 1]) i--;
        else j--;
    }
}