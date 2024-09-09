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

struct cmp
{
    bool operator()(const edge_data& a, const edge_data& b){
        return a.weight > b.weight;
    }
};

int find(int x) {
    if (root[x] == x) {
        return x;
    } else {
        return find(root[x]);
    }
}

void union_set(int x, int y){

    x = find(x);
    y = find(y);

    if(x < y){
        root[y] = x;
    }
    else{
        root[x] = y;
    }
}

double kruscal_algorithm(priority_queue<edge_data, vector<edge_data>, cmp> pq){
    double edge_sum = 0;

    while(!pq.empty()){
        edge_data cur_edge = pq.top(); pq.pop();

        if (find(cur_edge.node1) != find(cur_edge.node2)){
            union_set(cur_edge.node1, cur_edge.node2);
            edge_sum += cur_edge.weight;
        }

    }

    return edge_sum;
}

int main() {
	fastio;
    int n; cin >> n;

    vector<pair<double, double>> stars;

    root.resize(n);
    for(int i = 0; i < root.size(); i++){
        root[i] = i;
    }

    double x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        stars.push_back({x, y});
    }

    priority_queue<edge_data, vector<edge_data>, cmp> pq;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            double dist = sqrt(pow((stars[i].first - stars[j].first),2) + pow((stars[i].second - stars[j].second),2));
            pq.push({i, j, dist});
        }
    }

    double ans = kruscal_algorithm(pq);

    cout << fixed; cout.precision(2);
    cout << ans << '\n';

    return 0;
}