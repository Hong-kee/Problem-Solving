#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> wordStore = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string sentence = "";
	int answer = 0, idx;

	cin >> sentence;

	for (int i = 0; i < wordStore.size(); i++) {
		while (1) {
			idx = sentence.find(wordStore[i]);
			if (idx == string::npos) break;
			sentence.replace(idx, wordStore[i].length(), "#");
		}
	}
	cout << sentence.length();
}