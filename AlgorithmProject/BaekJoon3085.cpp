#include <iostream>
#include <algorithm>
using namespace std;

int N, answer = 0;
int dir[2][2] = { {1,0}, {0,1} };//남,동 
char board[51][51];

bool inBound(int y, int x) {
	return y >= 1 && y <= N && x >= 1 && x <= N;
}

void eatCandy() {
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		char standard = board[1][i]; //기준
		cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (board[j][i] == standard) {
				cnt++;
			}
			else {
				standard = board[j][i];
				answer = max(answer, cnt);
				cnt = 1;
			}
		}
		answer = max(answer, cnt);
	}

	for (int i = 1; i <= N; i++) {
		char standard = board[i][1]; //기준
		cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == standard) {
				cnt++;
			}
			else {
				standard = board[i][j];
				answer = max(answer, cnt);
				cnt = 1;
			}
		}
		answer = max(answer, cnt);
	}
}

void moveCandy(int y, int x) {
	for (int i = 0; i < 2; i++) {
		int my = y + dir[i][0];
		int mx = x + dir[i][1];

		if (inBound(my, mx) && board[y][x] != board[my][mx]) {
			swap(board[y][x], board[my][mx]);
			eatCandy();
			swap(board[y][x], board[my][mx]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			moveCandy(i, j);
			if (answer == N) {
				cout << answer;
				return 0;
			}
		}
	}
	cout << answer;
}