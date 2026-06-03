#include <bits/stdc++.h>

#define DIR 8

int N;
int dx[DIR] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[DIR] = {0, 1, 1, 1, 0, -1, -1, -1};

using namespace std;

bool InRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N; 
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    N = board.size();
    vector<vector<int>> next(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j])
            {
                next[i][j] = board[i][j];
                for(int d = 0; d < DIR; d++)
                {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    
                    if(InRange(nx, ny))
                        next[nx][ny] = 1;
                }
            }
        }
    }
    
    // for(int i = 0; i < N; i++)
    // {
    //     for(int j = 0; j < N; j++)
    //     {
    //         cout << next[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    int danger = 0;
    for(int i = 0; i < N; i++)
    {
        vector<int>& rows = next[i];
        danger += std::count(rows.begin(), rows.end(), 1);
    }
    
    answer = N*N - danger;
    
    return answer;
}