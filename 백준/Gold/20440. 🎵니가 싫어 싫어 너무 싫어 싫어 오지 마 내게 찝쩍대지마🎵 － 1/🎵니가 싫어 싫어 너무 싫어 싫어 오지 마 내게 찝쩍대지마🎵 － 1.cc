#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void)
{
    fastio;
    int N; cin >> N;
    vector<pair<int, int>> orgin;
    vector<int> v1;
    for(int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;
        orgin.push_back(make_pair(s, e));
        v1.push_back(s);
        v1.push_back(e);
    }

    // Erase-Unique Pattern
    std::sort(v1.begin(), v1.end());
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
    
    vector<int> diff(v1.size());

    for(auto& p : orgin)
    {
        auto& [s, e] = p;
        int startIdx = std::lower_bound(v1.begin(), v1.end(), s) - v1.begin();
        int endIdx = std::lower_bound(v1.begin(), v1.end(), e) - v1.begin();

        diff[startIdx]++;
        diff[endIdx]--;
    }

    int curCnt = 0;
    int maxCnt = 0;
    pair<int, int> maxRng = make_pair(0, 0);
    int s = 0;
    for(int i = 0; i < diff.size(); i++)
    {
        if(diff[i] == 0)
            continue;

        if(curCnt > maxCnt)
        {
            maxCnt = curCnt;
            maxRng = make_pair(v1[s], v1[i]);
        }

        curCnt += diff[i];
        s = i;
    }

    cout << maxCnt << '\n';
    cout << maxRng.first << " " << maxRng.second << '\n';

    return 0;
}