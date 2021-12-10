#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long X, Y; cin >> X >> Y;//게임 횟수, 이긴 게임

	long long lo = 1, hi = 1000000000, win = Y * 100 / X; //lo = 최소 판 수, hi = 최대 판 수, win = 승률
	
	while (lo <= hi) {
		long long mid = (lo + hi) / 2, winComp = (Y + mid) * 100 / (X + mid); //mid = 중간 값, winComp = 중간 값을 넣었을 때 승률
		
		if (win < winComp) hi = mid - 1; //만일 승률이 높아졌으면 최소 판 수를 뽑아내기 위해 hi값 축소
		else lo = mid + 1;//만일 아니라면 lo값 증가
	}
	if (lo == 1000000001) cout << -1;//예외 처리로 만일 모두 돌렸을 때 승률이 올라가지 않았으면 -1 출력
	else cout << lo;
}