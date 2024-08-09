#include <iostream>
using namespace std;

const int MAX = 100001;
int N, K;
int minTime[MAX];

int main(void){
    scanf("%d %d", &N, &K);
    
    
    minTime[i] = minTime[i - 1] + 1;
    if(minTime[i / 2] > 0)
        minTime[i] = min(minTime[i], minTime[i / 2] + 1);
    if(minTime[i - 1] > 0){
        
    }
    return 0;
}