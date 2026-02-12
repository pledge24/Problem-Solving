#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int V, E;

vector<int> root;

struct edge_data
{
    int node1;
    int node2;
    double weight;
};

struct posData
{
    int x;
    int y;
};

struct cmp
{
    bool operator()(const edge_data &a, const edge_data &b)
    {
        return a.weight > b.weight;
    }
};

int find(int x)
{
    if (root[x] == x)
    {
        return x;
    }
    else
    {
        return find(root[x]);
    }
}

void union_set(int x, int y)
{

    x = find(x);
    y = find(y);

    if (x < y)
    {
        root[y] = x;
    }
    else
    {
        root[x] = y;
    }
}

double kruscal_algorithm(priority_queue<edge_data, vector<edge_data>, cmp> pq)
{
    double edge_sum = 0;

    while (!pq.empty())
    {
        edge_data cur_edge = pq.top();
        pq.pop();

        if (find(cur_edge.node1) != find(cur_edge.node2))
        {
            union_set(cur_edge.node1, cur_edge.node2);
            edge_sum += cur_edge.weight;
        }
    }

    return edge_sum;
}

int main()
{
    fastio;

    int N, M;
    cin >> N >> M;

    vector<posData> gods;
    gods.resize(N + 1);
    root.resize(N + 1);

    int x, y;
    for (int i = 1; i <= N; i++)
    {
        cin >> gods[i].x >> gods[i].y;
        root[i] = i;
    }

    priority_queue<edge_data, vector<edge_data>, cmp> pq;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            double dist = sqrt(pow(gods[i].x - gods[j].x, 2) + pow(gods[i].y - gods[j].y, 2));

            pq.push({i, j, dist});
        }
    }

    vector<bool> visited;
    visited.resize(N + 1);

    double ans = 0;

    int vtx1, vtx2;
    for (int i = 0; i < M; i++)
    {
        cin >> vtx1 >> vtx2;
        if (find(vtx1) != find(vtx2))
        {
            union_set(vtx1, vtx2);
        }
    }

    ans = kruscal_algorithm(pq);

    cout << fixed; cout.precision(2);
    cout << ans << '\n';
}