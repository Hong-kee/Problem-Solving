#include <iostream>
#include <algorithm>
using namespace std;

int board[500][500];
bool visited[500][500];
int dir[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} };
int pictureCnt = 0, tempSize, maxSize = 0, r, c;

bool inBound(int y, int x) {
	return y >= 0 && y < r && x >= 0 && x < c;
}

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int my = y + dir[i][0];
		int mx = x + dir[i][1];

		if (inBound(my, mx) && !visited[my][mx] && board[my][mx] == 1) {
			++tempSize;
			dfs(my, mx);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visited[i][j] && board[i][j] == 1) {
				++pictureCnt; tempSize = 1;
				dfs(i, j);
			}
			maxSize = max(maxSize, tempSize);
		}
	}
	cout << pictureCnt << '\n' << maxSize;
}