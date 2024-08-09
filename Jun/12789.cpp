/*
 * 24-06-26, 20:28 ~  20:55
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int main(void){
    queue<int> qu;
    stack<int> st;
    int N;
    int i, no;
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &no);
        qu.push(no);
    }

    for(i = 1; i<= N; i++){
        if(!st.empty() && st.top() == i){
            st.pop();
        }
        else{
            while(!qu.empty() && qu.front() != i){
                st.push(qu.front());
                qu.pop();
            }
            if(!qu.empty()){
               qu.pop();
            }
            else{
                printf("Sad");
                return 0;
            }
        }
    }
    printf("Nice");
    return 0;
}