#include <iostream>
#include <vector>
using namespace std;

vector<int> node[100002];
vector<int> parents(100002);
bool visited[100002];

void dfs(int idx) {
	visited[idx] = true;
	for (int i = 0; i < node[idx].size(); i++) {
		if (!visited[node[idx][i]]) {
			parents[node[idx][i]] = idx;
			dfs(node[idx][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int start, end; cin >> start >> end;
		node[start].push_back(end);
		node[end].push_back(start);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i);
	}
	for (int i = 2; i <= N; i++) cout << parents[i] << '\n';
}