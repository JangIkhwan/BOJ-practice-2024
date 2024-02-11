/*
24-01-27 12:42

	a c a y k p
c	0 1 1 1 1 1 
a	1 1 2 2 2 2
p	1 1 2 2 2 3
c		
a
k
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string A, B;
int dp[1001][1001]; // dp[a][b] : A의 처음에서 a까지의 부분문자열과 B의 처음에서 b까지의 부분문자열에서 lcs의 길이
char result[1001];

void lcs() {
	int lcsLen = 0;
	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				lcsLen = max(lcsLen, dp[i][j]);
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	printf("%d\n", lcsLen);
	
	if (!lcsLen) {
		return;
	}
	/*int i, j;
	bool found = false;
	for (i = 1; i <= A.length(); i++) {
		for (j = 1; j <= B.length(); j++) {
			if (dp[i][j] == lcsLen && A[i - 1] == B[j - 1]) {
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}*/

	int i = A.length();
	int j = B.length();
	result[lcsLen] = '\0';
	while (lcsLen >= 0 && i >= 1 && j >= 1) {
		if (A[i - 1] == B[j - 1]) {
			result[--lcsLen] = A[i - 1];
			i--;
			j--;
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1]) {
				i--;
			}
			else {
				j--;
			}
		}
	}
	printf("%s", result);
}

int main(void) {
	cin >> A >> B;

	lcs();

	return 0;
}