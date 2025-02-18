#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> parent; // size설정과 -1로 초기화가 되어있는 배열
vector<int> tree_rank; 

// union-find 알고리즘(경로 압축 + union by rank포함)
int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]); // 경로 압축
}

bool union_set(int u, int v){
    u = find(u); 
    v = find(v);

    // 두 집합이 같은 집합이라면 false반환.
    if(u == v) return false;

    // 두 집합의 깊이가 같을 경우, 첫번째 집합의 트리 깊이 랭크를 하나 올린다.
    // 이는 첫번째 대표 원소를 합친 집합의 대표 원소로 하겠다는 의미이다.
    if(tree_rank[u] == tree_rank[v]) tree_rank[u]++;

    // 두 집합의 깊이가 다를 경우, 깊이가 깊은 트리에 낮은 트리를 합친다.
    if(tree_rank[u] < tree_rank[v]) parent[v] = u;
    else parent[u] = v;

    return true;
}


int main() {
	fastio;

    
}

// bool union_set(int u, int v){
//     u = find(u); 
//     v = find(v);

//     // 두 집합이 같은 집합이라면 false반환.
//     if(u == v) return false;

//     // 두 집합의 깊이가 같을 경우, 첫번째 집합의 트리 깊이 랭크를 하나 올린다.
//     // 이는 첫번째 대표 원소를 합친 집합의 대표 원소로 하겠다는 의미이다.
//     if(parent[u] == parent[v]) parent[u]--;

//     // 두 집합의 깊이가 다를 경우, 깊이가 깊은 트리에 낮은 트리를 합친다.
//     if(parent[u] < parent[v]) parent[v] = u;
//     else parent[u] = v;

//     return true;
// }