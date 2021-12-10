#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int iceMap[301][301]; //ºù»ê ¸Ê
int copyIceMap[301][301]; //ºù»ê ¸Ê Ä«ÇÇº»
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} }; //ºÏ, µ¿, ³², ¼­
bool visited[301][301]; //¹æ¹®Ã³¸®
int row, col, answer = 0;

struct pos {
	int y;
	int x;
};

bool inBound(int y, int x) {
	return y >= 1 && y <= row && x >= 1 && x <= col;
}

bool allMeltCheck() {
	int cnt = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (iceMap[i][j] == 0) cnt++;
		}
	}
	if (cnt == row * col) return true;
	return false;
}

void setIceMap() { // Copy to origin
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (copyIceMap[i][j] >= 0) iceMap[i][j] = copyIceMap[i][j];
			else iceMap[i][j] = 0;
		}
	}
}

void meltIce(int row, int col) { //Melting Ice
	queue<pos> q;
	q.push({ row, col });
	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		visited[y][x] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int my = y + dir[i][0];
			int mx = x + dir[i][1];

			if (inBound(my, mx) && !visited[my][mx]) {
				if (iceMap[my][mx] == 0) {
					copyIceMap[y][x]--;
				}
				else {
					q.push({ my, mx });
					visited[my][mx] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> row >> col;

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> copyIceMap[i][j]; 
			iceMap[i][j] = copyIceMap[i][j];
		}
	}
	
	while (1) {
		bool inIce = false;
		memset(visited, false, sizeof(visited));

		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				if (copyIceMap[i][j] > 0) {
					if (!visited[i][j]) {
						if (inIce) {
							cout << answer;
							return 0;
						}
						else {
							meltIce(i, j);
							inIce = true;
						}
					}
				}
			}
		}
		setIceMap();
		answer++;
		if (allMeltCheck()) {
			cout << 0;
			return 0;
		}
	}
}