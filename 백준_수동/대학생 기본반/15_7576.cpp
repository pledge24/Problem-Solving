// 2023-10-24

//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//#define DIR 4
//using namespace std;
//
//int M, N;
//
//vector<vector<int>> box;
//queue<pair<int, int>> q;
//
//bool inRange(int x, int y) {
//	return 0 <= x && x < N && 0 <= y && y < M;
//}
//
//bool qualified() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (box[i][j] == 0) return false;
//		}
//	}
//
//	return true;
//}
//
//void bfs() {
//
//	int dx[DIR] = { -1, 0, 1, 0 };
//	int dy[DIR] = { 0, 1, 0, -1 };
//	
//	int cnt = 1;
//	while (!q.empty()) {
//		pair<int, int> p = q.front();
//		q.pop();
//
//		int cur_r = p.first;
//		int cur_c = p.second;
//
//		for (int i = 0; i < DIR; i++) {
//			int nx = cur_r + dx[i];
//			int ny = cur_c + dy[i];
//
//			if (inRange(nx, ny) && !box[nx][ny]) {
//				box[nx][ny] = box[cur_r][cur_c] + 1;
//				cnt = box[cur_r][cur_c] + 1;
//				q.push(make_pair(nx, ny));
//			}
//		}
//	}
//
//	if (qualified()) {
//		cout << cnt -1 << '\n';
//	}
//	else {
//		cout << "-1" << '\n';
//	}
//}
//
//int main() {
//	fastio;
//
//	cin >> M >> N;
//	box.resize(N, vector<int>(M));
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> box[i][j];
//			if (box[i][j] > 0) {
//				q.push(make_pair(i, j));
//			}
//		}
//	}
//
//	bfs();
//
//	/*for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cout << box[i][j] << ' ';
//		}
//		cout << '\n';
//	}*/
//
//	return 0;
//}