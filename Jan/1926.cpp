/*
https://www.acmicpc.net/problem/1926

17:51 ~ 18:22
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int paper[501][501];
bool visited[501][501];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { -1, 0, 1, 0 };

int bfs(int sy, int sx) {
	int size = 0;
	queue<pair<int, int>> qu;
	visited[sy][sx] = true;
	qu.push({ sy, sx });
	size = 1;
	while (!qu.empty()) {
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
			if (!visited[ny][nx] && paper[ny][nx] == 1) { // 2차원 배열의 원소에 접근할 때 인덱스 순서를 y,x로 지키자 
				visited[ny][nx] = true;
				size += 1;
				qu.push({ ny, nx });
			}
		}
	}
	return size;
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	int pictureCount = 0;
	int maxSize = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (paper[i][j] == 1 && !visited[i][j]) {
				maxSize = max(maxSize, bfs(i, j));
				pictureCount += 1;
			}
		}
	}
	printf("%d\n%d", pictureCount, maxSize);
	return 0;
}