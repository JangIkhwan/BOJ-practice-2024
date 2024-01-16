/*
https://www.acmicpc.net/problem/2110

24-01-16 18:27 ~ 18:45, 21:56 ~ 22:11

Ǯ�̰���
- ����ȭ������ ���������� Ǫ�� ����� ����غ����� ��. 
- �ּҰŸ��� �ִ��� �̺�Ž���� ���� ã�� ����.
- �־��� �ּҰŸ��� �� �� �ִ����� ������ �Լ��� ���ؼ� �����ϸ� ��.

Ǯ�̰��� �� ������� ��
- �ݷʸ� ã�� ���� �������. �׷��� �Խ��ǿ� �ִ� �ݷʸ� ���������� �̻��� ������.
�׷��� �������� ���� �ִٺ��� �쿬�� �ݷʸ� �߰���.
���� �Է¿� ���ؼ� ���� ���� ������ ���� Ȯ����. 

3 3 
999999
100000
100001

�ڵ带 �ٽ� ���� �迭�� �����ϴ� ������ �߸� ��������. �׷��� �̸� ������.

- �̺�Ž���� ����� �� lo, hi���� �� �������� ���ؼ� ������� �߸� ������.
���� ����ϴ� �̺� Ž���� ��� lo, hi�� ������ �ּڰ� - 1, ������ �ּڰ� + 1�� �����ϴ� ���� ����

���Ӱ� �˰Ե� ��
- ����ȭ������ ���������� Ǫ�� ����� �Ű����� Ž���̶�� �θ��� ������ ����
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
		lo = min(lo, houses[i] - houses[i - 1]); // ���� �ۼ��� �̺�Ž���� �°� lo ���� ����� ��ƾ� ��
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

	sort(houses + 1, houses + N + 1); // �����ϴ� �迭�� ������ ��������
	
	// sort(houses, houses + N); 
	// ���� �迭�� ������ ������ 1���� N�̱� ������ ���� ���� �����ϸ� �ȵ�

	printf("%d\n", maxOfNearestDist());

	return 0;
}

/