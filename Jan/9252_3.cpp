/*
24-01-26 23:35 ~ 25:10
¹Ý·Ê

ABCABCABC
ACABCC
4
ABCC

½ÇÆÐ
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

string A, B;
int dp[1001][1001];
char result[1001];

void lcs() {
	int lcsLen = 0;
	bool found;
	//int prevJ = 0;
	for (int i = 1; i <= A.length(); i++) {
		found = false;
		for (int j = 1; j <= B.length(); j++) {
			//if (!found && j > prevJ && A[i - 1] == B[j - 1]) {
			if (!found && A[i - 1] == B[j - 1] && j >= lcsLen && dp[i - 1][j] == lcsLen) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				result[lcsLen] = A[i - 1];
				lcsLen++;
				//prevJ = j;
				found = true;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d\n", lcsLen);
	if (lcsLen) {
		result[lcsLen + 1] = '\0';
		printf("%s", result);
		/*int i = 1;
		int len = 1;
		bool finished = false;
		for (; i <= A.length(); i++) {
			for (int j = 1; j <= B.length(); j++) {
				if (dp[i][j] == len && dp[i - 1][j -1] == len - 1) {
					printf("%c", A[i - 1]);
					len++;
					if (len >= lcsLen + 1) {
						finished = true;
					}
					break;
				}
			}
			if (finished) {
				break;
			}
		}*/
	}
}

int main(void) {
	cin >> A;
	cin >> B;

	lcs();

	return 0;
}