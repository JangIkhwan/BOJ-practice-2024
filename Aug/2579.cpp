/*
00:21 ~ 
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int scores[301];

int dp[301][2];

void f(){
    dp[1][0] = scores[1];
    dp[1][1] = scores[1];
    for(int stair = 2; stair <= N; stair++){
        dp[stair][0] = dp[stair - 1][1] + scores[stair];
        dp[stair][1] = 0;
        if(stair >= 3){
            dp[stair][1] = max(dp[stair][1], dp[stair - 2][0] + scores[stair]);
            dp[stair][1] = max(dp[stair][1], dp[stair - 2][1] + scores[stair]);
        }
    }
    printf("%d", max(dp[N][0], dp[N][1]));
}

int main(void){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &scores[i]);
    }
    f();
    return 0;
}