#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct vertexData
{
    vector<int> adjacentList;
    int subTreeN = 1;
};

vector<vertexData> tree;
vector<bool> visited;

int dfs(int idx){

    vector<int> curAdjacentList = tree[idx].adjacentList;
    for(int i = 0; i < curAdjacentList.size(); i++){
        int adjacentIdx = curAdjacentList[i];
        if(!visited[adjacentIdx]){
            visited[adjacentIdx] = true;
            tree[idx].subTreeN += dfs(adjacentIdx);
        }
    }

    return tree[idx].subTreeN;
}

int main() {
	fastio;
    int N, R, Q; cin >> N >> R >> Q;

    tree.resize(N+1);
    visited.resize(N+1);

    int v1, v2;
    for(int i = 0; i < N-1; i++){
        cin >> v1 >> v2;

        tree[v1].adjacentList.push_back(v2);
        tree[v2].adjacentList.push_back(v1);
    }

    visited[R] = true;
    tree[R].subTreeN = dfs(R);

    int query_v;
    for(int i = 0; i < Q; i++){
        cin >> query_v;
        cout << tree[query_v].subTreeN << '\n';
    }

}