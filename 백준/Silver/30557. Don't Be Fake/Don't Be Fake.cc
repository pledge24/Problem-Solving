#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int MAX_SECOND = 86'400;
int main(void)
{
    fastio;
    vector<int> v1(MAX_SECOND+1, 0);
    int N; cin >> N;
    int maxPic = 0;
    for(int i = 0; i < N; i++)
    {
        int M; cin >> M;
        for(int j = 0; j < M; j++)
        {
            int L, R; cin >> L >> R;
            for(int k = L; k <= R; k++)
            {
                v1[k]++;
                maxPic = max(maxPic, v1[k]);
            }
        }
    }

    int cnt = 0;
    int streak = 0;
    int total = 0;
    for(int i = 0; i <= MAX_SECOND; i++)
    {
        if(v1[i] == maxPic)
            streak++;
        else
        {
            if(streak > 0)
            {
                total += streak;
                streak = 0;
                cnt++;
            }
        }
    }

    if(streak > 0)
    {
        streak = 0;
        cnt++;
    }

    cout << maxPic << '\n';
    cout << total << '\n';

    return 0;
}