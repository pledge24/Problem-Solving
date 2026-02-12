#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4
#define MAXN 2001

using namespace std;
using Matrix = int[MAXN][MAXN];
using Pos = pair<int, int>;
using Mane = vector<Pos>;

enum { NONE=0, WALL, CHAIR, MANE, START, MANE_INRANGE, VISITED};

int N, M;
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};
Pos nullPos = make_pair(-1, -1);
Matrix matrix = {0};
Matrix maneMatrix = {0};

struct MoveData{
	Pos pos;
	int moveN = 0;
};

bool inRange(int x, int y){
	return 0 <= x && x < N && 0 <= y && y < M; 
}

void InitManeMatrix(Matrix& maneMatrix, Mane& manes, int K){

	// based on BFS
	queue<MoveData> q;
	for(Pos pos : manes){
		q.push({pos, 0});
		maneMatrix[pos.first][pos.second] = MANE_INRANGE;
	}

	while(!q.empty()){
		MoveData moveData = q.front(); q.pop();
		Pos pos = moveData.pos;
		int moveN = moveData.moveN;

		for(int i = 0; i < DIR; i++){
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if(inRange(nx, ny) && moveN+1 <= K && maneMatrix[nx][ny] != MANE_INRANGE){
				/*Only-push promising*/
				if(moveN + 1 < K)
					q.push({ make_pair(nx, ny), moveN+1 });

				maneMatrix[nx][ny] = MANE_INRANGE;
			}
		}
	}
}

// void printMatrix(Matrix& matrix){
// 	cout << '\n';
// 	for(auto row : matrix){
// 		for(int elem : row){
// 			cout << elem << ' ';
// 		}
// 		cout << '\n';
// 	}
// 	cout << '\n';
// }

int bfs(Matrix& matrix, Matrix& maneMatrix, Pos startPos, Pos endPos){

	if(startPos == nullPos || endPos == nullPos)
		return -1;

	queue<MoveData> q;
	q.push({startPos, 0});
	matrix[startPos.first][startPos.second] = VISITED;

	while(!q.empty()){
		MoveData moveData = q.front(); q.pop();
		Pos pos = moveData.pos;
		int moveN = moveData.moveN;

		for(int i = 0; i < DIR; i++){
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if(inRange(nx, ny) && (matrix[nx][ny] == NONE || matrix[nx][ny] == CHAIR)){
				
				if(maneMatrix[nx][ny] != MANE_INRANGE){
					if(matrix[nx][ny] == CHAIR)
						return moveN+1;	

					q.push({make_pair(nx, ny), moveN+1});
					matrix[nx][ny] = VISITED;
				}
			}
		}
	}

	return -1;
}

int main(void){
	fastio; 
	int K; cin >> N >> M >> K;

	Pos startPos = nullPos, endPos = nullPos;
	Mane manes;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int num; cin >> num;
			/* memory special data*/
			switch (num)
			{
			case CHAIR:
				endPos = make_pair(i, j);
				break;
			case MANE:
				manes.push_back(make_pair(i, j));
				break;
			case START:
				startPos = make_pair(i, j);
				break;			
			default:
				break;
			}

			matrix[i][j] = num;
		}
	}

	InitManeMatrix(maneMatrix, manes, K);
	// printMatrix(maneMatrix);

	// find minDist
	int ans = bfs(matrix, maneMatrix, startPos, endPos);
	// printMatrix(matrix);

	cout << ans << '\n';

	return 0;
}