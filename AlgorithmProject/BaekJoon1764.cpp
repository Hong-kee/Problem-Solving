#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int answer = 0, N, M; cin >> N >> M;
	string s = "";
	map<string, int> mappingName;
	vector<string> nameStore;

	for (int i = 0; i < N; i++) {
		cin >> s; mappingName[s] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (mappingName[s] == 1) nameStore.push_back(s);
	}
	sort(nameStore.begin(), nameStore.end());
	cout << nameStore.size() << '\n';
	for (int i = 0; i < nameStore.size(); i++) cout << nameStore[i] << '\n';
}