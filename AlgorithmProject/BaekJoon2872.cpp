#include <iostream>
#include <vector>
using namespace std;

bool fixBooks[300001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int booksNum, answer = 0; cin >> booksNum;
	vector<int> bookStore(booksNum);
	int fixedValue = booksNum;

	for (int i = 0; i < booksNum; i++) cin >> bookStore[i];

	for (int i = booksNum - 1; i >= 0; i--) {
		if (bookStore[i] == fixedValue) {
			fixBooks[i] = true;
			fixedValue--;
		}
	}
	for (int i = 0; i < booksNum; i++) {
		if (!fixBooks[i]) answer++;
	}
	cout << answer;
}