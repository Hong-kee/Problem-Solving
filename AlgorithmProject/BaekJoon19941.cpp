#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K, answer = 0; cin >> N >> K;
	string tableStatus;	cin >> tableStatus;

	for (int i = 0; i < tableStatus.length(); i++) {
		if (tableStatus[i] == 'H' || tableStatus[i] == ' ') continue;
		
		for (int j = i - K; j <= i + K; j++) {
			if (j >= 0 && j < tableStatus.length() && tableStatus[j] == 'H') {
				answer++; tableStatus[j] = ' '; break;
			}
		}
	}
	cout << answer;
}