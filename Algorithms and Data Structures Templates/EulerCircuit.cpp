#include <bits/stdc++.h>
using namespace std;

vector<int> edge[205];
int n, m; //vertices, edges

// Time Complexity: O(m+n)
void Hierholzers(){
    if (n == 0) return;
  
    stack<int> st;
    vector<int> circuit;
  
    st.push(0);
  
    while (!st.empty()) {
        int v = st.top();
        if (edge[v].size()) {
            int next_v = edge[v].back();
            edge[v].pop_back();
            st.push(next_v);
        } else {
            circuit.push_back(v);
            st.pop();
        }
    }
  
    for (int i=circuit.size()-1; i>=0; i--) {
        cout << circuit[i];
        if (i) cout<<" -> ";
    }
}
  
int main() {
    n = 3, m = 3;
    edge[0].push_back(1);
    edge[1].push_back(2);
    edge[2].push_back(0);
    Hierholzers();
    cout << endl;
  
    fill(edge, edge+n, vector<int>(0));
    n = 7, m = 10;
    edge[0].push_back(1);
    edge[0].push_back(6);
    edge[1].push_back(2);
    edge[2].push_back(0);
    edge[2].push_back(3);
    edge[3].push_back(4);
    edge[4].push_back(2);
    edge[4].push_back(5);
    edge[5].push_back(0);
    edge[6].push_back(4);
    Hierholzers();
    cout << endl;
  
    return 0;
}