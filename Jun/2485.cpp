/*
* 24-06-28
* 출발점에서 각 지점 사이의 거리의 최대공약수를 간격으로 설정하면 된다.
* 
* 유클리드 호제법 : 최대공약수를 빠르게 구하는 알고리즘
* - 시간 복잡도는 O(max(log a, log b))이다.
* - a >= 2r이고 ab >= 2br 이므로 매번 값이 2배 정도 줄어든다.
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
   vector<int> dists, trees;
    int N, cur, prev;
    scanf("%d", &N);
    scanf("%d", &prev);
    trees.push_back(prev);
    for(int i = 1; i < N; i++){
        scanf("%d", &cur);
        trees.push_back(cur);
        dists.push_back(cur - prev);
        prev = cur;
    } 
    
    sort(dists.begin(), dists.end());
    int a, b, r;
    b = dists[0];
    for(int i = 1; i < N - 1; i++){
        a = dists[i];
        while(true){
            r = a % b;
            if(r == 0){
                break;
            }
            a = b;
            b = r;
        }
    }
    
    printf("%d\n", (trees[N -1] - trees[0]) / b + 1 - N);
}

// int main(void){
//     vector<int> trees;
//     int N, tree;
//     scanf("%d", &N);
//     for(int i = 0; i < N; i++){
//         scanf("%d", &tree);
//         trees.push_back(tree);
//     }

//     int shortestDist = 1000000001;
//     for(int i = 0; i < N - 1; i++){
//         int dist = trees[i + 1] - trees[i];
//         if(dist < shortestDist){
//             shortestDist = dist;
//         }
//     }
//     int answer = 1;
//     for(int dist = shortestDist; dist >= 1; dist--){
//         int includingCount = 1;
//         for(int i = 1; i < N; i++){
//             if((trees[i] - trees[0]) % dist == 0){
//                 includingCount += 1;
//             }
//         }
//         if(includingCount == N) {
//             answer = (trees[N -1] - trees[0])/ dist + 1 - N;
//             break;
//         }
//     }
//     printf("%d", answer);
//     return 0;
// }