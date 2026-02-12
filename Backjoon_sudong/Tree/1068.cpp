#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Tree = vector<vector<int>>;

int deleteNode;

void dfs(Tree& tree, int cur, int& cnt){
    if(cur == deleteNode)
        return;

    if(count_if(tree[cur].begin(), tree[cur].end(), [](int elem){return elem != deleteNode;}) == 0){
        cnt++;
        return;
    }

    for(int child : tree[cur]){
        dfs(tree, child, cnt);
    }

    return;
}

int main(void){
    fastio;
    int N; cin >> N;
    Tree tree(N);
    vector<int> parent(N);
    for(int i = 0; i < N; i++){
        cin >> parent[i];
        if(parent[i] == -1)
            continue;

        tree[parent[i]].push_back(i);
    }
    cin >> deleteNode;
    
    int root = 0;
    while(parent[root] != -1)
        root = parent[root];

    // cout << "root: " << root << '\n';

    int cnt = 0;
    dfs(tree, root, cnt);

    cout << cnt << '\n';

    return 0;
}