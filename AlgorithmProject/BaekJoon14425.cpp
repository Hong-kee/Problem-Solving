#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int answer = 0, N, M; cin >> N >> M;
	map<string, int> words;
	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		words[s] = 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (words.find(s) != words.end()) ++answer;
	}
	cout << answer;
}