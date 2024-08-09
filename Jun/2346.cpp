/*
 * 24-06-26, 21:03 ~ 21:24
*/
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int shiftStep[1001];

int main(void){
    int N;
    deque<int> dq;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &shiftStep[i]);
        dq.push_back(i);
    }

    for(int i = 1; i <= N; i++){
        int removedBalloon = dq.front();
        dq.pop_front();
        printf("%d ", removedBalloon);
        
      
        if(shiftStep[removedBalloon] < 0){
            for(int j = 1; j <= -shiftStep[removedBalloon]; j++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else{
            for(int j = 1; j < shiftStep[removedBalloon]; j++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
    return 0;
}