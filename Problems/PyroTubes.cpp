#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;
vector <int> light;
unordered_set <int> possible;
int N = 0;
int main() {
    int a;
    cin >> a;
    while (a != -1) {
        N++;
        light.push_back(a);
        cin >> a;
    }

    for (int i=0; i<N; i++){
        possible.clear();
        for (int j=0; j<18; j++){
            possible.insert(light[i]^(1<<j));
        }
        for (int j=1; j<18; j++){
            for (int k=0; k<j; k++){
                possible.insert(light[i] ^ (1<<j) ^ (1<<k));
            }
        }
        int cont = 0;
        for (auto it: possible){
            if (light[i] < it && (light[lower_bound(light.begin()+i, light.end(), it) - light.begin()] == it))
                cont++;
        }
        printf("%d:%d\n", light[i], cont);
    }
    return 0;
}
