/*
https://kih0902.tistory.com/31
*/
#include <iostream>
using namespace std;

int A, B, C, D;

int main(void){
    scanf("%d %d %d %d", &A, &B, &C, &D);
    long long num1 = A;
    int b = B;
    while(b > 0){
        b /= 10;
        num1 *= 10;
    }   
    num1 += B;
    long long num2 = C;
    int d = D;
    while(d > 0){
        d /= 10;
        num2 *= 10;
    }
    num2 += D;
    long long sum = num1 + num2;
    printf("%lld", sum);

    return 0;
}