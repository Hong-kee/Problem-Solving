#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int curHz, destHz, N;

	cin >> curHz >> destHz >> N;
	vector<int> hzStore(N);

	for (int i = 0; i < N; i++) cin >> hzStore[i];
	int answer = abs(curHz - destHz);

	for (int i = 0; i < N; i++) {
		int hzGap = abs(hzStore[i] - destHz) + 1;
		answer = min(answer, hzGap);
	}
	cout << answer;
}