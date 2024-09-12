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

int kruscal_algorithm(priority_queue<edge_data, vector<edge_data>, cmp> pq, vector<bool> isOverMaleList, int N)
{
    int edge_sum = 0;
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

    vector<bool> isOverMaleList;
    isOverMaleList.resize(N+1);
    root.resize(N+1);

    char gender;
    for(int i = 1; i <= N; i++){
        cin >> gender;
        isOverMaleList[i] = gender == 'M' ? true : false;
        root[i] = i;
    }

    priority_queue<edge_data, vector<edge_data>, cmp> pq;
    int vtx1, vtx2, w;
    for(int i = 0; i < M; i++){
        cin >> vtx1 >> vtx2 >> w;
        if(isOverMaleList[vtx1] == isOverMaleList[vtx2]) continue;
        pq.push({vtx1, vtx2, w});
    }

    int ans = kruscal_algorithm(pq, isOverMaleList, N);

    cout << ans << '\n';

    return 0;
}