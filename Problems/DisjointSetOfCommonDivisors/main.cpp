#include <iostream>
#include <cmath>
using namespace std;

bool prime[1000005];

long long gcd (long long A, long long B){
    while (A != 0){
        long long C = A;
        A = B % A;
        B = C;
    }
    return B;
}

void setup(long long N){
    fill(prime, prime+N, true);
    for (long long i=2; i<=N; i++){
        if (prime[i]){
            for (long long j=2*i; j<=N; j+=i){
                prime[j] = false;
            }
        }
    }
}

int main() {
    long long A, B;
    cin >> A >> B;
    long long c = gcd(A, B);
    setup((int) sqrt(c) + 5);
    long long tot = 0;

    long long g = (long long) sqrt(c) + 5;
    for (long long i=2; i<= g; i++){
        if (prime[i] && c % i == 0) {
            tot++;
            while (c % i  == 0){
                c /= i;
            }
        }
    }
    if (c != 1) tot++;
    tot++;
    cout << tot << endl;
    return 0;
}