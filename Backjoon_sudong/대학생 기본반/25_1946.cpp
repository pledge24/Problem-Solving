// 2023-11-12


#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void func1() {
	int N;
	cin >> N;

	vector<pair<int, int>> v;
	int score_a, score_b;
	for (int i = 0; i < N; i++) {
		cin >> score_a >> score_b;
		v.push_back(make_pair(score_a, score_b));
	}

	sort(v.begin(), v.end());
	int M = v[0].second, cnt = 1;

	//cout << '\n';
	//for (pair<int, int> p : v) {
	//	cout << p.first << " " << p.second << '\n';

	//}
	for (int i = 1; i < N; i++) {
		if (v[i].second < M) {
			M = v[i].second;
			cnt++;
		}
	}


	cout << cnt << '\n';
}

int main() {
	fastio;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		func1();
	}

}