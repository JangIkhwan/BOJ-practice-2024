#include <iostream>
#include <cstdio>
using namespace std;

long long fibo(int n){
    if(n == 0) return 1;
    return n * fibo(n - 1);
}

int main(void){
    int N;
    scanf("%d", &N);
    printf("%lld\n", fibo(N));
    return 0;
}