#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct Cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

int main(void)
{
    fastio;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;      // <Q, idx>
    priority_queue<pair<int, int>> pq_rev;

    int N, M; cin >> N >> M;
    vector<int> v1;
    for(int i = 0; i < N; i++)
    {
        int num; cin >> num;
        v1.push_back(num);
    }

    for(int i = 0; i < N; i++)
    {
        pq.push(make_pair(v1[i], i));
        pq_rev.push(make_pair(v1[i], i));
    }

    bool isReverse = false;
    vector<bool> visited(N);
    for(int i = 0; i < M; i++)
    {
        pair<int, int> p;
        int idx;
        while(true)
        {
            if(isReverse)
            {
                p = pq_rev.top();
                pq_rev.pop();
                // cout << "pq_rev: " << p.first << " " << p.second << '\n';
            }
            else
            {
                p = pq.top();
                pq.pop();
                // cout << "pq: " << p.first << " " << p.second << '\n';
            }
 
            idx = p.second;
            if(!visited[idx])
                break;

        }

        visited[idx] = true;
        cout << idx + 1 << '\n';

        if(p.first % 7 == 0)
            isReverse = !isReverse;
    }

    return 0;
}