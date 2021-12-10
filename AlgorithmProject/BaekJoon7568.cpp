#include <iostream>
#include <vector>
#define fastIo cin.tie(0) -> ios_base::sync_with_stdio(0);

using namespace std;

int main() {
	fastIo;
	vector<pair<int, int>> peopleStore; //����� ����
	int N, kg, cm;
	cin >> N;
	while (N--) {
		cin >> kg >> cm;
		peopleStore.push_back(make_pair(kg, cm));
	}
	for (int i = 0; i < peopleStore.size(); i++) { //ó�� ������� ������� ����
		int ranking = 1;
		for (int j = 0; j < peopleStore.size(); j++) {
			if (peopleStore[i].first < peopleStore[j].first && peopleStore[i].second < peopleStore[j].second) ranking++; //���� �ڽź��� ��ġ�� ũ�� ��ŷ�� �з�����.
		}
		cout << ranking << ' ';
	}
}