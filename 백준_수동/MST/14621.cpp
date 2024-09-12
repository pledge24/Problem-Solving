#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> root;

struct edge_data
{
    int node1;
    int node2;
    int weight;
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
    if (x == root[x]) return x;

    return root[x] = find(root[x]);
}

void union_set(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x < y) root[y] = x;
    else root[x] = y;
}

long long kruscal_algorithm(priority_queue<edge_data, vector<edge_data>, cmp> pq, int N)
{
    long long edge_sum = 0;
    int cnt = 0;

    while (!pq.empty())
    {
        edge_data cur_edge = pq.top();
        pq.pop();

        if (find(cur_edge.node1) != find(cur_edge.node2))
        {
            union_set(cur_edge.node1, cur_edge.node2);
            edge_sum += cur_edge.weight;
            cnt++;
        }
    }

    if(cnt != N-1) edge_sum = -1;

    return edge_sum;
}

int main() {
	fastio;
    int N, M; cin >> N >> M;

    root.resize(N+1);
    for(int i = 1; i <= N; i++){
        root[i] = i;
    }

    priority_queue<edge_data, vector<edge_data>, cmp> pq;
    int vtx1, vtx2, w;
    long long totalWeight = 0;
    for(int i = 0; i < M; i++){
        cin >> vtx1 >> vtx2 >> w;
        pq.push({vtx1, vtx2, w});
        totalWeight += w;
    }

    long long minWeight = kruscal_algorithm(pq, N);
    long long ans = minWeight == -1 ? -1 : totalWeight - minWeight;

    cout << ans << '\n';

    return 0;
}