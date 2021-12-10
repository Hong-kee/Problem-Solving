#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int answer = 0, number = 1, numberStart, numberEnd; cin >> numberStart >> numberEnd;
	vector<int> problemStore;
	
	while (number != 1001) {
		for (int i = 0; i < number; i++) {
			problemStore.push_back(number);
		}
		number++;
	}
	for (int i = numberStart - 1; i < numberEnd; i++) {
		answer += problemStore[i];
	}
	cout << answer;
}