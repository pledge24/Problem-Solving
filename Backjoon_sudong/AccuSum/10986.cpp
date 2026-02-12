#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;

int main(void)
{
    fastio;

    int N, M; cin >> N >> M;
    vector<int64> accu(N);
    map<int64, int64> m1;
    int64 totalCnt = 0;
    for(int i = 0; i < N; i++)
    {
        int64 num; cin >> num;
        if(i == 0)
            accu[i] = num;
        else
            accu[i] = accu[i-1] + num;

        int64 remain = accu[i] % M;
        totalCnt += m1[remain];
        if(remain == 0)
            totalCnt++;

        m1[remain]++;

        // cout << accu[i] << ' ';
    }
    // cout << '\n';

    cout << totalCnt << '\n';

    return 0;
}