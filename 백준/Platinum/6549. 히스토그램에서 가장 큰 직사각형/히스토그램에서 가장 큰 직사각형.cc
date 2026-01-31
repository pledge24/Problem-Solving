#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;

int main(void)
{
    fastio;
    while(true)
    {
        int N; cin >> N;
        if(N == 0)
            break;

        vector<int64> v1(N+1, 0);
        for(int i = 0; i < N; i++)
        {
            cin >> v1[i];
        }

        // Init
        stack<int64> s; 
        int64 maxArea = 0;

        // Process
        for(int i = 0; i <= N; i++) {
            while(!s.empty() && v1[s.top()] > v1[i]) {
                int64 h = v1[s.top()]; s.pop();
                int64 w = !s.empty() ? i - s.top() - 1 : i;
                maxArea = max(maxArea, w * h);
            }
            s.push(i);
        }

        cout << maxArea << '\n';
    }    
    

    return 0;
}