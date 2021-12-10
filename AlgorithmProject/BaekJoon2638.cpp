#include <iostream>
#include <queue>
using namespace std;

int N, M, cnt = 0, answer = 0; //가로, 세로
int cheeseMap[100][100][2];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool visited[100][100];

struct pos {
	int y;
	int x;
};

void initVisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

void meltingCheese() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cheeseMap[i][j][1] >= 2) {
				cheeseMap[i][j][0] = 0;
				cnt--;
			}
			cheeseMap[i][j][1] = 0;
		}
	}
}

bool inBound(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

void bfs(int y, int x) {
	queue<pos> q;
	q.push({ y, x });
	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		visited[y][x] = true;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int my = y + dir[i][0];
			int mx = x + dir[i][1];

			if (inBound(my, mx) && !visited[my][mx]) {
				if (cheeseMap[my][mx][0] == 0) {
					q.push({ my,mx }); visited[my][mx] = true;
				}
				else cheeseMap[my][mx][1]++;
			}
		}
	}
}

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int my = y + dir[i][0];
		int mx = x + dir[i][1];

		if (inBound(my, mx) && !visited[my][mx]) {
			if (cheeseMap[my][mx][0] == 0) {
				visited[my][mx] = true;
				dfs(my, mx);
			}
			else cheeseMap[my][mx][1]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cheeseMap[i][j][0];
			if (cheeseMap[i][j][0] == 1) cnt++;
		}
	}

	while (cnt != 0) {
		//dfs(0, 0);
		bfs(0, 0);
		initVisited();
		meltingCheese();
		answer++;
	}
	cout << answer;
}
