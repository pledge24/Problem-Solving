#include <bits/stdc++.h>

using namespace std;
using Pos = pair<int, int>;

int answer = 0;
int N = 0;

bool CanPut(vector<Pos>& posList, Pos newPos)
{
    int x1 = newPos.first;
    int y1 = newPos.second;
    
    for(Pos& pos : posList)
    {
        int x2 = pos.first;
        int y2 = pos.second;
        
        // 세로
        if(y1 == y2)
            return false;
        
        // 대각선
        if(abs(x1 - x2) == abs(y1 - y2))
            return false;
    }
    
    return true;
}

void DfsUtil(vector<Pos>& posList)
{
    if(posList.size() == N)
    {
        answer++;
                
        // vector<vector<bool>> board(N, vector<bool>(N));
//         for(Pos x : posList)
//         {
//             board[x.first][x.second] = true;
//         }
        
//         for(int i = 0; i < 4; i++)
//         {
//             for(int j = 0; j < 4; j++)
//             {
//                 cout << board[i][j] << ' ';
//             }
//             cout << '\n';
//         }
        return;
    }
    
    int nextRow = posList.size();
    for(int c = 0; c < N; c++)
    {
        Pos nPos = make_pair(nextRow, c);
        if(CanPut(posList, nPos))
        {
            posList.push_back(nPos);
            DfsUtil(posList);
            posList.pop_back();
        }
    }
}

void Dfs(int n)
{
    vector<Pos> posList;
    DfsUtil(posList);
}

int solution(int n) {
    N = n;
    
    Dfs(n);
    
    return answer;
}