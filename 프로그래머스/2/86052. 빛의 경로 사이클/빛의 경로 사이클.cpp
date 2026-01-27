#include <bits/stdc++.h>

#define DIR 4

// 북-동-남-서(시계방향)
int dx[DIR] = {-1, 0, 1, 0};
int dy[DIR] = {0, 1, 0, -1};

struct GridData
{
    char c;
    bool visited[DIR] = {false, false, false, false};   // input이 기준
};

struct MoveData
{
    int r;
    int c;
    int dir;
};

using namespace std;
using Matrix = vector<vector<GridData>>;
using Pos = pair<int, int>;

bool HasArrive(Matrix& matrix, MoveData& md)
{
    GridData gd = matrix[md.r][md.c];
    return gd.visited[md.dir];
}

MoveData GetNextPos(char c, MoveData& cur, int R, int C)
{
    MoveData next;
    int moveDir = (cur.dir + 2) % DIR;
    
    if(c == 'S')
    {
        int nx = cur.r + dx[moveDir];
        int ny = cur.c + dy[moveDir];
        
        next = {nx, ny, (moveDir + 2) % DIR};
    }
    else if(c == 'R')
    {
        moveDir = (moveDir + 1) % DIR;
        
        int nx = cur.r + dx[moveDir];
        int ny = cur.c + dy[moveDir];
        
        next = {nx, ny, (moveDir + 2) % DIR};
    }
    else if(c == 'L')
    {
        moveDir = moveDir - 1 >= 0 ? moveDir - 1 : DIR-1;
        
        int nx = cur.r + dx[moveDir];
        int ny = cur.c + dy[moveDir];
        
        next = {nx, ny, (moveDir + 2) % DIR};
    }

    if(next.r < 0)
        next.r = R-1;
    if(next.r >= R)
        next.r = 0;
    
    if(next.c < 0)
        next.c = C-1;
    if(next.c >= C)
        next.c = 0;
    
    return next;
}

int StartCycle(Matrix& matrix, MoveData cur)
{
    int R = matrix.size();
    int C = matrix[0].size();
    int len = 0;
    // printf("pos(%d, %d), dir: %d\n", cur.r, cur.c, cur.dir);
    while(!HasArrive(matrix, cur))
    {
        // 방문 처리
        GridData& gd = matrix[cur.r][cur.c];
        gd.visited[cur.dir] = true;
        len++;
        
        // 다음 방향
        cur = GetNextPos(gd.c, cur, R, C);
        // printf("pos(%d, %d), dir: %d\n", cur.r, cur.c, cur.dir);
    }
    
    // cout << len << '\n';
        
    return len;
}
    
// 만들어지는 모든 사이클들의 길이를 배열에 담아 반환하자.
// 1. 모든 이동은 반드시 순환이 발생한다.
// 2. 같은 방향의 input이 들어왔을때만 동일한 output이 발생한다.
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int R = grid.size();
    int C = grid[0].size();
    
    // Init
    Matrix matrix(R, vector<GridData>(C));
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            GridData& gd = matrix[i][j];
            gd.c = grid[i][j];
        }
    }
        
    // Process
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            GridData& gd = matrix[i][j];
            for(int dir = 0; dir < DIR; dir++)
            {
                if(gd.visited[dir])
                    continue;
                
                int len = StartCycle(matrix, {i, j, dir});  // i,j 위치를 dir 방향으로 들어왔다.
                answer.push_back(len);
            }
        }
    }
    
    std::sort(answer.begin(), answer.end());
    
    return answer;
}