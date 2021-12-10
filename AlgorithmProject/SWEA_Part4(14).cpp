#include <iostream>
using namespace std;

int recursive(int N, int M, int answer) {
	if (M == 0) return answer;
	recursive(N, M - 1, answer * N);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase = 0, number, N, M;

	while (testCase != 10) {
		cin >> number;
		cin >> N >> M;
		cout << '#' << number << ' ' << recursive(N, M, 1) << '\n';
		testCase++;
	}
}