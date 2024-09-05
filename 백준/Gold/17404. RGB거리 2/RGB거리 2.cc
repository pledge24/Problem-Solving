#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 1001
#define RGBN 3
using namespace std;

vector<vector<int>> cost_RGB;

int main()
{
    fastio;
    int N;
    cin >> N;

    cost_RGB.resize(RGBN, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < RGBN; j++)
        {
            cin >> cost_RGB[j][i];
        }
    }

    vector<vector<int>> dp_R(RGBN, vector<int>(N));
    vector<vector<int>> dp_G(RGBN, vector<int>(N));
    vector<vector<int>> dp_B(RGBN, vector<int>(N));

    dp_R[0][0] = cost_RGB[0][0];
    dp_R[1][0] = MAXN;
    dp_R[2][0] = MAXN;
    dp_G[0][0] = MAXN;
    dp_G[1][0] = cost_RGB[1][0];
    dp_G[2][0] = MAXN;
    dp_B[0][0] = MAXN;
    dp_B[1][0] = MAXN;
    dp_B[2][0] = cost_RGB[2][0];

    for (int i = 1; i < N; i++)
    {

        for (int rgb = 0; rgb < RGBN; rgb++)
        {
            dp_R[rgb][i] = min(dp_R[(rgb + 1) % RGBN][i - 1], dp_R[(rgb + 2) % RGBN][i - 1]) + cost_RGB[rgb][i];
            dp_G[rgb][i] = min(dp_G[(rgb + 1) % RGBN][i - 1], dp_G[(rgb + 2) % RGBN][i - 1]) + cost_RGB[rgb][i];
            dp_B[rgb][i] = min(dp_B[(rgb + 1) % RGBN][i - 1], dp_B[(rgb + 2) % RGBN][i - 1]) + cost_RGB[rgb][i];
        }
    }

    int ans = min({
        dp_R[1][N-1], dp_R[2][N-1],
        dp_G[2][N-1], dp_G[0][N-1],
        dp_B[0][N-1], dp_B[1][N-1]
    });

    cout << ans << '\n';
}