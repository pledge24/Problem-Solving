#include <bits/stdc++.h>

#define DIR 4
#define INF 100'000'000

using namespace std;
using Pos = pair<int, int>;
using Res = pair<bool, int>;    // <win, count>

int N, M;
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool InRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < M;
}

Res Backtracking(vector<vector<int>>& board, Pos myPos, Pos opPos)
{
    // 현재 위치의 발판이 이미 사라졌다면 패배
    if (board[myPos.first][myPos.second] == 0) return {false, 0};
    
    bool canWin = false;
    int minCount = INF;
    int maxCount = 0;
    bool canMove = false;
    
    for(int i = 0; i < DIR; i++)
    {
        int nx = myPos.first + dx[i];
        int ny = myPos.second + dy[i];
        Pos nextPos = make_pair(nx, ny);
        
        if(InRange(nx, ny) && board[nx][ny] == 1)
        {
            canMove = true;
            
            board[myPos.first][myPos.second] = 0;
            Res res = Backtracking(board, opPos, nextPos);
            board[myPos.first][myPos.second] = 1;
            
            bool opWin = res.first;
            if(!opWin)
            {
                canWin = true;
                minCount = min(minCount, res.second + 1);
            }
            else
            {
                maxCount = max(maxCount, res.second + 1);
            }
        }
    }
    
    // 2. 더 이상 갈 곳이 없다면 패배
    if (!canMove) return {false, 0};
    
    // 3. 승리할 수 있다면 최소 횟수, 질 수밖에 없다면 최대 횟수 반환
    if (canWin) return {true, minCount};
    
    return {false, maxCount};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    
    N = board.size();
    M = board[0].size();
    Pos posA = make_pair(aloc[0], aloc[1]);
    Pos posB = make_pair(bloc[0], bloc[1]);
    
    Res res = Backtracking(board, posA, posB);   // A가 먼저 시작.
    
    answer = res.second;
    
    return answer;
}