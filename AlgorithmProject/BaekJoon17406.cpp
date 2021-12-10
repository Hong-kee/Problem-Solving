//������ ������ �ٸ��� �ּڰ��� �ٸ��� ���ŵȴ�.
//������ ������ �ִ� 6��
//������ ����ؼ� ������ ������ �ٸ��� ��������.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pos { //�߰�y, �߰�x, ����
	int centerY; 
	int centerX;
	int range;
};
vector<pos>originStore, combinationStore;
int r, c, k, answer = 987654321;
int copyMap[51][51];
int map[51][51];
bool visited[6];

void initMap() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			map[i][j] = copyMap[i][j];
		}
	}
}

void rotationMap() {
	for (int i = 0; i < k; i++) {
		int y = combinationStore[i].centerY;
		int x = combinationStore[i].centerX;
		int range = combinationStore[i].range;

		for (int j = 1; j <= range; j++) {
			int my = y - j, mx = x - j; //���� ������ (���� �ϴ�)
			int temp = map[my][mx];//������ ��

			//���� ����
			for (int k = 1; k <= j * 2; k++) {
				map[my][mx] = map[my + 1][mx];
				my++;
			}
			//�Ʒ��� ����
			for (int k = 1; k <= j * 2; k++) {
				map[my][mx] = map[my][mx + 1];
				mx++;
			}
			//������ ����
			for (int k = 1; k <= j * 2; k++) {
				map[my][mx] = map[my - 1][mx];
				my--;
			}
			//���� ����
			for (int k = 1; k <= j * 2; k++) {
				//������ ó�� (temp �ֱ�)
				if (k == j * 2) map[my][mx] = temp;
				else {
					map[my][mx] = map[my][mx - 1];
					mx--;
				}
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		int cnt = 0;
		for (int j = 1; j <= c; j++) {
			cnt += map[i][j];
		}
		answer = min(cnt, answer);
	}
}

void dfs() {
	if (combinationStore.size() == k) {
		rotationMap();
		initMap();
		return;
	}
	for (int i = 0; i < k; i++) {
		if (!visited[i]) {
			visited[i] = true;
			combinationStore.push_back(originStore[i]);
			dfs();
			visited[i] = false;
			combinationStore.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> r >> c >> k;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> copyMap[i][j];
			map[i][j] = copyMap[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		int a, b, c; cin >> a >> b >> c;
		originStore.push_back({ a,b,c });
	}
	dfs();
	cout << answer;
}