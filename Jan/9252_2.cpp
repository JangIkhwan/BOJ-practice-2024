/*
24-01-26 16:54 ~ 17:24
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string a, b;
int dp[1001][1001];
char result[1001];
char temp[1001];

int lcs(int ia, int ib, int depth) {
	if (ia > a.length() || ib > b.length()) {
		temp[depth] = '\0';
		if (strlen(temp) > strlen(result)) {
			strcpy(result, temp);
		}
		return depth - 1;
	}
	int& ret = dp[ia][ib];
	for (; ia <= a.length(); ++ia) {
		for (; ib <= b.length(); ++ib) {
			if (a[ia] == b[ib]) {
				temp[depth];
				ret = max(ret, lcs(ia, ib, depth + 1));
			}
		}
	}
	return ret;
}

int main(void) {
	return 0;
}