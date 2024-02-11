#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int dp[1001];

int main(void) {
	int N;
	scanf("%d", &N);

	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1];
		if (i - 2 == 0) {
			dp[i] += 2;
		}
		else {
			dp[i] += dp[i - 2] * 2;
		}
		dp[i] %= 10007;
	}
	printf("%d", dp[N]);
	return 0;
}
