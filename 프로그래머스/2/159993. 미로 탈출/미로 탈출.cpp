#include <bits/stdc++.h>

#define DIR 4

using namespace std;
using Matrix = vector<vector<char>>;
using Pos = pair<int, int>;

int R, C;
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool InRange(int x, int y)
{
    return 0 <= x && x < R && 0 <= y && y < C;
}

int Bfs(Matrix& matrix, Pos src, Pos dst){
    int dist = 0;
    
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size()));
    queue<pair<Pos, int>> q; // Pos, distN
    
    q.push(make_pair(src, 0));
    visited[src.first][src.second] = true;
    
    while(!q.empty())
    {
        pair<Pos, int> cur = q.front(); q.pop();
        Pos curPos = cur.first;
        int curDist = cur.second;
        
        for(int i = 0; i < DIR; i++)
        {
            int nx = dx[i] + curPos.first;
            int ny = dy[i] + curPos.second;
            
            if(InRange(nx, ny) && !visited[nx][ny] && matrix[nx][ny] != 'X')
            {
                q.push(make_pair(make_pair(nx, ny), curDist + 1));
                visited[nx][ny] = true;
                
                if(make_pair(nx, ny) == dst)
                    return curDist + 1;
            }
        }
    }
    
    return -1;
}
// 격자 형태의 미로 탈출
// 통로들 중 "딱 한 칸"에는 레버 존재. -> 레버를 당겨야 문이 열림.
// 목표: 레버를 올린 상태로 출구에 도착하라
int solution(vector<string> maps) {
    int answer = 0;
    
    R = maps.size();
    C = maps[0].size();
    
    Matrix matrix(maps.size());
    Pos src, dst, lever;
    
    for(int i = 0; i < maps.size(); i++){
        const string& str = maps[i];
        for(int j = 0; j < str.length(); j++){
            
            switch(str[j]){
                case 'S' :
                    src = make_pair(i, j);
                    matrix[i].push_back('O');
                    break;
                case 'E' :
                    dst = make_pair(i, j);
                    matrix[i].push_back('O');
                    break;
                case 'L' :
                    lever = make_pair(i, j);
                    matrix[i].push_back('O');
                    break;
                default:
                    matrix[i].push_back(str[j]);
            }
        }   
    }
    
    int distToLever = Bfs(matrix, src, lever);
    if(distToLever == -1)
        return -1;
    
    int distToDst = Bfs(matrix, lever, dst);
    if(distToDst == -1)
        return -1;
    
    answer = distToLever + distToDst;
    
//     for(int i = 0; i < matrix.size(); i++){
//         for(int j = 0; j < matrix[i].size(); j++){
//             cout << matrix[i][j] << ' ';
//         }
//         cout << '\n';
//     }
    
//     cout << src.first << " " << src.second << '\n';
//     cout << dst.first << " " << dst.second << '\n';
//     cout << lever.first << " " << lever.second << '\n';
    
    return answer;
}