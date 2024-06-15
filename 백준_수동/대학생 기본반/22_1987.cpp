// 2023-10-25

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4
using namespace std;

int R, C;
vector<vector<char>> matrix;

int dx[DIR] = {1, -1, 0, 0};
int dy[DIR] = {0, 0, 1, -1};

map<char, bool> dfs_alpha;
int ans = 1;
int ans_max = 1;
struct step {
	int r;
	int c;
	map<char, bool> have_alpha;
	int cnt;
};
bool inRange(int x, int y) {
	return 0 <= x && x < R && 0 <= y && y < C;
}

void bfs() {
	queue<step> q;
	step s = { 0, 0, {{matrix[0][0], true}}, 1};

	q.push(s);

	int cnt = 1;
	while (!q.empty()) {
		step p = q.front();
		q.pop();

		int cur_r = p.r;
		int cur_c = p.c;
		for (int i = 0; i < DIR; i++) {
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];

			if (inRange(nx, ny) && !p.have_alpha[matrix[nx][ny]]) {

				step next_p;
				next_p.r = nx;
				next_p.c = ny;
				next_p.have_alpha = p.have_alpha;
				next_p.have_alpha[matrix[nx][ny]] = true;
				next_p.cnt = p.cnt + 1;
				cnt = next_p.cnt;
				
				q.push(next_p);

				
				//for (int i = 0; i < R; i++) {
				//	for (int j = 0; j < C; j++) {
				//		cout << next_p.visited[i][j] << ' ';
				//	}
				//	cout << '\n';
				//}
				//cout << '\n';
				
				

			}
		}
	}

	cout << cnt << '\n';
}

void dfs(int cur_r, int cur_c) {

	for (int i = 0; i < DIR; i++) {
		int nx = cur_r + dx[i];
		int ny = cur_c + dy[i];
		if (inRange(nx, ny) && !dfs_alpha[matrix[nx][ny]]) {
			dfs_alpha[matrix[nx][ny]] = true;
			ans++;
			ans_max = ans_max < ans ? ans : ans_max;
			dfs(nx, ny);
			dfs_alpha[matrix[nx][ny]] = false;
			ans--;
		}
	}
}
int main() {
	fastio;

	cin >> R >> C;
	matrix.resize(R, vector<char>(C));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> matrix[i][j];
		}
	}

	//bfs();

	dfs_alpha[matrix[0][0]] = true;
	dfs(0, 0);
	cout << ans_max << '\n';

	return 0;
}