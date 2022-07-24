#include <bits/stdc++.h>
using namespace std;

vector <string> split(string str = "1,2,3,4,5,6") {
    vector<string> v;
 
    stringstream ss(str);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }
    
    return v;
}