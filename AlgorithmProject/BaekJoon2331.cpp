#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool visited[236197];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<string>numberStore;
	string number;
	int P, answer = 0;

	cin >> number >> P;
	visited[stoi(number)] = true;
	numberStore.push_back(number);

	while (1) {
		int tempNumber = 0;
		for (int i = 0; i < number.length(); i++) {
			tempNumber += pow(number[i] - '0', P);
		}
		if (visited[tempNumber]) {
			for (int i = 0; i < numberStore.size(); i++) {
				if (to_string(tempNumber) != numberStore[i]) answer++;
				else break;
			}
			break;
		}
		else {
			numberStore.push_back(to_string(tempNumber));
			visited[tempNumber] = true;
			number = to_string(tempNumber);
		}
	}
	cout << answer;
}