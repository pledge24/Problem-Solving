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

struct cmp_asc
{
    bool operator()(const edge_data &a, const edge_data &b)
    {
        return a.weight < b.weight;
    }
};

struct cmp_desc
{
    bool operator()(const edge_data &a, const edge_data &b)
    {
        return a.weight > b.weight;
    }
};

int find(int x)
{
    if (x == root[x])
        return x;

    return root[x] = find(root[x]);
}

void union_set(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x < y)
        root[y] = x;
    else
        root[x] = y;

}

long long kruscal_algorithm(priority_queue<edge_data, vector<edge_data>, cmp_desc>& pq_desc, 
                            priority_queue<edge_data, vector<edge_data>, cmp_asc>& pq_asc, 
                            int N, 
                            string mode)
{
    long long edge_sum = 0;

    for(int i = 0; i <= N; i++){
        root[i] = i;
    }

    if (mode == "max") {
        while (!pq_desc.empty())
        {
            edge_data cur_edge = pq_desc.top();
            pq_desc.pop();

            int rootVtx1 = find(cur_edge.node1);
            int rootVtx2 = find(cur_edge.node2);

            if (rootVtx1 != rootVtx2)
            {
                union_set(cur_edge.node1, cur_edge.node2);
                if(cur_edge.weight == 0) edge_sum ++;
            }
        }
    } else {
        while (!pq_asc.empty())
        {
            edge_data cur_edge = pq_asc.top();
            pq_asc.pop();

            int rootVtx1 = find(cur_edge.node1);
            int rootVtx2 = find(cur_edge.node2);

            if (rootVtx1 != rootVtx2)
            {
                union_set(cur_edge.node1, cur_edge.node2);
                if(cur_edge.weight == 0) edge_sum ++;
            }
        }
    }

    //cout << edge_sum << '\n';

    return edge_sum;
}

int main()
{
    fastio;
    int N, M;
    cin >> N >> M;

    root.resize(N + 1);

    priority_queue<edge_data, vector<edge_data>, cmp_asc> pq_asc;
    priority_queue<edge_data, vector<edge_data>, cmp_desc> pq_desc;
    
    int vtx1, vtx2, w;
    for (int i = 0; i < M+1; i++)
    {
        cin >> vtx1 >> vtx2 >> w;

        pq_desc.push({vtx1, vtx2, w});
        pq_asc.push({vtx1, vtx2, w});
    }
 
    long long ans_min = kruscal_algorithm(pq_desc, pq_asc, N, "min");
    long long ans_max = kruscal_algorithm(pq_desc, pq_asc, N, "max");

    cout << ans_max * ans_max - ans_min * ans_min << '\n';

    return 0;
}