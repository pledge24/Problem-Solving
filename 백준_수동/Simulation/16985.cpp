// 5 X 5 X 5인 3차원 미로가 존재
// 2차원 미로는 회전 시킬 수 있으며, 순서를 바꿔 쌓을 수 있다.
// 최적의 미로에서의 최소 이동 횟수는?

// 5개의 판을 회전시킨 경우의 수 4^5 = 2^10 = 1024
// 5개의 판을 배열하는 경우의 수 5! = 120
// 모든 경우의 수 => 1024*120 '=. 100,000

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define N 5
#define DIR 4
#define DIR3D 6

using namespace std;
using Matrix = vector<vector<int>>;
using Cube = vector<Matrix>;
using Order = vector<int>;

vector<Order> orders;
int dx[DIR3D] = {1, 0, -1, 0, 0, 0};
int dy[DIR3D] = {0, 1, 0, -1, 0, 0};
int dz[DIR3D] = {0, 0, 0, 0, 1, -1};

static int Scnt = 0;

struct PosData{
    int x;
    int y;
    int z;
    int moveN = 0;
};

void printMatrix(Matrix& matrix){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void rotate(Matrix& matrix){
    Matrix temp = matrix;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp[j][N-1-i] = matrix[i][j];
        }
    }

    swap(matrix, temp);
}

void dfsUtil(vector<Order>& orders, vector<bool>& visited, vector<int> curOrder){
    if(curOrder.size() == N){
        orders.push_back(curOrder);
        return;
    }

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            curOrder.push_back(i);
            visited[i] = true;
            dfsUtil(orders, visited, curOrder);
            curOrder.pop_back();
            visited[i] = false;
        }
    }
}

void generateOrder(vector<Order>& orders){
    vector<int> curOrder;
    vector<bool> visited(N);
    dfsUtil(orders, visited, curOrder);
}

bool inRange(int x, int y, int z){
    return 0 <= x && x < N && 0 <= y && y < N && 0 <= z && z < N;
}

void bfs(int& ans, Cube& cube){
    Scnt++;

    if(cube[0][0][0] == 0 || cube[N-1][N-1][N-1] == 0){
        return;
    }

    queue<PosData> q;
    q.push({0, 0, 0, 0});
    cube[0][0][0] = 0;

    while(!q.empty()){
        PosData cur = q.front(); q.pop();

        for(int i = 0; i < DIR3D; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];

            if(inRange(nx, ny, nz) && cube[nx][ny][nz] == 1){
                if(nx == N-1 && ny == N-1 && nz == N-1){
                    ans = min(ans, cur.moveN+1);
                    return;
                }
                q.push({nx, ny, nz, cur.moveN+1});
                cube[nx][ny][nz] = 0;
            }
        }
    }
}

void findMinDist(int& ans, Cube& cube, vector<vector<Matrix>>& rotData, vector<int>& curRotOrder){
    Cube curCube(N);
    
    for(auto order : orders){ // 5!
        for(int i = 0; i < N; i++){
            curCube[i] = rotData[order[i]][curRotOrder[i]];
        }
        bfs(ans, curCube);
    }
}

void simulate(int& ans, Cube& cube, vector<vector<Matrix>>& rotData){
    // generate matrix orders
    generateOrder(orders);

    vector<int> curRotOrder(N);
    int cases = DIR*DIR*DIR*DIR*DIR;
    for(int i = 0; i < cases; i++){
        curRotOrder[0]++;
        int idx = 0;
        while(curRotOrder[idx] >= DIR){
            curRotOrder[idx] %= DIR;
            curRotOrder[idx+1]++;
            idx++;
        }

        findMinDist(ans, cube, rotData, curRotOrder);
    }

}

int main(void){
    fastio;
    
    Cube cube(N);
    for(int i = 0; i < N; i++){
        Matrix matrix(N, vector<int>(N));
        for(int j = 0; j < N*N; j++){
            int x = j / N;
            int y = j % N;

            cin >> matrix[x][y];
        }
        cube[i] = matrix;
    }

    // store rotData.(0, 90, 180, 270)
    vector<vector<Matrix>> rotData(N, vector<Matrix>(DIR));
    for(int i = 0; i < N; i++){
        Matrix curMatrix = cube[i];
        for(int dir = 0; dir < DIR; dir++){
            rotData[i][dir] = curMatrix;
            rotate(curMatrix);
        }
    }

    // print RotData
    // for(int i = 0; i < N; i++){
    //     cout << "====================\n";
    //     for(int j = 0; j < DIR; j++){
    //         Matrix matrix = rotData[i][j];
    //         printMatrix(matrix);
    //     }
    // }

    
    int ans = INT32_MAX;
    simulate(ans, cube, rotData);

    if(ans == INT32_MAX)
        ans = -1;

    cout << ans << '\n';

    // cout << "Scnt " << Scnt << '\n';
    return 0;
}