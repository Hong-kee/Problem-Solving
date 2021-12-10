#include <iostream>
#include <string>
using namespace std;

bool checkNumber[21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string command;
	int number, M; cin >> M;

	while (M--) {
		cin >> command;

		if (command == "add") {
			cin >> number; checkNumber[number] = true;
		}
		else if (command == "remove") {
			cin >> number; checkNumber[number] = false;
		}
		else if (command == "check") {
			cin >> number;
			if (checkNumber[number]) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (command == "toggle") {
			cin >> number;
			if (checkNumber[number]) checkNumber[number] = false;
			else checkNumber[number] = true;
		}
		else if (command == "all") {
			for (int i = 1; i <= 20; i++) {
				checkNumber[i] = true;
			}
		}
		else {
			for (int i = 1; i <= 20; i++) {
				checkNumber[i] = false;
			}
		}
	}
}