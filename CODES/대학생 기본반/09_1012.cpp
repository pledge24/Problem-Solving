//// 2023-10-17 메모리 초기화 한 번 알아보기(resize는 초기화 기능을 하지 못하는가!)
//
//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//#define DIR 4
//
//using namespace std;
//
//vector<vector<bool>> farm;
//vector<vector<bool>> visited;
//
//int T, R, C, K;
//
//bool inRange(int r, int c) { return (0 <= r && r < R && 0 <= c && c < C); }
//
//void bfs(int r, int c) {
//	int dx[4] = { -1, 0, 1, 0 };
//	int dy[4] = { 0, 1, 0, -1 };
//
//	// 큐를 생성하고 시작 노드를 큐에 추가
//	queue<pair<int, int>> q;
//	q.push(make_pair(r, c));
//
//	// 시작 노드를 방문한 것으로 표시
//	visited[r][c] = true;
//
//	while (!q.empty()) {
//		// 큐에서 하나의 노드를 꺼내 출력
//		pair<int, int> curr_pos = q.front();
//		q.pop();
//
//		// 해당 노드의 인접한 노드들을 방문
//		for (int i = 0; i < DIR; i++) {
//			int nx = curr_pos.first + dx[i];
//			int ny = curr_pos.second + dy[i];
//
//			if (inRange(nx, ny) && farm[nx][ny] && !visited[nx][ny]) {
//				//cout << "curr pos" << nx << " " << ny << '\n';
//				q.push(make_pair(nx, ny));
//				visited[nx][ny] = true;
//			}
//		}
//		
//	}
//}
//
//int main1012() {
//	fastio;
//
//	cin >> T;
//
//	// 테스트 단위.
//	for (int t = 0; t < T; t++) {
//
//		cin >> C >> R >> K;
//		farm.resize(R, vector<bool>(C, false));
//		visited.resize(R, vector<bool>(C, false));
//
//		for (int i = 0; i < R; i++) {
//			for (int j = 0; j < C; j++) {
//				farm[i][j] = false;
//				visited[i][j] = false;
//			}
//		}
//		int r, c;
//		for (int j = 0; j < K; j++) {
//			cin >> c >> r;
//			farm[r][c] = true;
//		}
//
//		int ans = 0;
//		for (int i = 0; i < R; i++) {
//			for (int j = 0; j < C; j++) {
//				if (farm[i][j] && !visited[i][j]) {
//					ans++;
//					bfs(i, j);
//				}
//			}
//		}
//
//		cout << ans << '\n';
//	}
//
//	return 0;
//}