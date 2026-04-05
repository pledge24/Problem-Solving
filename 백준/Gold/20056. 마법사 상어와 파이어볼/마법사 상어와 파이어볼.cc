#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 8

int N, M, K; 
int dx[DIR] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[DIR] = {0, 1, 1, 1, 0, -1, -1, -1};

struct FireBall
{
    int m = 0;
    int s = 0;
    int d = 0;    
};

using namespace std;
using Matrix = vector<vector<vector<FireBall>>>;
using Pos = pair<int, int>;

Matrix matrix;

// ======== DEBUG FUNCTION ============
void PrintMatrix(Matrix& matrix)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int m = 0;
            for(FireBall fb : matrix[i][j])
            {
                m += fb.m;
            }
            cout << m << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

// =======================================

void Update()
{
    // 1. Move
    {
        Matrix next(N, vector<vector<FireBall>>(N));

        // Collect All FireBall(안해도 되는데 코드상 깔끔함이 이유)
        queue<pair<vector<FireBall>, Pos>> q;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                vector<FireBall>& fireBalls = matrix[i][j];
                if(!fireBalls.empty())
                    q.push(make_pair(fireBalls, make_pair(i, j)));
            }
        }
        
        while(!q.empty())
        {
            auto [fireBalls, pos] = q.front(); q.pop();
            for(FireBall fireBall : fireBalls)
            {
                auto [m, s, d] = fireBall;

                int nx = ((pos.first + dx[d] * s) % N + N) % N;
                int ny = ((pos.second + dy[d] * s) % N + N) % N;
            
                next[nx][ny].push_back({m, s, d});
                // printf("%d %d %d '\n", m, s, d);
            }
        }

        matrix.swap(next);

        // PrintMatrix(matrix);
        
    }


    // 2. Merge & Split
    {
        Matrix next(N, vector<vector<FireBall>>(N));

        // Collect All FireBall(안해도 되는데 코드상 깔끔함이 이유)
        queue<pair<vector<FireBall>, Pos>> q;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(!matrix[i][j].empty())
                    q.push(make_pair(matrix[i][j], make_pair(i, j)));
            }
        }
        
        while(!q.empty())
        {
            auto [fireBalls, pos] = q.front(); q.pop();

            // If Only One...
            if(fireBalls.size() == 1)
            {
                next[pos.first][pos.second].push_back(fireBalls.back());
                continue;
            }

            // Merge
            int cnt[2] = {0, 0};
            FireBall mergedFb;
            for(FireBall& fb : fireBalls)
            {
                // Unpack Elem
                auto [m, s, d] = fb;

                mergedFb.m += m;
                mergedFb.s += s;

                cnt[d % 2]++;
            }
            
            // Process Split.
            int splitM = mergedFb.m / 5;
            int splitS = mergedFb.s / fireBalls.size();

            if(splitM == 0)
                continue;

            bool isMixedDir = (cnt[0] * cnt[1]) > 0;
            for(int i = 0 + isMixedDir; i < DIR; i+=2)
            {
                FireBall splittedFb = {splitM, splitS, i};
                next[pos.first][pos.second].push_back(splittedFb);
            }
        }

        matrix.swap(next);
    }
}

int main(void)
{
    fastio;
    cin >> N >> M >> K;

    matrix.assign(N, vector<vector<FireBall>>(N));
    for(int i = 0; i < M; i++)
    {
        int r, c, m, s, d;  // (r, c), 질량, 속력, 방향
        cin >> r >> c >> m >> s >> d;

        matrix[r-1][c-1].push_back(FireBall{m, s, d});
    }

    // Move K
    for(int i = 0; i < K; i++)
    {
        // PrintMatrix(matrix);
        Update();
        // PrintMatrix(matrix);
    }

    // Calc Sum M.
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(const FireBall& fb : matrix[i][j])
            {
                sum += fb.m;
            }
        }
    }

    cout << sum << '\n';

    return 0;
}