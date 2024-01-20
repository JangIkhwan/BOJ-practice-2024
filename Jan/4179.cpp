/*
< 1차시도 >
24-01-18 17:13 ~ 18:40

< 2차시도 >
24-01-20 10:11~ 10:59

문제점
- 메모리 초과..
- 이유는 bfs에서 큐에 정점을 삽입 전에 방문처리를 하지 않아서 
같은 정점이 중복삽입되기 때문임.

< 3차시도 >
24-01-20 22:00 ~ 23:13

풀이과정
- bfs를 통해서 불과 지훈 각각을 주어진 맵에서 이동시킴.
이동할 때마다 걸린 시간을 배열에 저장함.
- 둘의 이동시간을 비교해서 지훈이 가장자리에 도달하는 최소시간을 구하면 됨.
- 최소시간도 bfs를 통해서 구함.

문제점
- 61%에서 통과되지 않음
- 반례를 찾아냄. 불이 도달하지 못하는 곳에서 fire[]는 0인데, 
check의 조건식에 jihoon[ny][nx] >= fire[ny][nx]만 있으면 
지훈이 이동할 수 있음에도 이를 제외하게 됨. 그래서 fire[]가
0이어도 이동할 수 있도록 조건식을 수정함.

입력
5 5
#####
#J#F#
#.#.#
#.#.#
#.#.#

출력
00000
01000
02000
03000
04000


00000
00010
00020
00030
00040
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

int R, C;
bool wall[1001][1001];
int jihoon[1001][1001];
int fire[1001][1001];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
bool visited[1001][1001];

// 디버깅용
//void printArr(int a[][1001]) {
//	for (int y = 1; y <= R; y++) {
//		for (int x = 1; x <= C; x++) {
//			printf("%d", a[y][x]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

void bfs(queue<pair<int, pair<int, int>>>& qu, int visited[1001][1001]) {
	while (!qu.empty()) {
		int lapse = qu.front().first;
		int y = qu.front().second.first;
		int x = qu.front().second.second;
		qu.pop();
		for (int direct = 0; direct < 4; direct++) {
			int ny = y + dy[direct];
			int nx = x + dx[direct];
			if (ny > R || ny < 1 || nx > C || nx < 1) continue;
			if (wall[ny][nx]) continue;
			if (visited[ny][nx] > 0) continue;
			visited[ny][nx] = lapse; //  bfs를 구현할 때 정점을 방문처리 후에 큐에 삽입해야 중복 삽입이 안됨. 그리하여 메모리 초과 해결.
			qu.push({ lapse + 1, {ny, nx} });
		}
	}
}

int check(int sy, int sx) {
	queue<pair<int, int>> qu;
	visited[sy][sx] = true; //
	qu.push({ sy, sx });
	while (!qu.empty()) {
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();
		if (y == 1 || y == R || x == 1 || x == C) {
			return jihoon[y][x];
		}
		for (int direct = 0; direct < 4; direct++) {
			int ny = y + dy[direct];
			int nx = x + dx[direct];
			if (ny > R || ny < 1 || nx > C || nx < 1) continue;
			if (visited[ny][nx]) continue;
			if (jihoon[ny][nx] <= 0 || (fire[ny][nx] > 0 && jihoon[ny][nx] >= fire[ny][nx])) continue;  // 불이 도달할 수 없는 곳에서도 이동 가능함을 생각해야 했음
			visited[ny][nx] = true; // bfs를 구현할 때 정점을 방문처리 후에 큐에 삽입해야 중복 삽입이 안됨
			qu.push({ ny, nx });
		}
	}
	return -1;
}

int main(void) {
	int jy, jx;
	queue <pair<int, pair<int, int>>> jQu, fQu;
	char cell;
	scanf("%d %d", &R, &C);
	getchar();              // 여러줄로 이루어진 입력으로부터 문자를 입력받을 때는 엔터키를 지워야 함
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			scanf("%c", &cell);
			if (cell == '#') {
				wall[y][x] = true;
			}
			else if (cell == 'J') {
				jQu.push({ 2, { y, x } });
				jy = y;
				jx = x;
				jihoon[y][x] = 1; // 
			}
			else if (cell == 'F') {
				fQu.push({ 2, { y, x } });
				fire[y][x] = 1; //
			}
		}
		getchar();
	}

	bfs(jQu, jihoon);
	bfs(fQu, fire);

	// 디버깅용
	//printArr(jihoon);
	//printf("\n");
	//printArr(fire);
	//printf("\n");

	int answer = check(jy, jx);
	if (answer != -1) {
		printf("%d", answer);
	}
	else {
		printf("IMPOSSIBLE");
	}

	return 0;
}

/*

*/