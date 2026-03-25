#include <bits/stdc++.h>

#define DIR 4

using namespace std;
using Pos = pair<int, int>;

int N, M;
int dx[DIR] = {0, 1, 0, -1};
int dy[DIR] = {1, 0, -1, 0};

struct AppData
{
    Pos minPos;
    int len = 1;
};

map<int, AppData> appTable; // <id, AppData>

// === DEBUG FUNCTION ===
void PrintBoard(vector<vector<int>>& board)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool InRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < M;
}

void Simulate(vector<vector<int>>& board, int seedId, int arrow)
{
    arrow--; // dx dy에 맞추기 용도.
    int cnt = 0;
    while(seedId > 0)
    {
        // 1. Find Pushed App(Using BFS).
        // 반대편으로 넘어가서 연결되는 앱도 포함한다.
        set<int> pushApp = {seedId};
        {
            vector<vector<bool>> visited(N, vector<bool>(M));
            Pos startPos = appTable[seedId].minPos;
            
            queue<Pos> q;
            // Init.
            q.push(startPos);
            visited[startPos.first][startPos.second] = true;
            
            // Process BFS
            while(!q.empty())
            {
                Pos cur = q.front(); q.pop();
                
                for(int i = 0; i < DIR; i++)
                {
                    int nx = (cur.first + N + dx[i]) % N;
                    int ny = (cur.second + M + dy[i]) % M;
                    int nextId = board[nx][ny];
                    
                    if(visited[nx][ny] || nextId == 0)
                        continue;
                    
                    // 방향이 같으면 항상 이동 가능,
                    // 방향이 다르면 미는 앱으로 등록된 곳만 이동 가능
                    if(i == arrow || pushApp.find(nextId) != pushApp.end())
                    {
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                        pushApp.insert(nextId);
                    }
                }
                
            }
            
            
        }
        
        // for(int x : pushApp)
        //     cout << x << " ";
        // cout << '\n';
        
        // 2. 보드를 "한 칸"씩 민 결과로 갱신한다.
        vector<vector<int>> nextBoard(N, vector<int>(M));
        for(auto& p : appTable)
        {
            int appId = p.first;
            AppData& app = p.second;
            Pos& minPos = app.minPos;
            int len = app.len;
            
            if(pushApp.find(appId) != pushApp.end())
            {
                minPos.first = (minPos.first + N + dx[arrow]) % N;
                minPos.second = (minPos.second + M + dy[arrow]) % M;
            }
            
            // Draw App
            for(int i = 0; i < len; i++)
            {
                for(int j = 0; j < len; j++)
                {
                    nextBoard[(minPos.first + i) % N][(minPos.second + j) % M] = appId;
                }
            }
        }
        board.swap(nextBoard);
                
        // 3. 잘린 앱이 있다면 다음 시드id로 활용한다.
        int nextSeedId = -1;
        for(auto p : appTable)
        {
            int appId = p.first;
            AppData& app = p.second;
            Pos& minPos = app.minPos;
            int len = app.len;
            
            // 잘린 앱인지 판단.(잘린앱은 범위를 벗어나있음)
            Pos maxPos = make_pair(minPos.first + len - 1, minPos.second + len - 1);
            if(!InRange(maxPos.first, maxPos.second) ||
               board[maxPos.first][maxPos.second] != appId)
            {
                // cout << "appId: " << appId << '\n';
                // cout << "maxPos: " << maxPos.first << " " << maxPos.second << '\n';
                nextSeedId = appId;
                break;
            }
            
        }
        
        seedId = nextSeedId;
    }
}

vector<vector<int>> solution(vector<vector<int>> board, vector<vector<int>> commands) {
    vector<vector<int>> answer;
    
    N = board.size();
    M = board[0].size();
    
    // Find All App In Board.
    for(int i = 0; i < N; i++)
    {
        Pos minPos;
        int prevId = -1;
        int cnt = 0;
        for(int j = 0; j < M; j++)
        {
            if(prevId == board[i][j])
            {
                cnt++;
            }
            else
            {
                if(prevId > 0 && appTable.find(prevId) == appTable.end())
                    appTable[prevId] = {minPos, cnt};
                
                minPos = make_pair(i, j);
                cnt = 1;
            }
            
            prevId = board[i][j];
        }
        
        // Last Result Check
        if(prevId > 0 && appTable.find(prevId) == appTable.end())
            appTable[prevId] = {minPos, cnt};
    }
    
//     PrintBoard(board);
    
//     for(auto p : appTable)
//     {
//         int id = p.first;
//         AppData appdata = p.second;
//         printf("id: %d, minPos:(%d, %d), len:%d \n", id, appdata.minPos.first, appdata.minPos.second, appdata.len);
//     }
    
    // Process Commands.
    for(const vector<int>& cmd : commands)
    {
        int id = cmd[0];
        int arrow = cmd[1];
        Simulate(board, id, arrow);
        // PrintBoard(board);
    }
    
    answer = board;
    
    return answer;
}