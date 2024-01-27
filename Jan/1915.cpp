/*
24-01-27 17:19 ~ 18:03

풀이 과정
- 정사각형의 길이를 구하면 넓이를 알 수 있음
- 1~i, 1~j 범위에서 (i, j)칸을 포함하는 큰 정사각형을 S(i,j)라고 하자.
그러면 S(i,j)는 S(i-1, j), S(i-1,j-1), S(i. j-1)의 부분으로 구성됨. 
또한 큰 정사각형의 길이는 이 3개의 정사각형 중 가장 작은 정사각형의 길이에 
1을 더한 것임
- dp[i][j]를 1~i, 1~j 범위에서 (i, j)를 포함하는 가장 큰 정사각형 길이라고 
하면, 점화식은 다음과 같음.

(i,j)가 1이면, dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1
(i,j)가 0이면, dp[i][j] = 0

입력
===
1000
0011
0011
0110

1000
0011
0012
0110

===
1110
1110
1110
1010

1110
1220
1230
1010

1110
1100
1010
0000
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int N, M;
short map[1001][1001];
int dp[1001][1001]; // dp[i][j] : 1~i, 1~j 범위에서 (i, j)를 포함하는 정사각형 길이

void square() {
	int maxWidth = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 1) {
				int ml = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])); // 정사각형의 길이 중 최솟값 구하기
				if (ml == 0){
					dp[i][j] = 1;  // 최소값이 0이면 가장 큰 정사각형의 길이는 1
				}
				else {
					dp[i][j] = ml + 1; // 최소값이 가장큰 정사각형의 길이
				}
				maxWidth = max(maxWidth, dp[i][j]);
			}
		}
	}
	printf("%d", maxWidth * maxWidth); // 넓이 출력
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	square();
	return 0;
}