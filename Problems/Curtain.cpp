#include <iostream>
using namespace std;
int main(){
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d\n", max(0, A-2*B));
    return 0;
}
