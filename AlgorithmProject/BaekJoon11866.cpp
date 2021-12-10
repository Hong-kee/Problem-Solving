#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//�� ��� , K��° ����
	int N, K; cin >> N >> K;
	queue<int> person, answer;
	for (int i = 1; i <= N; i++) person.push(i);

	while (!person.empty()) {
		for (int i = 0; i < K - 1; i++) {
			person.push(person.front()); person.pop();
		}

		answer.push(person.front()); person.pop();
	}
	//���
	cout << '<';
	while (!answer.empty()) {
		cout << answer.front();
		answer.pop();
		if (answer.empty()) break;
		cout << ", ";
	}
	cout << '>';
}