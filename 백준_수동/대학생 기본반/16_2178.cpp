//// 2023-10-22
//
//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//#define DIR 4
//using namespace std;
//
//int N, M;
//
//vector<vector<int>> matrix;
//vector<vector<bool>> visited;
//
//bool inRange(int r, int c) {
//	return 0 <= r && r < N && 0 <= c && c < M;
//}
//
//void bfs(int r, int c) {
//	int dx[4] = { -1, 0 ,1 ,0 };
//	int dy[4] = { 0, 1, 0, -1 };
//
//	queue<pair<int, int>> q;
//	q.push(make_pair(r, c));
//	visited[r][c] = true;
//
//
//	while (!q.empty()) {
//		pair<int, int> p = q.front();
//		q.pop();
//
//		for (int i = 0; i < DIR; i++) {
//			int nx = p.first + dx[i];
//			int ny = p.second + dy[i];
//			if (inRange(nx, ny) && matrix[nx][ny] && !visited[nx][ny]) {
//				q.push(make_pair(nx, ny));
//				visited[nx][ny] = true;
//				matrix[nx][ny] = matrix[p.first][p.second] + 1;
//
//			}
//		}
//	}
//}
//
//int main() {
//	fastio;
//
//	cin >> N >> M;
//
//	matrix.resize(N, vector<int>(M));
//	visited.resize(N, vector<bool>(M, false));
//
//	char c;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> c;
//			matrix[i][j] = c - '0';
//		}
//	}
//
//	bfs(0, 0);
//
//	//for (int i = 0; i < N; i++) {
//	//	for (int j = 0; j < M; j++) {
//	//		cout << matrix[i][j] << " ";
//	//	
//	//	}
//	//	cout << '\n';
//	//}
// 
//	cout << matrix[N-1][M-1] << '\n';
//
//	return 0;
//}