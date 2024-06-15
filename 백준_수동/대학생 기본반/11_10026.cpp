//// 2023-10-18
//
//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//#define DIR 4
//
//using namespace std;
//
//vector<vector<int>> canvas;
//vector<vector<bool>> visited;
//int N;
//
//bool inRange(int r, int c) { return (0 <= r && r < N && 0 <= c && c < N); }
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
//			int cur_r = curr_pos.first;
//			int cur_c = curr_pos.second;
//			int nx = cur_r + dx[i];
//			int ny = cur_c + dy[i];
//
//			if (inRange(nx, ny) && canvas[nx][ny] == canvas[cur_r][cur_c] && !visited[nx][ny]) {
//				//cout << "curr pos" << nx << " " << ny << '\n';
//				q.push(make_pair(nx, ny));
//				visited[nx][ny] = true;
//				
//			}
//		}
//
//	}
//
//	return;
//}
//
//int main() {
//	fastio;
//
//	cin >> N;
//	
//	canvas.resize(N, vector<int>(N));
//	visited.resize(N, vector<bool>(N, false));
//
//	char color;
//	for (int r = 0; r < N; r++) {
//		for (int c = 0; c < N; c++) {
//			cin >> color;
//			switch (color)
//			{
//			case 'R':
//				canvas[r][c] = 1;
//				break;
//			case 'G':
//				canvas[r][c] = 2;
//				break;
//			case 'B':
//				canvas[r][c] = 3;
//				break;
//			default:
//				break;
//			}
//
//		}
//	}
//
//	int areas = 0;
//	for (int r = 0; r < N; r++) {
//		for (int c = 0; c < N; c++) {
//			if (!visited[r][c]) {
//				bfs(r, c);
//				areas++;
//			}
//
//		}
//	}
//
//	cout << areas << ' ';
//
//	// 방문 매트릭스 초기화.
//	for (int r = 0; r < N; r++) {
//		for (int c = 0; c < N; c++) {
//			visited[r][c] = false;
//			if (canvas[r][c] == 2) {
//				canvas[r][c] = 1;
//			}
//		}
//	}
//
//	areas = 0;
//	for (int r = 0; r < N; r++) {
//		for (int c = 0; c < N; c++) {
//			if (!visited[r][c]) {
//				bfs(r, c);
//				areas++;
//			}
//
//		}
//	}
//
//	cout << areas << '\n';
//
//	// test print
//	//for (int r = 0; r < N; r++) {
//	//	for (int c = 0; c < N; c++) {
//	//		cout << canvas[r][c] << " ";
//
//	//	}
//	//	cout << '\n';
//	//}
//
//	return 0;
//}