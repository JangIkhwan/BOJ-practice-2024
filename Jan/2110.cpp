/*
https://www.acmicpc.net/problem/2110

24-01-16 18:27 ~ 18:45, 21:56 ~ 22:11

풀이과정
- 최적화문제를 결정문제로 푸는 방법을 사용해보려고 함. 
- 최소거리의 최댓값을 이분탐색을 통해 찾는 것임.
- 주어진 최소거리가 될 수 있는지는 별도의 함수를 통해서 판정하면 됨.

풀이과정 중 어려웠던 점
- 반례를 찾는 것이 어려웠음. 그래서 게시판에 있는 반례를 참고했으나 이상이 없었음.
그래서 무작위로 값을 넣다보니 우연히 반례를 발견함.
다음 입력에 대해서 음수 값이 나오는 것을 확인함. 

3 3 
999999
100000
100001

코드를 다시 보니 배열을 정렬하는 범위를 잘못 설정했음. 그래서 이를 수정함.

- 이분탐색을 사용할 때 lo, hi값을 잘 설정하지 못해서 결과값이 잘못 나왔음.
내가 사용하는 이분 탐색의 경우 lo, hi를 범위의 최솟값 - 1, 범위의 최솟값 + 1로 설정하는 것이 좋음

새롭게 알게된 점
- 최적화문제를 결정문제로 푸는 방법을 매개변수 탐색이라고도 부르는 것으로 보임
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
int houses[200001];

bool install(int minDist) {
	int APtoInstall = C - 1;
	int dist = 0;
	for (int i = 2; i <= N; i++) {
		dist += houses[i] - houses[i - 1];
		if (dist >= minDist) {
			APtoInstall -= 1;
			if (APtoInstall == 0) {
				return true;
			}
			dist = 0;
		}
	}
	return false;
}

int maxOfNearestDist() {
	int hi = houses[N] - houses[1] + 1;
	int lo = hi;
	for (int i = 2; i <= N; i++) {
		lo = min(lo, houses[i] - houses[i - 1]); // 내가 작성한 이분탐색에 맞게 lo 값을 제대로 잡아야 함
	}
	lo -= 1; 
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (install(mid)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return lo;
}

int main(void) {
	scanf("%d %d", &N, &C);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &houses[i]);
	}

	sort(houses + 1, houses + N + 1); // 정렬하는 배열의 범위에 주의하자
	
	// sort(houses, houses + N); 
	// 내가 배열에 저장한 범위는 1에서 N이기 때문에 위와 같이 정렬하면 안됨

	printf("%d\n", maxOfNearestDist());

	return 0;
}

/