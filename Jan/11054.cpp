/*
24-01-29 23:05 ~ 23:45


L : 1 2 2 2 3 3 4 4 4

1 1, 4 3

R : 4 3 3 3 3 3 3 2 1                
1 1
2 2
5 3
4 3
4 3
4 3
4 3
5 4
4
*/
#include <iostream>
using namespace std;

int N;
int A[1001];
int incLen[1001]; // i까지 범위까지 가장 긴 증가 수열
int decLen[1001];

void solve() {
	for (int i = 1; i <= N; i++) {
		int length = 0;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i] && incLen[j] > length) {
				length = incLen[j];
			}
		}
		incLen[i] = length + 1;
	}
	for (int i = N; i <= 1; i--) {
		int length = 0;
		for (int j = N; j > i; j++) {
			if (A[j] < A[i] && incLen[j] > length) {
				length = decLen[j];
			}
		}
		decLen[i] = length + 1;
	}
	for(int )
}

int main(void) {
	return 0;
}

/*
*void solve() {
	for (int i = 1; i <= N; i++) {
		int length = 0;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i] && incLen[j] > length) {
				length = incLen[j];
			}
		}
		incLen[i] = length + 1;
	}
	for (int i = N; i <= 1; i--) {
		int length = 0;
		for (int j = N; j > i; j++) {
			if (A[j] < A[i] && incLen[j] > length) {
				length = decLen[j];
			}
		}
		decLen[i] = length + 1;
	}
	for(int )
}/