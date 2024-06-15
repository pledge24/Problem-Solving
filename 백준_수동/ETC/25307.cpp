#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

#define CHAIR 2
#define MANE 3
#define START 4
#define WALL 5
#define SIGHT 9
using namespace std;

vector<vector<int>> matrix;
vector<vector<int>> visited;
vector<pair<int, int>> mane;

queue<pair<int, int>> q;

int N, M, K;
int dx[DIR] = { 1, 0, -1, 0 };
int dy[DIR] = { 0, 1, 0, -1 };
int cnt = 1;
int min_cnt = -1;

bool canInstall(int x, int y) {
	return (matrix[x][y] != WALL) && (matrix[x][y] != MANE);
}

bool inRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

bool isMove(int x, int y) {
	return (matrix[x][y] != WALL) && (matrix[x][y] != MANE) && (matrix[x][y] != SIGHT);
}

void install_bfs(int mane_r, int mane_c) {
	queue<pair<int, int>> qq;
	qq.push(make_pair(mane_r, mane_c));
	vector<vector<int>> install_visited(N, vector<int>(M));

	while (!qq.empty()) {

		pair<int, int> p = qq.front();
		qq.pop();

		int cur_r = p.first;
		int cur_c = p.second;

		//cout << cur_r << " " << cur_c << '\n';
		
		for (int i = 0; i < DIR; i++) {
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];

			int distance = abs(nx - mane_r) + abs(ny - mane_c);
			
			//cout << inRange(nx, ny) << " " << (distance <= K) << " " << (matrix[nx][ny] == MANE) << '\n';
			if (inRange(nx, ny) && !install_visited[nx][ny] && distance <= K && canInstall(nx, ny)) {
				matrix[nx][ny] = SIGHT;
				install_visited[nx][ny] = true;
				qq.push(make_pair(nx, ny));
				//cout << "s" << '\n';
			}
		}
	}

}
void applyManeSight() {
	for (pair<int, int> pos : mane) {
		//cout << pos.first << " " << pos.second << '\n';
		install_bfs(pos.first, pos.second);
	}
}

void bfs() {

	while (!q.empty()) {

		pair<int, int> p = q.front();
		q.pop();

		int cur_r = p.first;
		int cur_c = p.second;


		for (int i = 0; i < DIR; i++) {
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];

			if (inRange(nx, ny) && isMove(nx, ny) && !visited[nx][ny]) {
				if (matrix[nx][ny] == CHAIR) {

					visited[nx][ny] = visited[cur_r][cur_c] + 1;
					min_cnt = visited[nx][ny];
					return;
				}
				q.push(make_pair(nx, ny));
				visited[nx][ny] = visited[cur_r][cur_c] + 1;
				//cout << visited[nx][ny] << '\n';
			}
		}
	}
	
	return;
}

int main() {
	fastio;

	cin >> N >> M >> K;
	
	matrix.resize(N, vector<int>(M));
	visited.resize(N, vector<int>(M));

	int start_r = -1, start_c = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];

			switch (matrix[i][j])
			{
			case MANE:
				mane.push_back(make_pair(i, j));
				break;
			//case CHAIR:
			//	chair_r = i;
			//	chair_c = j;
			//	break;
			case START:
				start_r = i;
				start_c = j;
				break;
			default:
				break;
			}

		}
	}

	visited[start_r][start_c] = -1;
	for (int i = 0; i < DIR; i++) {
		int nx = start_r + dx[i];
		int ny = start_c + dy[i];

		if (inRange(nx, ny) && isMove(nx, ny)) {
			if (matrix[nx][ny] == CHAIR) {
				cout << "1" << '\n';
				return 0;
			}
			//cout << nx << " " << ny << '\n';
			q.push(make_pair(nx, ny));
			visited[nx][ny] = 1;			
		}
	}

	applyManeSight();
	bfs();

	// install sight print test
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		//cout << matrix[i][j] << ' ';
	//		cout << visited[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}


	cout << min_cnt << '\n';
	//cout << visited
	return 0;
}

//5 5 1
//0 0 0 0 0
//0 0 0 1 0
//0 0 0 0 3
//0 0 0 1 0
//0 0 0 4 2