#include <iostream>
#include <vector>
#define fastIo cin.tie(0) -> ios_base::sync_with_stdio(0);

using namespace std;

int main() {
	fastIo;
	vector<pair<int, int>> peopleStore; //사람들 저장
	int N, kg, cm;
	cin >> N;
	while (N--) {
		cin >> kg >> cm;
		peopleStore.push_back(make_pair(kg, cm));
	}
	for (int i = 0; i < peopleStore.size(); i++) { //처음 사람부터 순서대로 돈다
		int ranking = 1;
		for (int j = 0; j < peopleStore.size(); j++) {
			if (peopleStore[i].first < peopleStore[j].first && peopleStore[i].second < peopleStore[j].second) ranking++; //만일 자신보다 덩치가 크면 랭킹이 밀려난다.
		}
		cout << ranking << ' ';
	}
}