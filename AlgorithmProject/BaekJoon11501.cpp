#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testCase; cin >> testCase;

	while (testCase--) {
		int N; cin >> N;
		long long answer = 0;
		vector<long long> stocks(N);

		for (int i = 0; i < N; i++) {
			cin >> stocks[i];
		}
		
		//누적 주식 갯수, 처음 시작 값
		long long cnt = 0, maxStock = stocks.back();
		for (int i = stocks.size() - 2; i >= 0; i--) {
			//기존 값이 더 크다면 주식 매입
			if (maxStock > stocks[i]) {
				cnt++; answer -= stocks[i];
			}
			//더 큰 값이 나오면 큰 값 갱신
			else if (maxStock < stocks[i]) {
				answer += cnt * maxStock;
				cnt = 0; maxStock = stocks[i];
			}
		}
		//계산이 안 된게 있으면 처리
		if (cnt > 0) answer += cnt * maxStock;
		cout << answer << '\n';
	}
}