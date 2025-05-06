#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

using Matrix = vector<vector<char>>;
using Pos = pair<int, int>;

int N; 
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

bool isHeart(Matrix& matrix, int x, int y){
    int cnt = 0;
    for(int i = 0; i < DIR; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(inRange(nx, ny) && matrix[nx][ny] == '*')
            cnt++;
    }

    return cnt == DIR;
}

int main(void){
    fastio;
    cin >> N;

    Matrix matrix(N, vector<char>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    Pos heartPos;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(isHeart(matrix, i, j))
                heartPos = make_pair(i, j);
        }
    }

    int leftArm = 0;
    Pos pos = heartPos;
    while(true){
        pos.second--;
        if(inRange(pos.first, pos.second) && matrix[pos.first][pos.second] == '*')
            leftArm++;
        else
            break;
    }

    int rightArm = 0;
    pos = heartPos;
    while(true){
        pos.second++;
        if(inRange(pos.first, pos.second) && matrix[pos.first][pos.second] == '*')
            rightArm++;
        else
            break;
    }

    int waist = 0;
    pos = heartPos;
    while(true){
        pos.first++;
        if(inRange(pos.first, pos.second) && matrix[pos.first][pos.second] == '*')
            waist++;
        else
            break;
    }

    Pos leftLegPos = make_pair(pos.first-1, pos.second-1);
    Pos rightLegPos = make_pair(pos.first-1, pos.second+1);
    
    // cout << leftLegPos.first << " " << leftLegPos.second << '\n';
    // cout << rightLegPos.first << " " << rightLegPos.second << '\n';

    int leftLeg = 0;
    {
        Pos pos = leftLegPos;

        while(true){
            pos.first++;
            if(inRange(pos.first, pos.second) && matrix[pos.first][pos.second] == '*')
                leftLeg++;
            else
                break;
        }
    }
    

    int rightLeg = 0;
    {
        Pos pos = rightLegPos;

        while(true){
            pos.first++;
            if(inRange(pos.first, pos.second) && matrix[pos.first][pos.second] == '*')
                rightLeg++;
            else
                break;
        }
    }

    cout << heartPos.first+1 << " " << heartPos.second+1 << '\n';
    cout << leftArm << " " << rightArm << " " << waist << " " 
        << leftLeg << " " << rightLeg << '\n';

    return 0;
}