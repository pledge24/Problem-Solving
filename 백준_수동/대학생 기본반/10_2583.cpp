// 2023-10-18

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

int M, N, K;
vector<vector<int>> mat;
vector<vector<bool>> visited;
vector<int> area_size;

bool inRange(int r, int c) { return (0 <= r && r < M && 0 <= c && c < N); }

void bfs(int r, int c) {
	int size = 0;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	
	// 큐를 생성하고 시작 노드를 큐에 추가
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));

	// 시작 노드를 방문한 것으로 표시
	visited[r][c] = true;
	size++;

	while (!q.empty()) {
		// 큐에서 하나의 노드를 꺼내 출력
		pair<int, int> curr_pos = q.front();
		q.pop();

		// 해당 노드의 인접한 노드들을 방문
		for (int i = 0; i < DIR; i++) {
			int nx = curr_pos.first + dx[i];
			int ny = curr_pos.second + dy[i];

			if (inRange(nx, ny) && mat[nx][ny] == 0 && !visited[nx][ny]) {
				//cout << "curr pos" << nx << " " << ny << '\n';
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				size++;
			}
		}

	}

	area_size.push_back(size);

	return;
}
int main() {
	fastio;

	cin >> M >> N >> K;

	mat.resize(M, vector<int>(N, 0));
	visited.resize(M, vector<bool>(N, false));

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				mat[y][x] = 1;
			}
		}
		
	}

	int x = 0, y = 0;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			
			if (mat[y][x] == 0 && !visited[y][x]) {
				bfs(y, x);
			}
		}		
	}

	cout << area_size.size() << '\n';

	sort(area_size.begin(), area_size.end());
	for (int size : area_size) {
		cout << size << " ";
	}
	cout << '\n';

	//// test print
	//for (int y = 0; y < M; y++) {
	//	for (int x = 0; x < N; x++) {
	//		cout << mat[y][x] << " ";
	//	}
	//	cout << '\n';
	//}

	return 0;
}