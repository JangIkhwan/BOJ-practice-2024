#include <iostream>
using namespace std;

int sequence[10];

void f(int depth, int N, int M){
    if(depth == M + 1){
        for(int i = 1; i <= M; i++ ){
            printf("%d ", sequence[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= N; i++){
        if(i >= sequence[depth - 1]){
            sequence[depth] = i;
            f(depth + 1, N, M);
        }
    }
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    f(1, N, M);

    return 0;
}