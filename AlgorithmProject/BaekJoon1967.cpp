#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pos {
	int y;
	int value;
};
vector<pos> node[10001];
bool visited[10001];
int nodeCnt, y, x, value, answer = 0;

void initVisited() {
	for (int i = 1; i <= nodeCnt; i++) {
		visited[i] = false;
	}
}

void dfs(int y, int answerCnt) {
	answer = max(answer, answerCnt);

	for (int i = 0; i < node[y].size(); i++) {
		if (!visited[node[y][i].y]) {
			visited[node[y][i].y] = true;
			dfs(node[y][i].y, answerCnt + node[y][i].value);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> nodeCnt;

	for (int i = 0; i < nodeCnt - 1; i++) {
		cin >> y >> x >> value;
		node[x].push_back({ y, value }); node[y].push_back({ x, value });
	}
	for (int i = nodeCnt; i > 0; i--) {
		visited[i] = true;
		for (int j = 0; j < node[i].size(); j++) {
			if (!visited[node[i][j].y]) {
				visited[node[i][j].y] = true;
				dfs(node[i][j].y, node[i][j].value);
			}
		}
		initVisited();
	}
	cout << answer;
}