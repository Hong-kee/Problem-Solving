#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long answer = 0, N; cin >> N;
	vector<int>students(N);
	
	for (int i = 0; i < N; i++) {
		cin >> students[i];
	}
	sort(students.begin(), students.end());
	
	for (int i = 0; i < N; i++) {
		answer += abs(students[i] - (i + 1));
	}
	cout << answer;
}