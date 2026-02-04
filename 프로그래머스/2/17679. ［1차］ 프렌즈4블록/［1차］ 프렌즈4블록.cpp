#include <bits/stdc++.h>

using namespace std;

bool Simulate(vector<string>& board, int m, int n, int& answer)
{
    vector<string> temp = board;
    set<pair<int, int>> s1;
    
    // Find
    for(int r = 0; r < m-1; r++)
    {
        for(int c = 0; c < n-1; c++)
        {
            char curC = board[r][c];
            if(curC == '.')
                continue;
            
            if((board[r+1][c] == curC) && (board[r][c+1] == curC) && (board[r+1][c+1] == curC))
            {
                temp[r][c] = '.';
                temp[r+1][c] = '.';
                temp[r][c+1] = '.';
                temp[r+1][c+1] = '.';
                
                s1.insert(make_pair(r, c));
                s1.insert(make_pair(r+1, c));
                s1.insert(make_pair(r, c+1));
                s1.insert(make_pair(r+1, c+1));
            }
        }
    }
    
    // Simulate
    for(int i = m-1; i >= 0; i--)
    {
        for(int j = 0; j <= n; j++)
        {
            char curC = temp[i][j];
            pair<int, int> pos = make_pair(i, j);
            
            if(curC == '.')
                continue;
            
            while(pos.first < (m - 1) && temp[pos.first+1][pos.second] == '.')
            {
                temp[pos.first][pos.second] = '.';
                temp[pos.first + 1][pos.second] = curC;
                pos.first++;
            }
        }
    }
    
    // Apply
    answer += s1.size();
    board.swap(temp);
    
    return s1.size() > 0;
}

// 지워지는 블록의 개수를 구해라.
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    // for(string s : board)
    // {
    //     cout << s << '\n';
    // }
    
    while(Simulate(board, m, n, answer))
    {
        // for(string s : board)
        // {
        //     cout << s << '\n';
        // }
    }
    
    return answer;
}