#include <iostream>
using namespace std;
int arr[55];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);
    long long sum = 0;
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            sum += arr[i]*arr[j];
        }
    }
    printf("%lld\n", sum);
    return 0;
}