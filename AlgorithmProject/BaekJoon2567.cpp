#include <iostream>
using namespace std;

bool board[101][101];
bool visited[101][101];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int cnt = 0, N, sum = 0;

bool inBound(int y, int x) {
	return y >= 1 && y <= 100 && x >= 1 && x <= 100;
}

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int my = y + dir[i][0];
		int mx = x + dir[i][1];

		if (!inBound(my, mx)) cnt++;
		else {
			if (!visited[my][mx]) {
				if (board[my][mx]) dfs(my, mx);
				else cnt++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	
	while (N--) {
		int y, x; cin >> y >> x;
		for (int i = y; i < y + 10; i++) {
			for (int j = x; j < x + 10; j++) {
				board[i][j] = true;
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (!visited[i][j] && board[i][j]) {
				cnt = 0;
				dfs(i, j);
				sum += cnt;
			}
		}
	}
	cout << sum;
}