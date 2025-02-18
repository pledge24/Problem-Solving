#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int v, e;

vector<vector<pair<int, int>>> adj;

vector<int> parent;

// union-find 알고리즘(경로 압축 + union by rank포함)
int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_group(int u, int v){
    u = find(u); 
    v = find(v);

    if(u == v) return false;

    if(parent[u] == parent[v]) parent[u]--;

    if(parent[u] < parent[v]) parent[v] = u;
    else parent[u] = v;

    return true;
}

vector<tuple<int, int, int>> edge; // tuple<int, int, int> : {가중치, 정점 1, 정점 2}

// 시간복잡도 O(VlogV)
int kruskal(){
    int cnt = 0;
    int ans = 0;

    // init
    sort(edge.begin(), edge.end()); // 간선을 가중치가 짧은 순으로 정렬
    fill(parent.begin(), parent.end(), -1);   // 부모 정점 초기화

    for(int i = 0; i < e; i++){
        int vtx1, vtx2, weight;
        tie(weight, vtx1, vtx2) = edge[i];

        // 간선의 시작점과 끝점이 같은 집합이라면(사이클을 만듦) 넘어간다.
        if(!is_diff_group(vtx1, vtx2)) continue;

        cnt++;
        ans += weight;

        // v-1개의 간선을 모두 찾으면 미리 루프탈출
        if(cnt == v-1) break;
    }

    return ans;
}

int main() {
	fastio;

    
}