/*
24-02-03 12:13 ~ 12:34

N = 2

0 1 2 3 4 5 6 7 8 9
--------
1 1 1 1 1 1 1 1 1 1
1 2 3 4 	

*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int N;
int dp[1001][10]; // dp[i][j] : 길이가 i일때, 맨 첫 자리가 j인 오르막 수의 갯수

void solve() {
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) { //
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k >= 0; k--) { //
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= 10007;
		}
	}
	int answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer += dp[N][i];
	}
	answer %= 10007; //
	printf("%d", answer);
}

int main(void) {
	scanf("%d", &N);
	solve();
	return 0;
}