#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<pair<int, pair<int, string>>> serialStore;

	for (int i = 0; i < N; i++) {
		int sumNum = 0; string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= '0' && s[j] <= '9') sumNum += s[j] - '0';
		}
		serialStore.push_back(make_pair(s.length(), make_pair(sumNum, s)));
	}
	sort(serialStore.begin(), serialStore.end());

	for (int i = 0; i < N; i++) cout << serialStore[i].second.second << '\n';
}