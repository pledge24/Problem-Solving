#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> parent, node_rank;

int find_root(int x) {
    //x가 root이면, 그대로 반환한다.
    if (x == parent[x]) return x;
    //x가 자식 노드일 경우, 부모 노드에 대해 재귀실행한다.
    //***이 때, parent[x]를 최종적으로 찾을 root 노드로 갱신한다.***
    return parent[x] = find_root(parent[x]);
}

bool union_root(int x, int y) {
    //x, y 정점의 최상위 정점을 각각 찾는다. (속한 트리의 루트 노드를 찾는다.)
    x = find_root(x);
    y = find_root(y);
 
    if(x == y) return false;
  
    //서로 다른 트리에 속한다면, 한 쪽의 트리를 다른 쪽에 붙인다.
    //***항상 높이가 낮은 트리를 높이가 높은 트리에 붙인다.***
    if (node_rank[x] < node_rank[y]) parent[x] = y;
    else if(node_rank[x] > node_rank[y]) parent[y] = x;
    else {
        parent[x] = y;
        node_rank[x]++;
    }

    return true;
}

int main() {
	fastio;
    int n, m; cin >> n >> m;

    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);

    node_rank.resize(n);

    int v1, v2;
    int cycleIdx = -1;
    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;

        if(cycleIdx != -1) continue;

        bool haveCycle = !union_root(v1, v2);

        if(haveCycle){
            cycleIdx = i + 1;
        }

    }

    if(cycleIdx == -1) cout << "0" << '\n';  
    else cout << cycleIdx << '\n';  

}