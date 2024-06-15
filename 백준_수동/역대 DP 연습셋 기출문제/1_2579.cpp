// 2023-10-26

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;

bool inRange(int x) {
	return 0 <= x && x < N;
}
int main() {
	fastio;
	cin >> N;

	vector<int> score(N);
	vector<vector<int>> ans(N, vector<int>(2));
	for (int i = 0; i < N; i++) {
		cin >> score[i];
	}

	vector<int> a, b;
	//int max_a, max_b;
	for (int i = 0; i < N; i++) {
		if (inRange(i - 1)) a = ans[i - 1]; else a.clear();
		if (inRange(i - 2)) b = ans[i - 2];	else b.clear();
		
		//max_a = *max_element(a.begin(), a.end());
		//max_b = *max_element(b.begin(), b.end() - 1);

		ans[i][0] = score[i];
		ans[i][1] = score[i];
		if (!b.empty()) ans[i][0] += max(b[0], b[1]);
		if (!a.empty()) ans[i][1] += a[0];
		
	}

	//cout << '\n';
	//for (int i = 0; i < N; i++) {
	//	
	//	cout << ans[i][0] << ":" << ans[i][1] << '\n';

	//}
	cout << *max_element(ans[N - 1].begin(), ans[N - 1].end()) << '\n';
}