/*
https://www.acmicpc.net/problem/2565

24-02-02 
<1차 시도>
13:07 ~ 13:12 14:39 ~ 15:09

A : 8 2 9 1 4 6 7 10
D : 1 1 2 1 2 3 4 5

<2차 시도>
17:19 ~ 17:48

풀이 과정
- 자르는 전선의 최소화하라는 것은 남아있는 전선의 수를 최대화하라는 것과 같음
따라서 총 전선의 수 - 남아있는 전선의 최대 갯수를 구하면 됨
- 남아있는 최대 전선의 수를 구하는 문제는 A의 번호를 오름차순으로 정렬했을 때, 
B의 번호가 오름차순인 부분 수열 중 길이가 최대인 수열을 구하는 문제로 바뀜
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> lines(101);
int dp[501]; // dp[i] : i번째 줄을 마지막으로 포함하여 연결할 수 있는 전기줄의 최대 갯수

int cutLines() {
	sort(lines.begin(), lines.begin() + N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (lines[j].second < lines[i].second) { 
				dp[i] = max(dp[i], dp[j]);  
			}
		}
		dp[i] += 1;
	}
	int maxConnect = 0;
	for (int i = 1; i <= N; i++) {
		maxConnect = max(maxConnect, dp[i]);
	}
	return N - maxConnect;
}

int main(void) {
	int a, b;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &a, &b);
		lines[i].first = a;
		lines[i].second = b;
	}
	printf("%d", cutLines());
	return 0;
}
