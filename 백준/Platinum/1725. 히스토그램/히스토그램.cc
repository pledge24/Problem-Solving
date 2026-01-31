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
    stack<int> s; 
    int maxArea = 0;

    // Process
    for(int i = 0; i <= N; i++) {
        while(!s.empty() && v1[s.top()] > v1[i]) {
            int h = v1[s.top()]; s.pop();
            int w = !s.empty() ? i - s.top() - 1 : i;
            maxArea = max(maxArea, w * h);
        }
        s.push(i);
    }

    cout << maxArea << '\n';

    return 0;
}