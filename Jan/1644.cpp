/*
24-01-28 18:11 ~ 18:55

풀이과정
- 소수인지 판정하기 위해서 에라토스테네스의 체를 이용
- 연속된 소수의 합을 구하기 위해서 투 포인터 이용

기억할 점
- 투 포인터를 이용한 연속합 구하기 알고리즘 복습 필요
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

int N;
bool prime[4000001];

void sumPrime() {
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= N; i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= N; j += i) {
				prime[j] = false;
			}
		}
	}
	int cnt = 0;
	int left = 2;
	int right = 2;
	int sum = 2;
	while (left <= right && right <= N) {
		if (sum < N) {
			right += 1;
			while (right <= N && !prime[right]) {
				right += 1;
			}
			if (prime[right]) {
				sum += right;
			}
		}
		else if (sum > N) {
			sum -= left;
			left += 1;
			while (left <= N && !prime[left]) {
				left += 1;
			}
		}
		else {
			cnt++;
			sum -= left;
			left += 1;
			while (!prime[left]) {
				left += 1;
			}
		}
	}
	printf("%d", cnt);
}

int main(void) {
	scanf("%d", &N);
	
	sumPrime();
	
	return 0;
}
