#include <bits/stdc++.h>
using namespace std;

int genNum(int bits){
    int nums[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    random_shuffle(nums, nums + 8);
    int ans = 0;
    for (int i=0; i<bits; i++){
        ans += (1<<nums[i]);
    }
    return ans;
}

void print_int(int a){
    bitset<8> x(a);
    cout << x << endl;
}

int T;
int main(){
    // srand(time(NULL));
    cin >> T;
    for (int t=1; t<=T; t++){
        int iter = 0;
        int guess = 0;
        int numBits = 0;
        for (; iter<300; iter++){
            print_int(guess);
            cin >> numBits;
            if (numBits == 0) {
                break;
            }
            guess = genNum(numBits);
        }
        if (iter >= 300) return 0; // failed
    }
    return 0;
}