#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cnt = -1, N; cin >> N;
	long long answer = pow(2, 62);
	map<long long, int> mappingCount;

	for (int i = 0; i < N; i++) {
		long long num; cin >> num;
		mappingCount[num]++;
	}
	for (auto iter = mappingCount.begin(); iter != mappingCount.end(); iter++) {
		if (iter->second > cnt) {
			answer = iter->first;
			cnt = iter->second;
		}
		else if (iter->second == cnt) answer = min(answer, iter->first);
	}
	cout << answer;
}