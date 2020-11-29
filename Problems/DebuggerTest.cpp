#include <iostream>

int gcd(int a, int b){
    while (b != 0){
        int c = b;
        b = a%b;
        a = c;
    }
    return a;
}

int main() {
    int a = 1232;
    int b = 18927346;
    int g = gcd(a, b);
    int l = a/g*b;
    printf("%d\n", l);
    return 0;
}