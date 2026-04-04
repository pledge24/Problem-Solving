#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 1'000'000'007

using namespace std;
using int64 = long long;

int main(void)
{
    fastio;
    int N, M; cin >> N >> M;

    // Input A
    vector<int64> A;
    vector<vector<int64>> modMappings(7);
    for(int i = 0; i < N; i++)
    {
        int64 num; cin >> num;
        A.push_back(num);
        modMappings[num % 7].push_back(i);
    }

    // Input B.
    vector<int64> B;
    for(int i = 0; i < M; i++)
    {
        int64 num; cin >> num;
        B.push_back(num);
    }

    int64 leftN = N;
    int64 accu = 0;
    vector<bool> removed(N);
    for(int i = 0; i < M; i++)
    {
        int64 mod = (accu + B[i]) % 7;
        vector<int64>& modList = modMappings[(7 - mod) % 7];
        
        // Pass
        if(leftN == modList.size())
            continue;

        // Accu
        accu += B[i];
        
        // Remove
        if(!modList.empty())
        {
            for(int idx : modList)
            {
                removed[idx] = true;
            }

            leftN -= modList.size();
            modList.clear();
        }
        
    }

    cout << leftN << '\n';
    for(int i = 0; i < N; i++)
    {
        if(removed[i])
            continue;

        cout << (A[i] + accu) % DIV << ' ';
    }
    cout << '\n';

    return 0;
}