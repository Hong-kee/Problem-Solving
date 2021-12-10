#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;//강의의 수, 블루레이 수
	vector<long long> lectures(N);

	long long lo = 0, hi = 0;

	for (int i = 0; i < N; i++) { //lo = 입력 값 중 최댓값, hi = 모든 강의 길이의 합
		cin >> lectures[i];
		hi += lectures[i];
		lo = max(lo, lectures[i]);
	}

	long long mid, bluerays, lectureLen = 0;
	
	while (lo <= hi) {
		bluerays = 0, lectureLen = 0; 
		long long mid = (lo + hi) / 2;

		for (int i = 0; i < N; i++) {
			if (lectureLen + lectures[i] > mid) { //만일 기준 강의 길이를 넘어간다 ?
				++bluerays; //블루레이 추가
				lectureLen = 0; //길이 초기화
			}
			lectureLen += lectures[i];
		}
		if (lectureLen != 0) ++bluerays; //마지막 예외처리
		if (bluerays <= M) hi = mid - 1; //만일 입력 블루레이 수가 더 많거나 같으면 시간을 줄여서 블루레이 수를 늘려야함
		else lo = mid + 1;//아니라면 시간 늘리기
	}
	cout << lo;
}