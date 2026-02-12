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
    int N; cin >> N;

    root.resize(N);
    for(int i = 0; i < N; i++){
        root[i] = i;
    }

    priority_queue<edge_data, vector<edge_data>, cmp> pq;
    long long totalWeight = 0;
    for(int i = 0; i < N; i++){
        string str; cin >> str;
        for(int j = 0; j < N; j++){

            if(str[j] == '0') continue;

            int w = str[j] >= 'a' ? str[j] - 'a' + 1 : str[j] - 'A' + 27;
            if(i != j && w > 0) pq.push({i, j, w});
            totalWeight += w;
        }
    }

    long long minWeight = kruscal_algorithm(pq, N);
    long long ans = minWeight == -1 ? -1 : totalWeight - minWeight;

    cout << ans << '\n';

    return 0;
}