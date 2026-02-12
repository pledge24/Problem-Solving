#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> v1;

bool finds = false;

void dfs(int N)
{

    if (!finds)
    {
        if (N == 1)
        {
            finds = true;
            cout << v1.size() << '\n';
            for (int elem : v1)
            {
                cout << elem << ' ';
            }
            cout << '\n';
            return;
        }

        if (N % 3 == 0)
        {
            v1.push_back(N / 3);
            dfs(N / 3);
            v1.pop_back();
        }
        if (N % 2 == 0)
        {
            v1.push_back(N / 2);
            dfs(N / 2);
            v1.pop_back();
        }
        v1.push_back(N - 1);
        dfs(N - 1);
        v1.pop_back();
    }

    return;
}

struct hop
{
    int n;
    int size;
    int next;
};

void bfs(int N){
    queue<hop> q;

    q.push({N, 0, -1});
    while(!q.empty()){
        hop h = q.front();
        q.pop();

        int cur_n = h.n;
        int cur_size = h.size;
        int cur_next = h.next;

        if(cur_n == 1) break;

        if (cur_n % 3 == 0){
            q.push({cur_n/3, cur_size+1, cur_n});
        }

        if (N % 2 == 0){
            q.push({cur_n/2, cur_size+1, cur_n});
        }

        q.push({cur_n-1, cur_size+1, cur_n});
    }

    return;
}

int main()
{
    fastio;
    int N;
    cin >> N;

    v1.push_back(N);
    //dfs(N);
    bfs(N);

}