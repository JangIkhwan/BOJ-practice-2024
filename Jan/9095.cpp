#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int dp[12]; // i를 합으로 나타낼 수 있는 경우의 수

int main(void) {
	int T, N;
	scanf("%d", &T);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;   // 1 1 1, 1 2, 2 1, 3
	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (T--) {
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
	return 0;
}