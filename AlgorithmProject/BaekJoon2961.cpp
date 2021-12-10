#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N; 
long long tasteGap = 1000000000;
vector<pair<long long, long long>> tasteStore; //�Ÿ�, ����
bool check[10];

void searchMinGap(int idx, long long sour, long long bitter) {
	tasteGap = min(tasteGap, abs(sour - bitter)); //�ּڰ� ����
	for (int i = idx + 1; i < N; i++) {
		if (!check[i]) { //���� �ȵƴٸ� ?
			check[i] = true; 
			searchMinGap(i, sour * tasteStore[i].first, bitter + tasteStore[i].second);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		tasteStore.push_back(make_pair(x, y));
	}
	for (int i = 0; i < N; i++) {
		check[i] = true;
		searchMinGap(i, tasteStore[i].first, tasteStore[i].second);
		check[i] = false;
	}
	cout << tasteGap;
}