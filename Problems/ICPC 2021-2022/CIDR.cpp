#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll nums[65540];
int main(){
    cin >> N;
    for (int i=0; i<N; i++){
        string ip;
        cin >> ip;
        istringstream iss(ip);
        vector<int> tokens;
        string token;
        while (std::getline(iss, token, '.')) {
            if (!token.empty())
                tokens.push_back(stoi(token));
        }
        long num = 0;
        for (int j=0; j<tokens.size(); j++){
            num <<= 8L;
            num += tokens[j];
        }
        nums[i] = num;
    }

    int highestDiff = 0;
    for (ll i=0; i<32; i++){
        int power = (1LL<<i);
        for (int j=0; j<N-1; j++){
            if ((nums[j] & power) != (nums[j+1] & power)){
                highestDiff = i+1;
                break;
            }
        }
    }
    cout << (32 - highestDiff) << endl;

    // for (int i=0; i<N; i++){
    //     bitset<64> x(nums[i]);
    // }
    return 0;
}