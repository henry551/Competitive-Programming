#include <bits/stdc++.h>
using namespace std;
vector <int> a; //original array
vector <int> b; //LIS

set <int> st;
set <int>::iterator it;

// simple implementation (without returning actual sequence)
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> endpoint(n+1, INF);
    endpoint[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(endpoint.begin(), endpoint.end(), a[i]) - endpoint.begin();
        if (endpoint[j-1] < a[i])
            endpoint[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (endpoint[i] < INF)
            ans = i;
    }
    return ans;
}

//Stores LIS in b
//Time Complexity: O(nlogn)
//Space Complexity: O(n)
void LIS()
{
    //p is the parent vector and stores the location of the previous element of the LIS
    vector<int> p(a.size()); //initialize vector with 0s
    if (a.empty()) return;

    b.push_back(0); //originally, b stores the indices of LIS

    for (int i = 1; i < a.size(); i++)
    {
        if (a[b.back()] < a[i]) //if last element is larger
        {
            p[i] = b.back();
            b.push_back(i);
            continue;
        }

        //binary search to find minimum l such that a[i]<=a[b[l]]
        int l=0, r=b.size();
        int m;
        while (r-l>1){
            m = l+(r-l)/2;
            if (a[b[m]] <= a[i]) l=m;
            else r=m;
        }
        if (a[b[l]]!=a[i]) l++;

        //set new value of b
        if (a[i] < a[b[l]]) //ignore case when a[i]==a[b[l]]
        {
            if (l > 0) p[i] = b[l-1];
            b[l] = i;
        }
    }

    //b stores the LIS
    for (int i = b.size()-1, j = b.back(); i>=0 ; i--, j = p[j]) {
        b[i] = a[j];
    }
}

//Outputs size of LIS
//Time Complexity: O(nlogn)
//Space Complexity: O(n)
int LIS2(){
    for (int i=0; i<a.size(); i++){
        it = st.lower_bound(a[i]);
        if (it!=st.end()) st.erase(it);
        st.insert(a[i]);
    }
    return st.size();
}