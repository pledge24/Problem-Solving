// 2023-10-24

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 8
using namespace std;

int I, start_r, start_c, end_r, end_c;

//vector<vector<int>> matrix;
//vector<vector<bool>> visited;

bool inRange(int r, int c) {
	return 0 <= r && r < I && 0 <= c && c < I;
}


void bfs(int r, int c) {
	
	int dx[DIR] = { 2, -2, 2, -2, 1, -1, 1, -1 };
	int dy[DIR] = { 1, 1, -1, -1, 2, 2, -2, -2 };//cout << "sssssss" << I << "\n";
	
	vector<vector<int>> matrix(I, vector<int>(I));
	
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	matrix[r][c] = 1;
	//visited[r][c] = true;

	//cout << "while문 진입" << "\n";
	while (!q.empty()) {
		//cout << r << ";;;;; " << c << '\n';
		pair<int, int> p = q.front();
		q.pop();

		int cur_r = p.first;
		int cur_c = p.second;
		for (int i = 0; i < DIR; i++) {
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];
			//cout << nx << ";;;;; " << ny << '\n';
			if (inRange(nx, ny) && !matrix[nx][ny]) {
				//cout << nx << ";;;;; " << ny << '\n';
				q.push(make_pair(nx, ny));
				//visited[nx][ny] = true;
				matrix[nx][ny] = matrix[cur_r][cur_c] + 1;

			}
		}
	}

	//for (int ii = 0; ii < I; ii++) {
	//	for (int jj = 0; jj < I; jj++) {
	//		cout << matrix[ii][jj] << " ";
	//	}
	//	cout << '\n';
	//}

	cout << matrix[end_r][end_c] - 1 << '\n';
}


int main() {
	fastio;
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> I >> start_r >> start_c >> end_r >> end_c;

		//matrix.resize(I, vector<int>(I));
		//for (int i = 0; i < I; i++) {
		//	fill(matrix[i].begin(), matrix[i].end(), 0);
		//}
		
		//visited.resize(I, vector<bool>(I));
		/*for (int i = 0; i < I; i++) {
			fill(visited[i].begin(), visited[i].end(), false);
		}*/
		
		//cout << "BFS진입" << '\n';
		bfs(start_r, start_c);

		/*for (int ii = 0; ii < I; ii++) {
			for (int jj = 0; jj < I; jj++) {
				cout << matrix[ii][jj] << " ";
			}
			cout << '\n';
		}*/

		//cout << end_r << end_c << '\n';
		
	}

	return 0;
}