// 2023-10-18

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

int N;
vector<vector<int>> mat;
vector<vector<bool>> visited;
vector<int> area_size;

bool inRange(int r, int c) { return (0 <= r && r < N && 0 <= c && c < N); }

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

			if (inRange(nx, ny) && mat[nx][ny] && !visited[nx][ny]) {
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

	cin >> N;

	mat.resize(N, vector<int>(N, 0));
	visited.resize(N, vector<bool>(N, false));

	char cc;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> cc;

			mat[r][c] = cc - '0';
		}
	}
		
	

	int x = 0, y = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			
			if (mat[y][x] && !visited[y][x]) {
				bfs(y, x);
			}
		}		
	}

	cout << area_size.size() << '\n';

	sort(area_size.begin(), area_size.end());
	for (int size : area_size) {
		cout << size << '\n';
	}

	//// test print
	//for (int y = 0; y < N; y++) {
	//	for (int x = 0; x < N; x++) {
	//		cout << mat[y][x] << " ";
	//	}
	//	cout << '\n';
	//}

	return 0;
}