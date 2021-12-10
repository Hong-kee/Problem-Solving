#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; long long M; cin >> N >> M; //나무의 수, 가져가려하는 나무의 높이
	vector<long long> treeStore(N);//나무들의 높이

	for (int i = 0; i < N; i++) cin >> treeStore[i];
	sort(treeStore.begin(), treeStore.end());

	long long answer = 0, lo = 0, hi = treeStore[N - 1]; //lo = 높이 0, hi = 가장 높은 나무

	while (lo <= hi) {
		answer = 0;
		long long mid = (lo + hi) / 2; //중간 값 잡고

		for (int i = 0; i < N; i++) {
			if (mid > treeStore[i]) continue;
			answer += treeStore[i] - mid;
		}
		if (answer >= M) lo = mid + 1; //만일 자른 나무들의 길이의 합이 가져가려고 하는 나무의 길이보다 크거나 같으면 최저 값을 높여야 한다.
		else if (answer < M) hi = mid - 1;// 아니라면 최고 값을 낮춰야 한다.
	}
	cout << hi;
}