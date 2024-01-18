/*
24-01-18 12:19 ~ 36, 13:21 ~ 40, 15:20 ~ 15:43

예시 입력
i = 1
10 1 5 2 3

i = 2
1 5 2 3 10

i = 3
1 2 3 5 10


i = 1
2 3 4 1 5 6

2 3 1 4 5 6

2 1 3 4 5 6

1 2 3 4 5 6

i = 1
4 3 2 1 5

방법1.
B[i] : i번째 이전에 있으면서 i번째 값보다 큰 값의 수
B의 최댓값만큼 i를 반복하면 정렬상태가 되는 것으로 보임
시간제한을 만족하도록 구현하는 것이 어려움...

방법2. 
swap 연산이 이루어지지 않는 경우는 정렬된 경우임
swap이 이루어지면 원소 하나가 정렬되면서 일부 원소가 왼쪽으로 한칸 이동
가장 많이 왼쪽으로 이동한 원소의 이동 횟수가 곧 swap의 총 횟수가 됨
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> A;

int main(void) {
	int val, idx;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &val);
		A.push_back({ val, i });
	}

	sort(A.begin(), A.end());

	int maxBackStep = 0;
	for (int i = 0; i < A.size(); ++i) {
		int prevIdx = A[i].second;
		maxBackStep = max(maxBackStep, prevIdx - i);
	}
	printf("%d", maxBackStep + 1);

	return 0;
}
