#include <bits/stdc++.h>

#define fastio cin.tie(nullptr)->sync_with_stdio(false)
#define SHARK 9 
#define VISITED -1
#define DIR 4

using namespace std;
using Matrix = vector<vector<int>>;
using Pos = pair<int, int>; // posX, posY
using MoveData = pair<Pos, int>; // fishPos, moveCost

int N; 
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, -1, 0, 1};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

// 상하좌우 이동
// 먹을 수 있는 물고기 중 왼쪽 위 물고기 우선.
MoveData findFish(Matrix matrix/*duplicate*/, Pos sharkPos, int sharkSize){
    vector<Pos> edibleFish;
    int timeCost = 0;
    queue<Pos> q;
    q.push(sharkPos);
    matrix[sharkPos.first][sharkPos.second] = VISITED;

    // 먹을 수 있는 물고기가 있을때까지 반복.
    while(edibleFish.empty()){
        timeCost++;
        queue<Pos> tempQ;

        // timeCost만큼 이동 cost가 드는 위치를 저장하는 q.
        while(!q.empty()){
            Pos pos = q.front(); q.pop();

            for(int i = 0; i < DIR; i++){
                int nx = pos.first + dx[i];
                int ny = pos.second + dy[i];

                if(inRange(nx, ny) && matrix[nx][ny] != VISITED){
                    // can eat
                    if(0 < matrix[nx][ny] && matrix[nx][ny] < sharkSize){
                        edibleFish.push_back(make_pair(nx, ny));

                    }

                    // can move
                    if(0 <= matrix[nx][ny] && matrix[nx][ny] <= sharkSize){
                        tempQ.push(make_pair(nx, ny));
                        matrix[nx][ny] = VISITED;
                    }

                }

            }
        }

        swap(q, tempQ);

        // 더이상 이동할 공간이 없음.
        if(q.empty()){
            return {make_pair(-1, -1), -1};
        }
             
    }

    // cout << "check\n " << timeCost;

    // 먹을 수 있는 물고기들 왼쪽 위 기준 오름차순 정렬.
    sort(edibleFish.begin(), edibleFish.end());

    return {edibleFish[0], timeCost};
}

void printMatrix(Matrix& matrix){
    for(auto rows : matrix){
        for(auto col : rows){
            cout << col << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void simulate(Matrix& matrix, Pos sharkPos, int& t){

    int sharkSize = 2; // default size is 2
    int eatFishes = 0;

    while(true){
        MoveData next = findFish(matrix, sharkPos, sharkSize);
        if(next.first == make_pair(-1, -1))
            return;

        // update board
        Pos nextPos = next.first;
        matrix[sharkPos.first][sharkPos.second] = 0;
        matrix[nextPos.first][nextPos.second] = SHARK;

        // updata etc data
        sharkPos = nextPos;
        eatFishes++;
        if(eatFishes == sharkSize){
            sharkSize++;
            eatFishes = 0;
        }
        t += next.second;

        // printMatrix(matrix);
        // cout << "curSharkSize: " << sharkSize << '\n';
    }
}

int main(void){
    fastio;
    cin >> N;

    Matrix matrix(N, vector<int>(N));
    Pos sharkPos;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int num; cin >> num;
            
            if(num == SHARK)
                sharkPos = make_pair(i, j);
              
            matrix[i][j] = num;
        }
    }

    int t = 0;
    simulate(matrix, sharkPos, t);

    cout << t << '\n';

    return 0;
}