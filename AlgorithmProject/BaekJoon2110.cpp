#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, C; cin >> N >> C;

	vector<int> house(N);
	for (int i = 0; i < N; i++) cin >> house[i];
	sort(house.begin(), house.end());

	//lo = 최소 거리인 1, hi = 최대 거리인 끝 집 - 처음 집, dist = 갱신할 거리
	int lo = 1, hi = house[N - 1] - house[0], dist = 0;

	while (lo <= hi) {
		int mid = (lo + hi) / 2, router = 1, start = house[0];
		
		for (int i = 1; i < N; i++) {
			dist = house[i] - start; //거리를 갱신한다.
			if (mid <= dist) { //만일 갱신한 거리가 기준 거리보다 크거나 같으면
				router++;//공유기 설치
				start = house[i];//설치한 곳을 기준으로
			}
		}
		if (router >= C) lo = mid + 1;//만일 공유기를 설치한 곳이 주어진 공유기보다 많거나 같으면 기준 거리를 넓힘
		else hi = mid - 1;//반대면 기준 거리를 좁힘
	}
	cout << hi;
}