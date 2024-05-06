#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int V, E;

vector<int> root;

struct edge_data
{
    int node1;
    int node2;
    int weight;

};

struct cmp
{
    bool operator()(const edge_data& a, const edge_data& b){
        return a.weight > b.weight;
    }
};

priority_queue<edge_data, vector<edge_data>, cmp> pq;

/* find(x): 재귀 이용 */
int find(int x) {
    // 루트 노드는 부모 노드 번호로 자기 자신을 가진다.
    if (root[x] == x) {
        return x;
    } else {
        // 각 노드의 부모 노드를 찾아 올라간다.
        return find(root[x]);
    }
}

/* union(x, y) */
void union_set(int x, int y){
    // 각 원소가 속한 트리의 루트 노드를 찾는다.
    x = find(x);
    y = find(y);

    if(x < y){
        root[y] = x;
    }
    else{
        root[x] = y;
    }
}

int kruscal_algorithm(){
    int edge_sum = 0;

    while(!pq.empty()){
        edge_data cur_edge = pq.top(); pq.pop();

        //cout << "ssssssssss "<< cur_edge.node1 << " " << cur_edge.node2 << " " << cur_edge.weight << '\n';
        
        if (find(cur_edge.node1) != find(cur_edge.node2)){
            //cout << "AADD" << '\n';
            union_set(cur_edge.node1, cur_edge.node2);
            edge_sum += cur_edge.weight;
        }

    }

    return edge_sum;
}

int main() {
	fastio;
    cin >> V >> E;
  
    root.resize(V+1);

    for(int i = 0; i < root.size(); i++){
        root[i] = i;
    }

    if(V == 1){
        cout << 0 << '\n';
        return 0;
    }

    int node1, node2, weight;
    for(int i = 0; i < E; i++){
        cin >> node1 >> node2 >> weight;
        pq.push({node1, node2, weight});
    }   

    // while(!pq.empty()){
    //     cout << pq.top().node1 << " " << pq.top().node2 << " " << pq.top().weight << '\n';
    //     pq.pop();
    // }
    
    int ans = E == 1 ? weight : kruscal_algorithm();

    cout << ans << '\n';

    return 0;
}