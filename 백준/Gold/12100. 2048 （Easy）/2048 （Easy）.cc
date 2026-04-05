#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;
using Matrix = vector<vector<int>>;
using Pos = pair<int, int>;

Matrix matrix;
int N; 
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};
int maxVal = 0;

// =========DEBUG FUNCTION=========
void PrintMatrix(Matrix& matrix)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool InRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

void Update(Matrix& cur, int moveDir)
{
    Matrix next(N, vector<int>(N));
    vector<vector<bool>> merged(N, vector<bool>(N));

    bool hMove = dy[moveDir] != 0;

    for(int i = 0; i < N; i++)
    {
        Pos pos = make_pair(0, 0);

        if(hMove)
        {
            pos.first += i;
        }
        else
        {
            pos.second += i;
        }

        // ====MONO====

        // 1. 끝 방향으로 일단 이동.
        
        while(InRange(pos.first + dx[moveDir], pos.second + dy[moveDir]))
        {
            pos.first += dx[moveDir];
            pos.second += dy[moveDir];
        }
    
        // 2. 반대로 오면서 하나씩 이동
        while(InRange(pos.first, pos.second))
        {
            if(cur[pos.first][pos.second] > 0)
            {
               // Move One Block.
               Pos blockPos = pos;
               int val = cur[pos.first][pos.second];
               do
               {
                int nx = blockPos.first + dx[moveDir];
                int ny = blockPos.second + dy[moveDir];
    
                if(!InRange(nx, ny) || next[nx][ny] > 0)
                    break;
    
                blockPos = make_pair(nx, ny);
               } while (true);
               
               // Try Merge.
               int mergeX = blockPos.first + dx[moveDir];
               int mergeY = blockPos.second + dy[moveDir];

               if(InRange(mergeX, mergeY) 
               && !merged[mergeX][mergeY] 
               && val == next[mergeX][mergeY]) 
                {
                    merged[mergeX][mergeY] = true;
                    next[mergeX][mergeY] *= 2;
                }
                else
                {
                    next[blockPos.first][blockPos.second] = val;
                }
                
    
            }
    
            // Move.
            pos.first -= dx[moveDir];
            pos.second -= dy[moveDir];
        }
    }

    cur.swap(next);
}

int Simulate(vector<int> path)
{
    Matrix cur = matrix;

    // Update.
    for(int elem : path)
    {
        Update(cur, elem);

        // PrintMatrix(cur);
    }

    // Find Max Block Value
    int val = 0;
    for(auto& row : cur)
    {
        val = max(val, *max_element(row.begin(), row.end()));
    }

    return val;
}

void DfsUtil(vector<int>& path)
{
    if(path.size() == 5)
    {
        int val = Simulate(path);
        maxVal = max(maxVal, val);

        return;
    }

    for(int i = 0; i < DIR; i++)
    {
        path.push_back(i);
        DfsUtil(path);
        path.pop_back();
    }
}

void Dfs()
{
    vector<int> path;
    DfsUtil(path);
}

int main(void)
{
    fastio;
    cin >> N;
    matrix.resize(N, vector<int>(N));

    // Fill Matrix
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Dfs
    Dfs();

    // Simulate({0, 1, 2, 3});

    cout << maxVal << '\n';

    return 0;
}