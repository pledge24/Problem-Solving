// 2023-10-26

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int cnt = 0;
int min_cnt = -1;

void dfs(int num) {
	
	if (min_cnt != -1 && min_cnt < cnt) return;

	if (num == 1) {
		if (min_cnt == -1 || min_cnt > cnt) {
			min_cnt = cnt;
		}
		return;
	}

	if (num % 3 == 0) {
		cnt++;
		dfs(num / 3);
		cnt--;
	}

	if (num % 2 == 0) {
		cnt++;
		dfs(num / 2);
		cnt--;
	}


	cnt++;
	dfs(num - 1);
	cnt--;
	
	return;
}

int main() {
	fastio;
	int N;
	cin >> N;
	dfs(N);

	cout << min_cnt << '\n';

	return 0;
}