/*
24-01-26, 12:17~ 47
*/
#include <iostream>
using namespace std;

char s1[1001], s2[1001];
int resultLen;
char result[1001];
char tempLcs[1001];
int dp[1001][1001];

void lcs(int p1, int p2, int len) {
	if (p1 > strlen(s1) || p2 > strlen(s2)) {
		tempLcs[len] = '\0';
		if (resultLen < len - 1) {
			strcpy(result, tempLcs);
			resultLen = len - 1;
		}
	}

	while (s1[p1] != s2[p2]) {
		++p2;
	}
	if (s1[p1] == s2[p2]) {
		tempLcs[len] = s1[p1];
	}
	lcs(p1 + 1, p2 + 1, len + 1);
}

int main(void) {
	scanf("%s", s1);
	scanf("%s", s2);

	lcs();

	return 0;
}