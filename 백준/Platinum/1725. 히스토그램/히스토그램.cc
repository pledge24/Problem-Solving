#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void)
{
    fastio;
    int N; cin >> N;
    vector<int> v1(N+1, 0);
    for(int i = 0; i < N; i++)
    {
        cin >> v1[i];
    }

    // Init
    stack<pair<int, int>> s;    // <idx, h>
    s.push(make_pair(0, v1[0]));
    int maxArea = v1[0];

    // Process
    for(int i = 1; i <= N; i++)
    {
        while(!s.empty() && (s.top().second > v1[i]))
        {
            pair<int, int> p = s.top(); s.pop();
            int idx = p.first;
            int h = p.second;
            int w = !s.empty() ? i - s.top().first - 1 : i;

            // printf("%d %d %d\n", idx, h, w);
            maxArea = max(maxArea, w*h);
        }

        s.push(make_pair(i, v1[i]));
    }

    cout << maxArea << '\n';

    return 0;
}