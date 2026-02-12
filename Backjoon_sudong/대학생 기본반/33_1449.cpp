// 2023-10-22

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
	int N, L;
	cin >> N >> L;
	
	vector<pair<int, bool>> pos;
	int p;
	for (int i = 0; i < N; i++) {
		cin >> p;
		pos.push_back(make_pair(p, false));
	}

	sort(pos.begin(), pos.end());

	int cover = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		// 아직 테이프 안붙은 곳
		if (pos[i].second == false) {
			cnt++;

			cover = pos[i].first + L - 1;
			for (int j = i; j < N; j++) {
				if (pos[j].first <= cover) {
					pos[j].second = true;
				}
				else {
					break;
				}
			}
		}
		

	}
	
	cout << cnt << '\n';

	return 0;
}