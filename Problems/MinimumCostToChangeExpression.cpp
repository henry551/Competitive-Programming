#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int INF = 0x3f3f3f3f;

struct Node {
    char symbol;
    int minVal[2];
    int left; int right;
    Node(){};
    Node(char symbol) {
        this->symbol = symbol;
        left = -1;
        right = -1;
        minVal[0] = minVal[1] = INF;
    }
};

class Solution {
private:
    Node nodes[100005];
    char operations[2] = {'|', '&'};

    int calculate(int first, char op, int second) {
        if (op == '|') return first | second;
        else return first & second;
    }

    void solve(int v, int p) {
        char symbol = nodes[v].symbol;
        if (symbol == '1' || symbol == '0') {
            nodes[v].minVal[symbol - '0'] = 0;
            nodes[v].minVal[!(symbol - '0')] = 1;
            return;
        }
        int left = nodes[v].left;
        int right = nodes[v].right;
        solve(left, v);
        solve(right, v);

        int start = 0;
        if (symbol == '&') {
            start = 1;
        }

        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++) {
                for (int cur=0; cur<2; cur++){
                    int val = calculate(i, operations[(cur+start) % 2], j);
                    // cout << val << " " << i << " " << operations[(cur+start)%2] << " " << j << " " << nodes[left].minVal[i] + nodes[right].minVal[j] + cur << endl;
                    nodes[v].minVal[val] = min(nodes[v].minVal[val], nodes[left].minVal[i] + nodes[right].minVal[j] + cur);
                }
            }
        }        
    }

public: 
    int minOperationsToFlip(string expression) {
        map <int,int> mp;
        int idx = 0;
        for (int i=0; i<expression.length(); i++){
            if (expression[i] == '1' || expression[i] == '0' || expression[i] == '&' || expression[i] == '|') {
                mp[i] = idx;
                nodes[idx] = Node(expression[i]);
                idx++;
            }
        }
        
        int num = 0, op = 1, bracket = 2;
        
        stack <pii> st;
        int sz = 0;
        int top = -1;
        int prev = -1;
        for (int i=0; i<expression.length(); i++){
            char c = expression[i];
            if (c == '(') {
                st.push({i,bracket});
                prev = top;
                top = bracket;
                sz++;
            } else if (c == ')'){
                pii temp = st.top();
                st.pop();
                st.pop();
                prev = st.empty() ? -1 : st.top().second;
                top = num;
                st.push(temp);
                sz--;
            } else if (c == '|' || c == '&') {
                st.push({i,op});
                prev = top;
                top = op;
                sz++;
            } else {
                st.push({i,num});
                prev = top;
                top = num;
                sz++;
            }
            while (sz >= 3 && top == num && prev == op) {
                pii a, b, c;
                c = st.top();
                st.pop();
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                nodes[mp[b.first]].left = mp[a.first];
                nodes[mp[b.first]].right = mp[c.first];
                prev = st.empty() ? -1 : st.top().second;
                top = num;
                st.push({b.first, num});
                sz -= 2;
            }
        }

        int root = mp[st.top().first];
        solve(root, -1);
        // for (int i=0; i<idx; i++){
        //     cout << i << ": " << nodes[i].symbol << " " << nodes[i].left << " " << nodes[i].right << " " << nodes[i].minVal[0] << " " << nodes[i].minVal[1] << endl;
        // }

        return max(nodes[root].minVal[0], nodes[root].minVal[1]);
    }
};

class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};

int main(){
    string exp;
    getline(cin, exp);
    Solution sol;
    cout << sol.minOperationsToFlip(exp) << endl;

    return 0;
}