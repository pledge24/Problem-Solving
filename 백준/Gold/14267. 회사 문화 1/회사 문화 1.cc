#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Tree = vector<vector<int>>;

void dfs(Tree& tree, vector<int>& scores, int cur){
    int curScore = scores[cur];

    for(int child : tree[cur]){
        scores[child] += curScore;
        dfs(tree, scores, child);
    }
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;
    
    Tree tree(N+1);
    for(int i = 1; i <= N; i++){
        int parent; cin >> parent;
        if(parent == -1)
            continue;

        tree[parent].push_back(i);
    }

    vector<int> scores(N+1);
    for(int i = 0; i < M; i++){
        int start, score; cin >> start >> score;
        scores[start] += score;
    }

    int root = 1;
    dfs(tree, scores, root);

    for(int i = 1; i <= N; i++){
        cout << scores[i] << ' ';
    }
    cout << '\n';

    return 0;
}