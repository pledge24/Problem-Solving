#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;
using Matrix = vector<vector<int>>;
using Pos = pair<int, int>;

int dx[DIR] = {0, 1, 0, -1};
int dy[DIR] = {1, 0, -1, 0};

struct rotData{
    int r;
    int c;
    int s;
};

// 왼쪽 위에서 시작해서 시계방향으로 돌린다.
void rotateCW(Matrix& matrix, int r, int c, int rad){

    // 왼쪽 위 시작.
    Pos curPos = make_pair(r-rad, c-rad);
    int prevNum = matrix[curPos.first][curPos.second];

    // rad*2만큼 한 방향 이동, 4번 방향 전환.
    for(int i = 0; i < DIR; i++){
        for(int j = 0; j < rad*2; j++/*j는 반복용*/){
            curPos.first += dx[i];
            curPos.second += dy[i];
            
            swap(prevNum, matrix[curPos.first][curPos.second]);
        }
    }
}

void rotateCCW(Matrix& matrix, int r, int c, int rad){

    // 왼쪽 위 시작.
    Pos curPos = make_pair(r-rad, c-rad);
    int prevNum = matrix[curPos.first][curPos.second];

    // rad*2만큼 한 방향 이동, 4번 방향 전환.
    for(int i = DIR-1; i >= 0; i--){
        for(int j = 0; j < rad*2; j++/*j는 반복용*/){
            curPos.first += dx[i]*-1;
            curPos.second += dy[i]*-1;
            
            swap(prevNum, matrix[curPos.first][curPos.second]);
        }
    }
}

void printMatrix(Matrix& matrix){
    for(auto row : matrix){
        for(auto elem : row){
            cout << elem << ' ';
        }

        cout << '\n';
    }
    cout << '\n';

}
void rotate(Matrix& matrix, int r, int c, int s, bool isCW){
    if(isCW){
        for(int i = 1; i <= s; i++){
            rotateCW(matrix, r, c, i);
        }
    }
    else{
        for(int i = 1; i <= s; i++){
            rotateCCW(matrix, r, c, i);
        }
    }
    
}

void dfsUtil(int& ans, Matrix& matrix, vector<rotData>& rotDataList, vector<bool>& visited, vector<int>& sequence){
    
    if(sequence.size() == visited.size()){
        // for(int elem : sequence){
        //     cout << elem << ' ';
        // }
        // cout << '\n';

        // printMatrix(matrix);


        bool isZeroRow = true;
        for(auto row : matrix){
            if(isZeroRow){
                isZeroRow = false;
                continue;
            }

            int sum = accumulate(row.begin(), row.end(), 0);

            // cout << "sum: " << sum << '\n';

            ans = min(ans, sum);
        }
    }
    
    for(int i = 0; i < visited.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            sequence.push_back(i);
            rotate(matrix, rotDataList[i].r, rotDataList[i].c, rotDataList[i].s, true/*CW*/);
            
            dfsUtil(ans, matrix, rotDataList, visited, sequence);
            
            visited[i] = false;
            sequence.pop_back();
            rotate(matrix, rotDataList[i].r, rotDataList[i].c, rotDataList[i].s, false/*CCW*/);
        }
    }
}

void dfs(int& ans, Matrix& matrix, vector<rotData>& rotDataList){
    vector<bool> visited(rotDataList.size());
    vector<int> sequence;

    dfsUtil(ans, matrix, rotDataList, visited, sequence);
}

int main(void){
    fastio;
    int N, M, K; cin >> N >> M >> K;

    Matrix matrix(N+1, vector<int>(M+1));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> matrix[i][j];
        }
    }

    vector<rotData> rotDataList;
    for(int i = 0; i < K; i++){
        int r, c, s; cin >> r >> c >> s;
        rotDataList.push_back({r, c, s});
    }
    
    int ans = INT32_MAX;
    dfs(ans, matrix, rotDataList);

    cout << ans << '\n';




    return 0;
}