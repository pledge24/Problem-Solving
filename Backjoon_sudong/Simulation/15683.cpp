#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define CAMERA_TYPE_N 5
#define DIR 4

using namespace std;
using Matrix = vector<vector<int>>;
using Pos = pair<int, int>;
using CameraSight = vector<vector<bool>>;


// 5개 카메라, 방향개수 최대 4개, 4방향에 대한 true/false
#pragma region camData

// 1번 카메라
CameraSight cam1 = {
    {true, false, false, false},
    {false, true, false, false},
    {false, false, true, false},
    {false, false, false, true}
};


// 2번 카메라
CameraSight cam2 = {
    {true, false, true, false},
    {false, true, false, true}
};


// 3번 카메라 
CameraSight cam3 = {
    {true, true, false, false},
    {false, true, true, false},
    {false, false, true, true},
    {true, false, false, true}
};

// 4번 카메라
CameraSight cam4 = {
    {true, true, false, true},
    {true, true, true, false},
    {false, true, true, true},
    {true, false, true, true}
};

// 5번 카메라
CameraSight cam5 = {
    {true, true, true, true}
};

#pragma endregion

vector<CameraSight> cameraSights = {
    { }, cam1, cam2, cam3, cam4, cam5
};
// cameraSights[1][3] => 1번 카메라의 3번 회전 방향의 정보

int N, M; 
// 북 기준 시계방향
int dx[DIR] = {-1, 0, 1, 0};
int dy[DIR] = {0, 1, 0, -1};

struct Camera{
    int type;               // 카메라 타입 (1~5)
    Pos pos;                // 카메라 위치
    int direction = -1;     // 회전 방향 (1~4)
};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void printMatrix(Matrix& matrix){
    for(auto v1 : matrix){
        for(int elem : v1){
            cout << elem << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}

void fillSight(Matrix& matrix, vector<Camera>& cameras){
    for(Camera cam : cameras){ 
        // 현재 카메라 방향
        vector<bool> sight = cameraSights[cam.type][cam.direction];
        Pos camPos = cam.pos;

        // 감시 지역 채우기
        for(int i = 0; i < sight.size();/*DIR = 4*/ i++){
            if(sight[i] == true){
                int nx = camPos.first;
                int ny = camPos.second;

                while(inRange(nx, ny) && (matrix[nx][ny] != 6)){
                    matrix[nx][ny] = -1;
                    nx += dx[i];
                    ny += dy[i];
                    // printMatrix(matrix);
                }
            }
        }
    }

}

int countGrayArea(Matrix& matrix){
    // printMatrix(matrix);

    int cnt = 0;
    for(auto v1 : matrix){
        cnt += count(v1.begin(), v1.end(), 0);
    }

    return cnt;
}

// 작업을 하고 이동한다?
void dfsUtil(Matrix& matrix, vector<Camera>& cameras, int& minN, int camNo){
    if(camNo == cameras.size()){
        // for(Camera cam : cameras){
        //     cout << cam.direction << ' ';
        // }
        // cout << '\n';

        Matrix tempMatrix(matrix);
        fillSight(tempMatrix, cameras);
        // printMatrix(tempMatrix);
        minN = min(minN, countGrayArea(tempMatrix));

        return;
    }

    int camType = cameras[camNo].type;
    for(int dir = 0; dir < cameraSights[camType].size(); dir++){
        cameras[camNo].direction = dir;
        dfsUtil(matrix, cameras, minN, camNo+1);
        cameras[camNo].direction = -1; // check 용
    }
}

// 사각지대의 최소 크기를 반환.
int dfs(Matrix& matrix, vector<Camera>& cameras){
    int minN = INT32_MAX;

    // camNo 회전시킬 카메라 번호.
    dfsUtil(matrix, cameras, minN, 0);

    return minN;
}

int main(void){
    fastio;
    cin >> N >> M;

    Matrix matrix(N, vector<int>(M));
    vector<Camera> cameras;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int num; cin >> num;

            // 1~5는 cctv 종류.
            if(1 <= num && num <= 5)
                cameras.push_back({num, make_pair(i, j)});

            matrix[i][j] = num;
        }
    }

    int ans = dfs(matrix, cameras);

    cout << ans << '\n';

    return 0;
}