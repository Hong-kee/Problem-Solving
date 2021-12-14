#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	set<int> numStore;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		numStore.insert(num);
	}
	for (auto iter = numStore.begin(); iter != numStore.end(); iter++) cout << *iter << ' ';
}