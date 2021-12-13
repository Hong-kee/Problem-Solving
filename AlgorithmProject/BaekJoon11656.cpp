#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	vector<string> suffixStore;
	int idx = 0;

	while (idx != s.length()) {
		suffixStore.push_back(s.substr(idx, s.length()));
		idx++;
	}
	sort(suffixStore.begin(), suffixStore.end());
	for (int i = 0; i < suffixStore.size(); i++) cout << suffixStore[i] << '\n';
}