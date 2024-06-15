// 2023-10-26

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 6
using namespace std;

int M, N, H;

vector<vector<vector<int>>> box;
queue<vector<int>> q;

bool inRange(int h, int x, int y) {
	return 0 <= h && h < H && 0 <= x && x < N && 0 <= y && y < M;
}

bool qualified() {

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] == 0) return false;
			}

		}
	}

	return true;
}

void bfs() {

	int dz[DIR] = { -1,1, 0, 0, 0, 0 };
	int dx[DIR] = { 0, 0, 1, 0, -1, 0 };
	int dy[DIR] = { 0, 0, 0, 1, 0, -1 };
	
	int cnt = 1;
	while (!q.empty()) {
		//cout << 'b' << '\n';
		vector<int> p = q.front();
		q.pop();
		//cout << 'b' << '\n';
		int cur_h = p[0];
		int cur_r = p[1];
		int cur_c = p[2];
		
		for (int i = 0; i < DIR; i++) {
			int nz = cur_h + dz[i];
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];			

			if (inRange(nz, nx, ny) && !box[nz][nx][ny]) {
				box[nz][nx][ny] = box[cur_h][cur_r][cur_c] + 1;
				cnt = box[cur_h][cur_r][cur_c] + 1;
				q.push({nz, nx, ny});
			}
		}

		//for (int i = 0; i < H; i++) {
		//	for (int j = 0; j < N; j++) {
		//		for (int k = 0; k < M; k++) {
		//			cout << box[i][j][k] << ' ';
		//		}
		//		cout << '\n';

		//	}
		//	
		//}
		//cout << '\n';
	}

	if (qualified()) {
		cout << cnt -1 << '\n';
	}
	else {
		cout << "-1" << '\n';
	}
}

int main() {
	fastio;

	cin >> M >> N >> H;
	box.resize(H, vector<vector<int>>(N, vector<int>(M)));
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] > 0) {
					q.push({i, j, k});
				}
			}
			
		}
	}

	//cout << "a" << '\n';
	bfs();

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << box[i][j] << ' ';
		}
		cout << '\n';
	}*/

	return 0;
}