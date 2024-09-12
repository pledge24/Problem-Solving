#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 100'001
using namespace std;

int main()
{
    fastio;
    long long N, S;
    cin >> N >> S;

    vector<long long> v1;
    v1.resize(N);

    int start_idx = 0;
    long long sum = 0;

    int ans = MAXN;
    for (int end_idx = 0; end_idx < N; end_idx++)
    {
        cin >> v1[end_idx];

        sum += v1[end_idx];

        if (sum >= S)
        {
            while (sum - v1[start_idx] >= S && start_idx < end_idx)
            {
                sum -= v1[start_idx];
                start_idx++;
            }

            if(sum >= S)
                ans = end_idx - start_idx + 1 < ans ? end_idx - start_idx + 1 : ans;
            //cout << start_idx << " " << end_idx << '\n';
        }
    }


    if (ans == MAXN)
    {
        ans = 0;
    }

    cout << ans << '\n';
}