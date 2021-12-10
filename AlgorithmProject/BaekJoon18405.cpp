#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int board[201][201][2];
int N, K, S, destY, destX;

struct pos{
	int y;
	int x;
};
queue<pos> q;

void copyBoard() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j][0] = board[i][j][1];
		}
	}
}

bool inBound(int y, int x) {
	return y >= 1 && y <= N && x >= 1 && x <= N;
}

void bfs() {
	int sizeOfQueue = q.size(); //고정

	for (int i = 0; i < sizeOfQueue; i++) {
		int y = q.front().y;
		int x = q.front().x;

		q.pop();

		for (int j = 0; j < 4; j++) {
			int my = y + dir[j][0];
			int mx = x + dir[j][1];

			if (board[my][mx][0] >= 1 && board[my][mx][0] < 1001) continue; //만일 값이 세팅되어 있으면 안해
			if (inBound(my, mx)) {
				int changeCheck = board[my][mx][1];
				board[my][mx][1] = min(board[my][mx][1], board[y][x][0]);
				if (changeCheck != board[my][mx][1]) q.push({ my, mx });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j][0];
			
			if (board[i][j][0] > 0) q.push({ i, j });
			else board[i][j][0] = 1001;

			board[i][j][1] = board[i][j][0];
		}
	}
	cin >> S >> destY >> destX;

	while (S--) {
		bfs();
		copyBoard();
	}
	if (board[destY][destX][0] == 1001) cout << 0;
	else cout << board[destY][destX][0];
}