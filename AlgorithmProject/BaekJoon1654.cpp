#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K, N; cin >> K >> N;//랜선의 갯수, 필요한 갯수
	vector<long long> lineStore(K);

	for (int i = 0; i < K; i++) cin >> lineStore[i];
	sort(lineStore.begin(), lineStore.end());

	long long answer = 0, lo = 1, hi = lineStore[K - 1];

	while (lo <= hi) {
		answer = 0;
		long long mid = (lo + hi) / 2;

		for (int i = 0; i < K; i++) answer += lineStore[i] / mid; //랜선을 기준치로 자르기
		if (answer >= N) lo = mid + 1; //만일 자른 랜선의 갯수가 많거나 같으면 자르는 길이 늘리기
		else hi = mid - 1;//반대인 경우 자르는 길이 줄이기
	}
	cout << hi;
}