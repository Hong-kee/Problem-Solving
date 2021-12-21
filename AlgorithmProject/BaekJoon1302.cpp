#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cnt = -1, N; cin >> N;
	map<string, int> books;
	string s, answer;

	for (int i = 0; i < N; i++) {
		cin >> s; books[s]++;
	}
	for (auto iter = books.begin(); iter != books.end(); iter++) {
		if (iter->second > cnt) {
			cnt = iter->second; answer = iter->first;
		}
		else if (iter->second == cnt) {
			answer = min(answer, iter->first);
		}
	}
	cout << answer;
}