/*
2 1 3 4 5
2 1 4 3 5
3 4 1 2 5
3 4 1 2 5


4 3 2 1 5
2 3 4 1 5
*/
#include <iostream>
#include <cstdio>
using namespace std;

int curBucket[101];
int lastBucket[101];

int main(void){
    int N, M;
    int i, j, start, end;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++){
        lastBucket[i] = i;
    }
    for(i = 1; i <= M; i++){
        scanf("%d %d", &start, &end);
        for(j = 1; j <= N; j++){
            curBucket[j] = lastBucket[j];
        }
        for(j = 0; j <= (end - start) / 2; j++){
            int temp = curBucket[start + j];
            curBucket[start + j] = curBucket[end - j];
            curBucket[end - j] = temp;
        }
        for(j = 1; j <= N; j++){
            lastBucket[j] = curBucket[j];
        }
    }
    for(int i = 1; i <= N; i++)
        printf("%d ", lastBucket[i]);
    return 0;
}