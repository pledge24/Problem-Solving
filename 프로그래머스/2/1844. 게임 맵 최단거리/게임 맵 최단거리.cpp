#include <bits/stdc++.h>

#define DIR 4

using namespace std;
using Pos = pair<int, int>;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};
int N, M;

bool InRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < M;
}

int Bfs(vector<vector<int>>& maps)
{
    N = maps.size();
    M = maps[0].size();
    struct PosData
    {
        int x = 0;
        int y = 0;
        int cnt = 0;
    };
    queue<PosData> q;
    vector<vector<bool>> visited(N, vector<bool>(M));
    Pos dst = make_pair(N-1, M-1);
    
    // Init
    q.push(PosData{0, 0, 1});
    visited[0][0] = true;
    
    // Process
    while(!q.empty())
    {
        PosData cur = q.front(); q.pop();
        
        if(make_pair(cur.x, cur.y) == dst)
        {
            return cur.cnt;
        }
        
        // Next
        for(int i = 0; i < DIR; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if(InRange(nx, ny) && !visited[nx][ny] && maps[nx][ny] == 1)
            {
                // Update
                q.push({nx, ny, cur.cnt+1});
                visited[nx][ny] = true;
            }
        }
    }
        
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
       
    answer = Bfs(maps);
    return answer;
}