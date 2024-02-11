/*
24-02-11 23:10 ~ 23:37
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1001];
int leftMaxLen[1001]; // i번째까지 포함하는 바이토닉 수열의 길이 중 최대 
int rightMaxLen[1001]; // i번째부터 포함하는 바이토닉 수열의 길이 중 최대 

int solve() {
	for (int i = 1; i <= N; i++) {
		int temp = 1;
		for (int j = 1; j < i; j++) {
			if(A[j] < A[i])
				temp = max(temp, leftMaxLen[j] + 1);
		}
		leftMaxLen[i] = temp;
	}
	for (int i = N; i >= 1; i--) {
		int temp = 1;
		for (int j = N; j > i; j--) {
			if (A[i] > A[j])
				temp = max(temp, rightMaxLen[j] + 1);
		}
		rightMaxLen[i] = temp;
	}
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		int left = leftMaxLen[i];
		int right = rightMaxLen[i];
		ret = max(ret, max(left + right - 1, max(left, right)));
	}
	return ret;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	printf("%d", solve());
	return 0;
}