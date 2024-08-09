#include <iostream>
#include <cmath>
using namespace std;

void cantor(int n){
    if(n == 0) {
        printf("-");
        return;
    }
    cantor(n - 1);
    for(int i = 0; i < pow(3, n - 1); i++){
        printf(" ");
    }
    cantor(n - 1);
}

int main(void){
    int N;
    while(scanf("%d", &N) != EOF){
        cantor(N);  
        printf("\n");  
    }
    return 0;
}