#include <bits/stdc++.h>

#define DIR 4

using namespace std;
using Matrix = vector<vector<bool>>;
using Pos = pair<int, int>;

const int MAX_X = 50*2;
const int MAX_Y = 50*2;

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool InRange(int x, int y)
{
    return 1 <= x && x <= MAX_X && 1 <= y && y <= MAX_Y;
}

bool IsEdge(Matrix& matrix, Pos pos)
{
    int x = pos.first;
    int y = pos.second;
    
    int areas = matrix[x-1][y-1] + matrix[x-1][y] + matrix[x][y-1] + matrix[x][y];
    
    return 0 < areas && areas < 4;
}

int GetDistance(Matrix& matrix, Pos cur, Pos dst, set<Pos> s1)
{
    int dist = 0;
    
    // Init
    s1.insert(cur);
    dist++;
    // cout << cur.first << " " << cur.second << '\n';
    
    while(cur != dst)
    {
        for(int i = 0; i < DIR; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            Pos next = make_pair(nx, ny);
            
            if(InRange(nx, ny) && s1.find(next) == s1.end() && IsEdge(matrix, next))
            {
                // Update
                s1.insert(next);
                dist++;
                
                cur = next;
                // cout << cur.first << " " << cur.second << '\n';
                break;
            }
        }
    }
    
    return dist;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    // Init
    Matrix matrix(MAX_X+1, vector<bool>(MAX_Y+1));
    for(vector<int>& rec : rectangle)
    {
        int minX = rec[0]*2;
        int minY = rec[1]*2;
        int maxX = rec[2]*2;
        int maxY = rec[3]*2;
        
        for(int x = minX; x < maxX; x++)
        {
            for(int y = minY; y < maxY; y++)
            {
                matrix[x][y] = true;
            }
        }
    }
    
    // Process
    Pos src = make_pair(characterX*2, characterY*2);
    Pos dst = make_pair(itemX*2, itemY*2);
    int minDist = 100'000'000;
    for(int i = 0; i < DIR; i++)
    {
        int nx = src.first + dx[i];
        int ny = src.second + dy[i];
        Pos next = make_pair(nx, ny);
        
        if(InRange(nx, ny) && IsEdge(matrix, next))
        {
            set<Pos> s1 = {src};
            
            int dist = GetDistance(matrix, next, dst, s1);
            // cout << "dist: " << dist << '\n';
            
            minDist = min(minDist, dist);
        }
    }
    
    answer = minDist / 2;
    
    return answer;
}