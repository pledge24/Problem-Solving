#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> root;
map<int, bool> powerStation;

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

    if(powerStation[x]){
        root[y] = x;
    }
    else if(powerStation[y]){
        root[x] = y;
    }
    else{
        if (x < y) root[y] = x;
        else root[x] = y;
    }
    
}

long long kruscal_algorithm(priority_queue<edge_data, vector<edge_data>, cmp> pq, int N)
{
    long long edge_sum = 0;

    while (!pq.empty())
    {
        edge_data cur_edge = pq.top();
        pq.pop();

        int rootVtx1 = find(cur_edge.node1);
        int rootVtx2 = find(cur_edge.node2);

        if(powerStation[rootVtx1] && powerStation[rootVtx2]) continue;

        if (rootVtx1 != rootVtx2)
        {
            union_set(cur_edge.node1, cur_edge.node2);
            edge_sum += cur_edge.weight;
        }
    }

    return edge_sum;
}

int main() {
	fastio;
    int N, M, K; cin >> N >> M >> K;

    int ps;
    for(int i = 0; i < K; i++){
        cin >> ps;

        powerStation[ps] = true;
    }

    root.resize(N+1);
    for(int i = 1; i <= N; i++){
        root[i] = i;
    }

    priority_queue<edge_data, vector<edge_data>, cmp> pq;
    int vtx1, vtx2, w;
    for(int i = 0; i < M; i++){
        cin >> vtx1 >> vtx2 >> w;

        if(powerStation[vtx1] && powerStation[vtx2]) continue;

        pq.push({vtx1, vtx2, w});
    }

    long long ans = kruscal_algorithm(pq, N);
   
    cout << ans << '\n';

    return 0;
}