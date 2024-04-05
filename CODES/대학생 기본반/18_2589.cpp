//// 2023-10-24
//
//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//#define DIR 4
//using namespace std;
//
//vector<vector<int>> land;
//
//int M, N;
//int dx[DIR] = { -1, 0, 1, 0 };
//int dy[DIR] = { 0, 1, 0, -1 };
//
//int ans = 0;
//
//bool inRange(int x, int y) {
//	return 0 <= x && x < M && 0 <= y && y < N;
//}
//
//bool isCandidate(int cur_r, int cur_c) {
//
//	int cnt = 0;
//	for (int i = 0; i < DIR; i++) {
//		int nx = cur_r + dx[i];
//		int ny = cur_c + dy[i];
//
//		if (inRange(nx, ny) && land[nx][ny]) {
//			cnt++;
//		}
//	}
//
//	return cnt == 1;
//}
//
//void bfs(int r, int c) {
//
//	queue<pair<int, int>> q;
//
//	vector<vector<int>> step;
//	step.resize(M, vector<int>(N, -1));
//
//	q.push(make_pair(r, c));
//	step[r][c] = 0;
//	
//	int distance = 0;
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
//			if (inRange(nx, ny) && land[nx][ny] && (step[nx][ny] < 0) ) {
//				step[nx][ny] = step[cur_r][cur_c] + 1;
//				distance = step[nx][ny];
//				q.push(make_pair(nx, ny));
//			}
//		}
//	}
//
//	ans = distance > ans ? distance : ans;
//	//cout << distance << '\n';
//}
//
//
//int main() {
//	fastio;
//	cin >> M >> N;
//	land.resize(M, vector<int>(N));
//	
//
//	char c;
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < N; j++) {			
//			cin >> c;
//			land[i][j] = (c == 'L') ? 1 : 0;
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < N; j++) {
//			if (land[i][j]) {
//				bfs(i, j);
//			}			
//		}
//	}
//
//	
//
//	/*for (int i = 0; i < M; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << matrix[i][j] << " ";
//		}
//		cout << '\n';
//	}*/
//
//	cout << ans << '\n';
//}
//
////5 5
////LLLLL
////LWWWL
////LWWWL
////LWWWL
////LLLLL
//
////3 3
////LLW
////WWW
////WWW