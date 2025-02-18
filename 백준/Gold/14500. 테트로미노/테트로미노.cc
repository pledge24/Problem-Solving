#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using minoOffset = vector<pair<int ,int>>;

int N, M; 
vector<minoOffset> minos = {
    // I mino
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},  
    // O mino
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    // L mino
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    {{0, 0}, {-1, 0}, {-2, 0}, {-2, -1}},
    {{0, 0}, {0, -1}, {0, -2}, {1, -2}},
    // J mino 
    {{0, 0}, {1, 0}, {2, 0}, {2, -1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {-1, 0}, {-2, 0}, {-2, 1}},
    {{0, 0}, {0, -1}, {0, -2}, {-1, -2}},
    // S mino
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    // Z mino
    {{0, 0}, {1, 0}, {1, -1}, {2, -1}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    // T mino
    {{0, 0}, {1, 0}, {-1, 0}, {0, 1}},
    {{0, 0}, {1, 0}, {-1, 0}, {0, -1}},
    {{0, 0}, {1, 0}, {0, 1}, {0, -1}},
    {{0, 0}, {-1, 0}, {0, 1}, {0, -1}}
};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

int getMaxNum(vector<vector<int>> &matrix, int x, int y){

    int maxNum = 0;
    for(int i = 0; i < minos.size(); i++){

        int sum = 0;
        for(pair<int, int> p : minos[i]){
            int nx = x + p.first;
            int ny = y + p.second;
            
            if(!inRange(nx, ny)){
                sum = 0;
                break;
            }
            sum += matrix[nx][ny];
        }

        maxNum = max(maxNum, sum);
    }

    return maxNum;
}

int main(void){
    fastio;

    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int maxNum = getMaxNum(matrix, i, j);
            ans = max(maxNum, ans);
        }
    }

    cout << ans << '\n';

    return 0;
}