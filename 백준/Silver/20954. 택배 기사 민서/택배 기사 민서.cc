#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 3'000'000'000

using namespace std;
using int64 = long long;

int main(void)
{
    fastio;
    vector<int64> v1 = {0};

    for(int i = 0; i <= 64; i++)
    {
        int64 exp = i / 2;
        int64 num = 1 << exp;
        int64 curPos = i % 2 == 0 ? num : -num;

        v1.push_back(curPos);
    }    

    // for(auto elem : v1)
    // {
    //     cout << elem << '\n';
    // }

    int T; cin >> T;
    for(int i = 0; i < T; i++)
    {
        int64 x; cin >> x;
        int64 dist = 0;
        for(int j = 1; j < v1.size(); j++)
        {
            // Check InRange
            int64 prevPos = v1[j-1];
            int64 curPos = v1[j];

            if(min(prevPos, curPos) <= x && x <= max(prevPos, curPos))
            {
                cout << dist + abs(prevPos - x) << '\n';
                break;
            }

            dist += abs(prevPos - curPos);
        }
    }
 

    return 0;
}