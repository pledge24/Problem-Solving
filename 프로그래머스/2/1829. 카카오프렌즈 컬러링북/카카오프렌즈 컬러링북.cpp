#include <bits/stdc++.h>

#define DIR 4

using namespace std;
using Pos = pair<int, int>;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};
int M, N;

bool InRange(int x, int y)
{
    return 0 <= x && x < M && 0 <= y && y < N;
}

int Bfs(vector<vector<int>>& picture, vector<vector<bool>>& visited, int curX, int curY)
{
    int color = picture[curX][curY];
    int cnt = 0;
    queue<Pos> q;
    
    // Init
    visited[curX][curY] = true;
    cnt++;
    q.push(make_pair(curX, curY));
    
    // Process
    while(!q.empty())
    {
        Pos cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        
        for(int i = 0; i < DIR; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(InRange(nx, ny) && !visited[nx][ny] && (picture[nx][ny] == color))
            {
                visited[nx][ny] = true;
                cnt++;
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    return color > 0 ? cnt : 0;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    M = m;
    N = n;
    
    vector<vector<bool>> visited(m, vector<bool>(n));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                int areas = Bfs(picture, visited, i, j);
                if(areas > 0)
                {
                    number_of_area++;
                    max_size_of_one_area = max(max_size_of_one_area, areas);
                }
                
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    // 1 1 1 0
    // 1 1 1 0
    // 0 0 0 1
    // 0 0 0 1
    // 0 0 0 1
    // 0 0 0 1
    return answer;
}