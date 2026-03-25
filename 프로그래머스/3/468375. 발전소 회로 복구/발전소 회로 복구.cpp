#include <bits/stdc++.h>

#define DIR 4
#define INF 1'000'000'000

using namespace std;
using Pos = pair<int, int>;

int N, M, H;
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};
Pos elevatorPos;

// ======= DEBUG FUNCTION =========
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

int Bfs(vector<string>& grid, Pos s, Pos e)
{
    vector<vector<bool>> visited(N, vector<bool>(M));
    
    queue<pair<Pos, int>> q;
    visited[s.first][s.second] = true;
    q.push(make_pair(s, 0));
    
    while(!q.empty())
    {
        pair<Pos, int> cur = q.front(); q.pop();
        Pos curPos = cur.first;
        int moveN = cur.second;
        
        if(curPos == e)
        {
            // printf("s(%d, %d) e(%d, %d) moveN:%d \n", s.first, s.second, e.first, e.second, moveN);
            return moveN;
        }
        
        for(int i = 0; i < DIR; i++)
        {
            int nx = curPos.first + dx[i];
            int ny = curPos.second + dy[i];
            
            if(InRange(nx, ny) && !visited[nx][ny] && grid[nx][ny] != '#')
            {
                Pos nextPos = make_pair(nx, ny);
                
                visited[nx][ny] = true;
                q.push(make_pair(nextPos, moveN+1));
            }
            
        }
    }
}

int GetMinDist(vector<string>& grid, vector<int>& panelPos1, vector<int>& panelPos2)
{
    int f1 = panelPos1[0];
    int r1 = panelPos1[1] - 1;
    int c1 = panelPos1[2] - 1;
    
    int f2 = panelPos2[0];
    int r2 = panelPos2[1] - 1;
    int c2 = panelPos2[2] - 1;
    
    if(f1 == f2)
        return Bfs(grid, make_pair(r1, c1), make_pair(r2, c2));
    else
        return Bfs(grid, make_pair(r1, c1), elevatorPos) + 
                abs(f1 - f2) + 
                Bfs(grid, make_pair(r2, c2), elevatorPos);
    
    return -1;
}

int solution(int h, vector<string> grid, vector<vector<int>> panels, vector<vector<int>> seqs) {
    int answer = 0;
    
    N = grid.size();
    M = grid[0].size();
    H = h;
    
    // Find Elevator Pos.
    for(int r = 0; r < N; r++)
    {
        const string& str = grid[r];
        int c = str.find("@");
        if(c != string::npos)
        {
            elevatorPos = make_pair(r, c);
            break;
        }
    }
    
    // Calculate Panel2Panel MinDist.
    int panelN = panels.size();
    vector<vector<int>> minDist(panelN, vector<int>(panelN));
    for(int i = 0; i < panelN; i++)
    {
        for(int j = i; j < panelN; j++)
        {
            if(i == j)
                minDist[i][j] = 0;
            else
            {
                int dist = GetMinDist(grid, panels[i], panels[j]);
                minDist[i][j] = dist;
                minDist[j][i] = dist;
            }
        }
    }
    
    // for(int i = 0; i < panelN; i++)
    // {
    //     for(int j = 0; j < panelN; j++)
    //     {
    //         cout << minDist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    
    
    // Store preq Pattern.
    vector<int> preActiveMask(panelN);
    for(vector<int>& s : seqs)
    {
        int panel1 = s[0] - 1;
        int panel2 = s[1] - 1;
        
        preActiveMask[panel2] |= 1 << panel1;
    }
    
    // Process DP
    int maxMask = 1 << panelN;
    vector<vector<int>> dp(maxMask, vector<int>(panelN, INF));  // dp[현재 활성화된 패널 비트 패턴][마지막 위치]
    dp[0][0] = 0;
    for(int mask = 0; mask < maxMask; mask++)
    {
        for(int lastPanel = 0; lastPanel < panelN; lastPanel++)
        {
            if(dp[mask][lastPanel] == INF)
                continue;   // No Path.
            
            for(int nextPanel = 0; nextPanel < panelN; nextPanel++)
            {
                int nextMask = mask | (1 << nextPanel);
                if(mask == nextMask)
                    continue;   // Already Activate.

                if( (mask & preActiveMask[nextPanel]) != preActiveMask[nextPanel])
                    continue;   // Not Satisfy preq.
                
                int dist = dp[mask][lastPanel] + minDist[lastPanel][nextPanel];
                dp[nextMask][nextPanel] = min(dp[nextMask][nextPanel], dist); 
            }
        }    
        
    }
        
    answer = *min_element(dp[maxMask-1].begin(), dp[maxMask-1].end());
    
    // for(int mask = 0; mask < maxMask; mask++)
    // {
    //     for(int lastPanel = 0; lastPanel < panelN; lastPanel++)
    //     {
    //         cout << dp[mask][lastPanel] << ' ';
    //     }    
    //     cout << '\n';
    // }
    
    return answer;
}